//
//  stopClock.cpp
//  DataToyPrototype002
//
//  Created by PengCheng on 3/3/13.
//
//

#include "stopClock.h"

stopClork::stopClork(){


}
//-------------------------------------------------------
void stopClork::setup(int &_year){
    img01.loadImage("images/c031.png");
    img02.loadImage("images/c032.png");
    img03.loadImage("images/c033.png");
    img04.loadImage("images/c034.png");
    img05.loadImage("images/c035.png");
    startTime = ofGetElapsedTimef();
    bClorkPressed = false;
    bTimeChange = false;
    bBallStart = false;
    prePos.set(0, 0);
    offSet.set(0, 0);
    angle = 0;
    preAngle = 0;
    mylevel = 0;
    alpha=255;
    year = &_year;
     
}
//-------------------------------------------------------
void stopClork::update(float a){

    alpha = a;
    
    if (bClorkPressed) {

    }
    
    
    

}
//-------------------------------------------------------
void stopClork::draw(){
    
   
    ofPushStyle();
    ofSetColor(255, 255, 255,alpha);
    img05.draw(522+370+offSet.x,282+111+offSet.y);
    img04.draw(522,282);
    ofPushMatrix();
    ofTranslate(522+28+170,326+28+171);
    ofRotateZ(angle);
    ofTranslate(-170,-171);
    if (alpha != 30) {
        img03.draw(0,0);
    }
    ofPopMatrix();
    img01.draw(522+27,326+27);
    ofPushMatrix();
    ofTranslate(522+182+17,282+160+80);
    float a;
    float speed;
    float time = ofGetElapsedTimef()-startTime;
    speed = 0.2;
    a = RAD_TO_DEG*(time*speed);
    if (a>359){
        startTime = ofGetElapsedTimef();
        bClorkPressed = false;
    }
    if(bClorkPressed)ofRotateZ(a);
    ofTranslate(-17,-80);
    img02.draw(0,0);
    ofPopMatrix();
    ofPopStyle();
    
}
//-------------------------------------------------------
void stopClork::touchDown(int id, int number, float x, float y){
    
    
    if (id == 0) {
        ofRectangle rect;
        rect.set(700, 411, 200, 200);
      
        if (rect.inside(x, y)) {
            prePos.set(x, y);
            bTimeChange = true;
            preAngle = angle;
        }
        
          
        rect.set(522+370,282+111, 73, 68);
        if (rect.inside(x, y)) {
            offSet.set(-15, 15);
        }
    }
   

    
}
//-------------------------------------------------------
void stopClork::touchMove(int id, int number, float x, float y){
    
    if (id==0) {
        
        ofRectangle rect;
        rect.set(522+370,282+111, 73, 68);
        if (rect.inside(x, y)) {
            offSet.set(-15, 15);
        }else{
            offSet.set(0, 0);
        }
        
        if (bTimeChange) {
            
            float     dis;
            float     a;
            ofPoint   pos;
            pos.set(x, y);
            
            dis = pos.distance(prePos);
            dis = ofClamp(dis, 0, 200);
            a = ofMap(dis, 0, 200, 0, 40);
            if (pos.y > prePos.y) {
                angle += a;
                if (angle - preAngle > 30) {
                    angle = preAngle + 30;
                }
            }
            if (pos.y<prePos.y) {
                angle -= a;
                if (angle - preAngle < -30) {
                    angle = preAngle - 30;
                }
            }
            
            prePos.set(x, y);
            }
        }
    
    
    
    
}
//-------------------------------------------------------
void stopClork::touchUp(int id, int number, float x, float y){

   
        ofRectangle rect;
        rect.set(522+370,282+111, 73, 68);
    
        if (rect.inside(x, y)) {
            offSet.set(0, 0);
            bClorkPressed = true;
            startTime = ofGetElapsedTimef();
        }
    
    if (bTimeChange) {
        
        if (-15<angle && angle<=15) {
            angle = 0;
            *year = 2005;
        }else if(-30<angle&& angle<=-15){
            angle = -30;
            *year = 2010;
        }else if(15<angle&& angle<30){
            angle = 30;
            *year = 2000;
        }
        if (angle>=30) {
            angle = 30;
            *year = 2000;
        }else if(angle<=-30){
            angle = -30;
            *year = 2010;
        }
        
        bTimeChange = false;
    }
       
    
    
    
    
    
}

//----------------------------------------------
