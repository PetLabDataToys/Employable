//
//  balls.cpp
//  DataToyBeta02
//
//  Created by PengCheng on 3/7/13.
//
//

#include "balls.h"

void CustomParticle::setup(string &name, int &year){
  
    cityName = &name;
    cityYear = &year;
    Pop_Per_Ball = 100000;

    world.init();
	world.setGravity(0, 15);
	world.createBounds();
	world.setFPS(30.0);
    world.registerGrabbing();
    world.setIterations(1, 1);
    

    preYear = *cityYear;
    preName = *cityName;
    
    
}

void balls::update(){
    
    world.update();
    
    if (*cityName!=preName || *cityYear != preYear) {
        
        int city = dBase.getCityId(*cityName);
        int time = dBase.getYearId(*cityYear);
        

        imm_all = dBase.getNumVal(MPI_NUM_IMMIGRANTS,city,time);
        Native_all  = dBase.getNumVal(MPI_NUM_POPULATION, city, time) - imm_all;
        imm_num_No = imm_all* dBase.getPctVal(MPI_PCT_DEGREE_IMMIGRANTS_NO, city,time);
        native_num_No = Native_all*dBase.getPctVal(MPI_PCT_DEGREE_NATIVE_NO, city,time);
        
        imm_num_HS = imm_all* dBase.getPctVal(MPI_PCT_DEGREE_IMMIGRANTS_HIGHSCHOOL, city,time);
        native_num_HS = Native_all*dBase.getPctVal(MPI_PCT_DEGREE_NATIVE_HIGHSCHOOL, city,time);
        
        imm_num_BA = imm_all* dBase.getPctVal(MPI_PCT_DEGREE_IMMIGRANTS_BA, city,time);
        native_num_BA = Native_all*dBase.getPctVal(MPI_PCT_DEGREE_NATIVE_BA, city,time);
        
        no_balls = (imm_num_No+native_num_No)/Pop_Per_Ball;
        hs_balls = (imm_num_HS + native_num_HS )/Pop_Per_Ball;
        ba_balls = (imm_num_BA + native_num_BA) /Pop_Per_Ball;
        
        for (int i =0; i<no_balls; i++) {
                cout<<"2"<<endl;
            CustomParticle p;
            p.setPhysics(3.0, 0.3, 0.1);
            p.setup(world.getWorld(), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 44);
            p.setVelocity(0, 0);
//            p.education = 0;
            myballs.push_back(p);
        }
        
        for (int i =0; i<hs_balls; i++) {
                cout<<"3"<<endl;
            CustomParticle p;
            p.setPhysics(3.0, 0.3, 0.1);
            p.setup(world.getWorld(), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 63);
            p.setVelocity(0, 0);
//            p.education = 1;
            myballs.push_back(p);
        }
        
        for (int i =0; i<ba_balls; i++) {
                cout<<"4"<<endl;
            CustomParticle p;
            p.setPhysics(3.0, 0.3, 0.1);
            p.setup(world.getWorld(), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 93);
            p.setVelocity(0, 0);
//            p.education = 2;
            myballs.push_back(p);
        }

        preName = *cityName;
        preYear = *cityYear;
    }
    
    
    
    
    
}


void balls::draw(){
    
    for (int i =0 ; i<myballs.size(); i++) {
        ofSetColor(255, 255, 0);
        myballs[i].draw();
       
    }

}