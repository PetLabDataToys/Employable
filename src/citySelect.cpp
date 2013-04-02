//
//  citySelect.cpp
//  DataToyBeta02
//
//  Created by PengCheng on 3/6/13.
//
//

#include "citySelect.h"

citySelect::citySelect(){
    
    
    height = 0;
    width = 0;
    speed = 0.03f;
    pct = 0;
    W = 220;
    H = 768;
    space = 10;
    pos.set(0, 0);
    prePos.set(0, 0);
    offSet = 25;
    boxPos.set(220, 0);
    temPos.set(0, 0);
    bDone = false;
}

//--------------------------------------------------------------
void citySelect::setup(string &name,int &year,bool &select, bool & bBalls){
    bBall = &bBalls;
    bSelect = &select;
    cityName =&name;
    cityYear =&year;
    font.loadFont("fonts/Futura-CondensedMedium.ttf",20);
    dBase.loadCities("cities.csv");
    dBase.loadYear(2000, "2000.csv");
    dBase.loadYear(2005, "2005.csv");
    dBase.loadYear(2010, "2010.csv");
    pos.set(0, 0);
    for (int i=0; i<25; i++) {
        ofColor c;
        c.set(255, 255, 255,100);
        colors.push_back(c);
        ofRectangle temp;
        temp.set(0,space*i+35*i,W,35);
        rects.push_back(temp);
    }
    
    
   }

//--------------------------------------------------------------
void citySelect::update(){

    for (int i=0; i<25; i++) {
        
        float temSize;
        float temShape;
        float temAlpha;
        temSize = ofMap(dBase.getPctVal(MPI_PCT_POPULATION_SHARE, i , dBase.getYearId(*cityYear)), dBase.getMinPctVal(MPI_PCT_POPULATION_SHARE,-1,dBase.getYearId(*cityYear)), dBase.getMaxPctVal(MPI_PCT_POPULATION_SHARE,-1,dBase.getYearId(*cityYear)), 8, 30);
        
        temShape = ofMap(dBase.getPctVal(MPI_PCT_EMPLOYED_SHARE, i,dBase.getYearId(*cityYear)), dBase.getMinPctVal(MPI_PCT_EMPLOYED_SHARE,-1,dBase.getYearId(*cityYear)), dBase.getMaxPctVal(MPI_PCT_EMPLOYED_SHARE,-1,dBase.getYearId(*cityYear)), 3, 12);
        
        if (*cityYear == 2010) {
            int k1 = dBase.getNumVal(MPI_NUM_IMMIGRANTS, i, dBase.getYearId(2010))* dBase.getPctVal(MPI_PCT_RECENT_ARRIVALS,dBase.getCityId(*cityName), dBase.getYearId(2010));
            
            int k2 =   dBase.getNumVal(MPI_NUM_IMMIGRANTS, i, dBase.getYearId(2005))* dBase.getPctVal(MPI_PCT_RECENT_ARRIVALS, i, dBase.getYearId(2005));
            
            int k =  k1 - k2;
            
            if (k>0) {
                temAlpha = 255;
            }else{
                temAlpha = 128;
            }
        }else if (*cityYear == 2005){
            
            int k1 = dBase.getNumVal(MPI_NUM_IMMIGRANTS, i, dBase.getYearId(2005))* dBase.getPctVal(MPI_PCT_RECENT_ARRIVALS,i, dBase.getYearId(2005));
            
            int k2 =   dBase.getNumVal(MPI_NUM_IMMIGRANTS, i, dBase.getYearId(2000))* dBase.getPctVal(MPI_PCT_RECENT_ARRIVALS,i, dBase.getYearId(2000));
            
            int k =  k1 - k2;
            
            if (k>0) {
                temAlpha = 255;
            }else{
                temAlpha = 128;
            }
        }else{
            
            temAlpha = 255;
            
        }
        
        shape.push_back(temShape);
        size.push_back(temSize);
        alpha.push_back(temAlpha);
    }

  
    pct += speed;
    if (pct>1) {
        pct = 1;
    }
    width = (1-pct) * width + pct * W;
    height = (1-pct) * height + pct * H;
    
    
}

//--------------------------------------------------------------
void citySelect::draw(){
    
    ofSetColor(51, 60, 65);
    
    ofPushMatrix();
    
        ofSetColor(51, 60, 64);
        ofRect(0, 0, width, height);
        ofTranslate(0, offSet);
        for (int i =0; i<25; i++) {
            ofSetColor(colors[i]);
            ofRect(rects[i]);
        }
    
        for (int i = 0; i<25; i++) {
            ofRectangle rect;
            rect = font.getStringBoundingBox(dBase.getCity(i), 0, 0);
            ofSetColor(255, 255, 255);
            font.drawString(dBase.getCity(i),30, space*i+35*i+28);
          
            ofPushStyle();
            ofSetCircleResolution(int(shape[i]));
            ofSetColor(237, 0, 140,int(alpha[i]));
            ofCircle(170, space*i+35*i+18, int(size[i]));
            ofPopStyle();
        }
    
        
    ofPopMatrix();
    

    
}

//--------------------------------------------------------------
void citySelect::mouseDown(int id, int number, float x, float y){

    if (id ==0) {
        pos.set(x, y);
        for (int i=0; i<25; i++) {
            ofRectangle tempRect;
            tempRect.set(rects[i].getPosition().x,rects[i].getPosition().y + offSet, rects[i].getWidth(), rects[i].getHeight());
            if(tempRect.inside(x, y)){
                colors[i].set(255, 255, 255,50);
            }else{
                colors[i].set(255, 255, 255,0);
            }
        }
        
        prePos = pos;
        prePos1 = pos;
    }
    
}

//--------------------------------------------------------------
void citySelect::mouseMove(int id, int number, float x, float y){
    
    if (id ==0) {
        pos.set(x, y);

        float diff;
        diff = pos.y - prePos.y;
        offSet += diff;
        
        if (offSet< -(space*8+35*8+14)) {
            offSet= -(space*8+35*8+14);
        }else if(offSet>28){
            offSet=28;
        }
        
        for (int i=0; i<25; i++) {
            ofRectangle tempRect;
            tempRect.set(rects[i].getPosition().x, rects[i].getPosition().y + offSet, rects[i].getWidth(), rects[i].getHeight());
            if(tempRect.inside(x, y)){
                colors[i].set(255, 255, 255,50);
            }else{
                colors[i].set(255, 255, 255,0);
            }
        }
        prePos = pos;
    }
}

//--------------------------------------------------------------
void citySelect::mouseUp(int id, int number, float x, float y){
   
    if (id == 0) {
    
        for (int i=0; i<25; i++) {
            colors[i].set(255, 255, 255,0);
            ofRectangle tempRect;
            tempRect.set(rects[i].getPosition().x,rects[i].getPosition().y + offSet, rects[i].getWidth(), rects[i].getHeight());
            if(tempRect.inside(x, y) && prePos1.y == pos.y){
                colors[i].set(255, 255, 255,0);
                *cityName = dBase.getCity(i);
                *bSelect = false;
                *bBall = true;
                bDone = true;
            }
            
        }
    }

}