//
//  cities.cpp
//  DataToyPrototype002
//
//  Created by PengCheng on 3/2/13.
//
//

#include "cities.h"

// comparison routine for sort...
bool comparisonFunction(  particle * a, particle * b ) {
	return a->pos.x < b->pos.x;
}

cities::cities(){
    

}
//-------------------------------
void cities::setup(vector<particle> particles,int &myCase, string &name,int &year, dataBall & _dataBall){
    
   
    myYear = & year;
    level = &myCase;
    myName = &name;
    dBase.loadCities( "cities.csv");
    dBase.loadYear(2000, "2000.csv");
    dBase.loadYear(2010, "2010.csv");
    dBase.loadYear(2005, "2005.csv");
    
    for (int i =0; i<5; i++) {
        icons[i].loadImage("images/icon0" + ofToString(i+1)+".png");
    }
    
    
	for (int i = 0; i < 25; i++){
		citiesParticle * p = new citiesParticle();
		myParticles.push_back(p);
		myParticles[i]->pos.set(particles[i].pos);
		myParticles[i]->vel.set(0,0);
        myParticles[i]->img = &icons[int(ofRandom(0,4))];
        myParticles[i]->name = dBase.getCity(i);
        myParticles[i]->size = ofMap(dBase.getPctVal(MPI_PCT_POPULATION_SHARE, i, dBase.getYearId(*myYear)), dBase.getMinPctVal(MPI_PCT_POPULATION_SHARE,-1,dBase.getYearId(*myYear)), dBase.getMaxPctVal(MPI_PCT_POPULATION_SHARE,-1,dBase.getYearId(*myYear)), 20, 70);
        
        myParticles[i]->CR = ofMap(dBase.getPctVal(MPI_PCT_EMPLOYED_SHARE, i,dBase.getYearId(*myYear)), dBase.getMinPctVal(MPI_PCT_EMPLOYED_SHARE,-1,dBase.getYearId(*myYear)), dBase.getMaxPctVal(MPI_PCT_EMPLOYED_SHARE,-1,dBase.getYearId(*myYear)), 3, 15);
        
        
        int k1 = dBase.getNumVal(MPI_NUM_IMMIGRANTS, i, dBase.getYearId(2010))* dBase.getPctVal(MPI_PCT_RECENT_ARRIVALS,i, dBase.getYearId(2010));
        
        int k2 =  dBase.getNumVal(MPI_NUM_IMMIGRANTS, i, dBase.getYearId(2005))* dBase.getPctVal(MPI_PCT_RECENT_ARRIVALS,i, dBase.getYearId(2005));

        
        int k =  k1 - k2;
        
        if (k>0) {
            myParticles[i]->b = 234.6;
            myParticles[i]->s = 79.5;
            myParticles[i]->a = 255;
        }else{
            
            myParticles[i]->b = 234.6;
            myParticles[i]->s = 79.5/3*2;
            myParticles[i]->a = 100;
        }
        
    }
    
    touchPos.set(-10, -10);
  
    myBall =& _dataBall;
    
    bDestry = false;
}
//-------------------------------
void cities::update(){
    
    if(*level ==1){
        sort( myParticles.begin(), myParticles.end(), comparisonFunction );
        
        
        for (int i = 0; i < myParticles.size(); i++){
            myParticles[i]->resetForce();
        }
        
        for (int i = 0; i < myParticles.size(); i++){
            for (int j = i-1; j >= 0; j--){
                if ( fabs(myParticles[j]->pos.x - myParticles[i]->pos.x) >	120) break;
                myParticles[i]->addRepulsionForce( *myParticles[j],120,1.1f);
            }
        }
        
        
        for (int i = 0; i < myParticles.size(); i++){
            myParticles[i]->addAttractionForce( ofGetWidth()/2,ofGetHeight()/2,1500,0.05);
            myParticles[i]->addRepulsionForce(touchPos.x, touchPos.y, 100, 3);
            myParticles[i]->addDampingForce();
            myParticles[i]->update();
        }

    }
    
       
}
//-------------------------------
void cities::draw(){
    
    if (*level == 1) {
        for (int i = 0; i < myParticles.size(); i++){
            myParticles[i]->draw();
        }
    }
    
}

//-------------------------------
void cities::touchDown(int id, int number, float x, float y){
 
}
//-------------------------------
void cities::touchMove(int id, int number, float x, float y){

    if (id == 0) {
        touchPos.x = x;
        touchPos.y = y;
    }
}
//-------------------------------
void cities::touchUp(int id, int number, float x, float y){
    
   
        
        if (id == 0) {
            
            for (int i=0; i<25; i++) {
                float dis;
                ofPoint t;
                t.x = x;
                t.y = y;
                dis = myParticles[i]->pos.distance(t);
                if (dis<myParticles[i]->size) {
                    bDestry = true;
                    
                    *myName = myParticles[i]->name;
                    
                    myBall->All_Jobs = dBase.getNumVal(MPI_NUM_EMPLOYED, dBase.getCityId(*myName),dBase.getYearId(*myYear));
              
                    myBall->IMM_Jobs = dBase.getNumVal(MPI_NUM_EMPLOYED_IMMIGRANTS, dBase.getCityId(*myName),dBase.getYearId(*myYear));
                    myBall->NATIVE_Jobs = dBase.getNumVal(MPI_NUM_EMPLOYED_NATIVE, dBase.getCityId(*myName),dBase.getYearId(*myYear));
                    myBall->IMM_pctNo = dBase.getPctVal(MPI_PCT_DEGREE_IMMIGRANTS_NO, dBase.getCityId(*myName),dBase.getYearId(*myYear));
                    myBall->IMM_pctHS = dBase.getPctVal(MPI_PCT_DEGREE_IMMIGRANTS_HIGHSCHOOL, dBase.getCityId(*myName),dBase.getYearId(*myYear));
                    myBall->IMM_pctBA = dBase.getPctVal(MPI_PCT_DEGREE_IMMIGRANTS_BA, dBase.getCityId(*myName),dBase.getYearId(*myYear));
                    myBall->NATIVE_pctNo = dBase.getPctVal(MPI_PCT_DEGREE_NATIVE_NO, dBase.getCityId(*myName),dBase.getYearId(*myYear));
                    myBall->NATIVE_pctHS = dBase.getPctVal(MPI_PCT_DEGREE_NATIVE_HIGHSCHOOL, dBase.getCityId(*myName),dBase.getYearId(*myYear));
                    myBall->NATIVE_pctBA = dBase.getPctVal(MPI_PCT_DEGREE_NATIVE_BA, dBase.getCityId(*myName),dBase.getYearId(*myYear));
                    
                    *level = 2;
                    
                   
                }
            }
        }

    
    
}