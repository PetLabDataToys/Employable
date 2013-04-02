//
//  dataBall.cpp
//  DataToyPrototype002
//
//  Created by PengCheng on 3/4/13.
//
//

#include "dataBall.h"


void dataBall::setup(){
    for (int i =0; i<13; i++) {
        icons[i].loadImage("images/icon0" + ofToString(i+1)+".png");
    }
    
    
    All_Jobs =0;
    pre_All_Jobs = 0;
    IMM_Jobs =0;
    NATIVE_Jobs=0;
    IMM_pctNo=0;
    IMM_pctHS=0;
    IMM_pctBA=0;
    NATIVE_pctNo=0;
    NATIVE_pctHS=0;
    NATIVE_pctBA=0;
     IMM_Pop_No =0;
     IMM_Pop_HS=0;
     IMM_Pop_BA=0;
     NATIVE_Pop_No=0;
     NATIVE_Pop_HS=0;
     NATIVE_Pop_BA=0;
     IMM_Number_NO=0;
     IMM_Number_HS=0;
     IMM_Number_BA=0;
     NATIVE_Number_NO=0 ;
     NATIVE_Number_HS=0 ;
     NATIVE_Number_BA=0 ;
    startTime = ofGetElapsedTimeMillis();
    startTime1 = ofGetElapsedTimeMillis();
    world.init();
	world.setGravity(0, 15);
	world.createBounds();
	world.setFPS(30.0);
    world.registerGrabbing();
    world.setIterations(1, 1);
  //setting----------------
    totalBall = 140;
    endTime = 200;
    endTime1 = 200;
    size = 29;
    offset.set(40, ofGetHeight()/2);
}

//------------------------------

void dataBall::update(){
    
    
    gravity*=-1;
    gravity *= 30;
    world.setGravity(gravity.y,gravity.x);
    world.update();

    
    if (All_Jobs !=pre_All_Jobs) {
         IMM_Pop_No = int(IMM_pctNo/100 * IMM_Jobs);
         IMM_Pop_HS = int(IMM_pctHS/100 * IMM_Jobs);
         IMM_Pop_BA = int(IMM_pctBA/100 * IMM_Jobs);
         NATIVE_Pop_No = int(NATIVE_pctNo/100 * NATIVE_Jobs);
         NATIVE_Pop_HS = int(NATIVE_pctHS/100 * NATIVE_Jobs);
         NATIVE_Pop_BA = int(NATIVE_pctBA/100 * NATIVE_Jobs);
         IMM_Number_NO = ofMap(IMM_Pop_No, 0, All_Jobs, 0, totalBall);
         IMM_Number_HS = ofMap(IMM_Pop_HS, 0, All_Jobs, 0, totalBall);
         IMM_Number_BA = ofMap(IMM_Pop_BA, 0, All_Jobs, 0, totalBall);
         NATIVE_Number_NO = ofMap(NATIVE_Pop_No, 0, All_Jobs, 0, totalBall);
         NATIVE_Number_HS = ofMap(NATIVE_Pop_HS, 0, All_Jobs, 0, totalBall);
         NATIVE_Number_BA = ofMap(NATIVE_Pop_BA, 0, All_Jobs, 0, totalBall);
    }
    
    if (*educationID == 0) {
        if (ofGetElapsedTimeMillis()-startTime>endTime) {
            float  v = ofRandom(0, 25);
            
            if (IMM_Balls_NO.size()<IMM_Number_NO) {
                CustomParticle b;
                b.setPhysics(3.0, 0.3, 0.1);
                b.setup(world.getWorld(), offset.x, offset.y, size);
                b.setVelocity(v, v);
                b.img = &icons[12];
                IMM_Balls_NO.push_back(b);
            }else if (IMM_Balls_HS.size()<IMM_Number_HS) {
                CustomParticle b;
                b.setPhysics(3.0, 0.53, 0.1);
                b.setup(world.getWorld(), offset.x, offset.y, size);
                b.setVelocity(v, v);
                b.img = &icons[7];
                IMM_Balls_HS.push_back(b);
            }else if (IMM_Balls_BA.size()<IMM_Number_BA) {
                CustomParticle b;
                b.setPhysics(3.0, 0.73, 0.1);
                b.setup(world.getWorld(), offset.x, offset.y, size);
                b.setVelocity(v, v);
                b.img = &icons[9];
                IMM_Balls_BA.push_back(b);
            }
            
            
            startTime = ofGetElapsedTimeMillis();
            
           
        }
        
        if (ofGetElapsedTimeMillis()-startTime1> endTime1) {
            float  v = ofRandom(0, 25);
            if (Native_Balls_NO.size()<NATIVE_Number_NO) {
                CustomParticle b;
                b.setPhysics(3.0, 0.3, 0.1);
                b.setup(world.getWorld(), ofGetWidth()-offset.x, offset.y, size);
                b.setVelocity(-v, -v);
                b.img = &icons[5];
                Native_Balls_NO.push_back(b);
            }else if (Native_Balls_HS.size()<NATIVE_Number_HS) {
                CustomParticle b;
                b.setPhysics(3.0, 0.53, 0.1);
                b.setup(world.getWorld(), ofGetWidth()-offset.x, offset.y, size);
                b.setVelocity(-v, -v);
                b.img = &icons[11];
                Native_Balls_HS.push_back(b);
            }else if (Native_Balls_BA.size()<NATIVE_Number_BA) {
                CustomParticle b;
                b.setPhysics(3.0, 0.73, 0.1);
                b.setup(world.getWorld(), ofGetWidth()-offset.x, offset.y, size);
                b.setVelocity(-v, -v);
                b.img = &icons[11];
                Native_Balls_BA.push_back(b);
                
            }
            
            startTime1 = ofGetElapsedTimeMillis();
        }
        
    }
    pre_All_Jobs = All_Jobs;
}

//------------------------------
void dataBall::draw(){

    if (IMM_Balls_NO.size()>0) {
        for (int i=0; i<IMM_Balls_NO.size(); i++) {
            ofSetColor(0, 255, 0, 100);
            IMM_Balls_NO[i].draw();
        }
    }
    
    if (IMM_Balls_HS.size()>0) {
        for (int i=0; i<IMM_Balls_HS.size(); i++) {
            ofSetColor(255, 0, 0,100);
            IMM_Balls_HS[i].draw();
        }
    }
    
    if (IMM_Balls_BA.size()>0) {
        for (int i=0; i<IMM_Balls_BA.size(); i++) {
            ofSetColor(0, 0, 255,100);
            IMM_Balls_BA[i].draw();
        }
    }
    
    
    
    
    if (Native_Balls_NO.size()>0) {
        for (int i=0; i<Native_Balls_NO.size(); i++) {
            ofSetColor(0, 255, 0);
            Native_Balls_NO[i].draw();
        }
    }
    
    if (Native_Balls_HS.size()>0) {
        for (int i=0; i<Native_Balls_HS.size(); i++) {
            ofSetColor(255, 0, 0);
            Native_Balls_HS[i].draw();
        }
    }
    
    if (Native_Balls_BA.size()>0) {
        for (int i=0; i<Native_Balls_BA.size(); i++) {
            ofSetColor(0, 0, 255);
            Native_Balls_BA[i].draw();
        }
    }
    
    
    
}

