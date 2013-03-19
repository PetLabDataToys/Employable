//
//  scene02.cpp
//  DataToyPrototype002
//
//  Created by PengCheng on 3/2/13.
//
//

#include "scene02.h"

scene02::scene02(){

}
//-------------------------------
void scene02::setup(int &level,ofPoint &grav){

    //images
    info01.loadImage("image/info02.png");
    character.loadImage("image/gal.png");
    selectLayout01.loadImage("image/SelectingLayout01.png");
    selectLayout02.loadImage("image/SelectingLayout02.png");
    
    font.loadFont("fonts/Futura-CondensedMedium.ttf",30);
    font2.loadFont("fonts/Futura.ttc",18);

    for (int i =0; i<3; i++) {
        platForm[i].loadImage("image/c0" + ofToString(i+1)+".png");
    }
    
      //others

    startTime = ofGetElapsedTimeMillis();

    mouseOver = false;
    bPressed = false;
    bCitySeclect = false;
    bBalls = false;
    bYear = false;
    gravity = &grav;
    ButtonSize = 70;
    lastSize = 0;
    //select
    cityName = "0";
    preCityName = cityName;
    cityYear = 2005;
    preCityYear = cityYear;
    yearTouch = 0;
    
    selectRect.set(228, 443, 190, 97);
    selectRect2.set(632, 443, 170, 97);
    select.setup(cityName,cityYear,bCitySeclect, bBalls);
    myCity.setup(cityName, cityYear);
    
    box2d.init();
	box2d.setGravity(0, 15);
	box2d.createBounds();
	box2d.setFPS(30.0);
    box2d.registerGrabbing();
    box2d.setIterations(1, 1);
    
}
//-------------------------------
void scene02::update(){
    
    
    ofPoint g;
    g = *gravity;
    g.x *= -1;
    g.y *= -1;
    g *= 30;
    box2d.setGravity(g.y,g.x);
    
    box2d.update();
    
    if (bCitySeclect) select.update();
    myCity.update();
    
    if (cityName != preCityName || cityYear != preCityYear) {
        
        if (box2d.getBodyCount()>0) {
            for (int i=0; i<mySuperBall.size(); i++) {
                    mySuperBall[i].destroy();
            }
        }
        
        ofColor umImpolie;
        ofColor impolied;
        umImpolie.set(130, 202,156);
        impolied.set(1135, 129, 190);
        
        superBall b;
        b.setPhysics(3.0, 0, 0.1);
        b.setup(box2d.getWorld(), ofRandom(ofGetWidth()), ofRandom(0,ofGetHeight()/3), 44);
        b.setVelocity(0, 0);
        b.color.set(237, 0, 140);
        b.alpha = 255;
        mySuperBall.push_back(b);
        
        cout<<"imm_no_no: "<<myCity.imm_no_no<<" imm_HS_no: "<<myCity.imm_hs_no<<" imm_BA_no: "<<myCity.imm_ba_no<<endl;
        cout<<"imm_no_yes: "<<myCity.imm_no_yes<<" imm_HS_yes: "<<myCity.imm_hs_yes<<" imm_BA_yes: "<<myCity.imm_ba_yes<<endl;
        cout<<"Nat_no_no: "<<myCity.nat_no_no<<" Nat_HS_no: "<<myCity.nat_hs_no<<" Nat_BA_no: "<<myCity.nat_ba_no<<endl;
        cout<<"Nat_no_yes: "<<myCity.nat_no_yes<<" Nat_HS_yes: "<<myCity.nat_hs_yes<<" Nat_BA_yes: "<<myCity.nat_ba_yes<<endl;
        
        //-----NO-----
        for (int i =0; i<myCity.imm_no_no; i++) {
            superBall b;
            b.setPhysics(3.0, 0, 0.1);
            b.setVelocity(0, 10);
            b.setup(box2d.getWorld(), ofRandom(50,ofGetWidth()-50), ofRandom(0,ofGetHeight()/3), 10);
            b.color = umImpolie;
            mySuperBall.push_back(b);
        }
        
        for (int i =0; i<myCity.imm_no_yes; i++) {
            superBall b;
            b.setPhysics(3.0, 0, 0.1);
            b.setup(box2d.getWorld(), ofRandom(50,ofGetWidth()-50), ofRandom(0,ofGetHeight()/3), 10);
            b.color = impolied;
            mySuperBall.push_back(b);
        }
        
        for (int i =0; i<myCity.nat_no_no; i++) {
            superBall b;
            b.setPhysics(3.0, 0.3, 0.1);
            b.setVelocity(0, 10);
            b.setup(box2d.getWorld(), ofRandom(50,ofGetWidth()-50), ofRandom(0,ofGetHeight()/3), 10);
            b.color = umImpolie;
            mySuperBall.push_back(b);
        }
        
        for (int i =0; i<myCity.nat_no_yes; i++) {
            superBall b;
            b.setPhysics(3.0, 0.3, 0.1);
            b.setVelocity(0, 10);
            b.setup(box2d.getWorld(), ofRandom(50,ofGetWidth()-50), ofRandom(0,ofGetHeight()/3), 10);
            b.color = impolied;
            mySuperBall.push_back(b);
        }
        
        //-----HS-----
        for (int i =0; i<myCity.imm_hs_no; i++) {
            superBall b;
            b.setPhysics(3.0, 0.3, 0.1);
            b.setVelocity(0, 10);
            b.setup(box2d.getWorld(), ofRandom(50,ofGetWidth()-50), ofRandom(ofGetHeight()/3), 32);
            b.setVelocity(0, 0);
            b.color = umImpolie;
            mySuperBall.push_back(b);
        }
        
        for (int i =0; i<myCity.imm_hs_yes; i++) {
            superBall b;
            b.setPhysics(3.0, 0.3, 0.1);
            b.setVelocity(0, 10);
            b.setup(box2d.getWorld(), ofRandom(50,ofGetWidth()-50), ofRandom(ofGetHeight()/3), 32);
            b.color = impolied;
            mySuperBall.push_back(b);
        }
        
        for (int i =0; i<myCity.nat_hs_no; i++) {
            superBall b;
            b.setPhysics(3.0, 0.3, 0.1);
            b.setVelocity(0, 10);
            b.setup(box2d.getWorld(), ofRandom(50,ofGetWidth()-50), ofRandom(ofGetHeight()/3), 32);
            b.setVelocity(0, 0);
            b.color = umImpolie;
            mySuperBall.push_back(b);
        }
        
        for (int i =0; i<myCity.nat_hs_yes; i++) {
            superBall b;
            b.setPhysics(3.0, 0.3, 0.1);
            b.setVelocity(0, 10);
            b.setup(box2d.getWorld(), ofRandom(50,ofGetWidth()-50), ofRandom(ofGetHeight()/3), 32);
            b.color = impolied;
            mySuperBall.push_back(b);
        }
        
        //-----BA-----
        for (int i =0; i<myCity.imm_ba_no; i++) {
            superBall b;
            b.setPhysics(3.0, 0.3, 0.1);
            b.setVelocity(0, 10);
            b.setup(box2d.getWorld(), ofRandom(50,ofGetWidth()-50), ofRandom(ofGetHeight()/3), 44);
            b.color = umImpolie;
            mySuperBall.push_back(b);
        }
        for (int i =0; i<myCity.imm_ba_yes; i++) {
            superBall b;
            b.setPhysics(3.0, 0.3, 0.1);
            b.setVelocity(0, 10);
            b.setup(box2d.getWorld(), ofRandom(50,ofGetWidth()-50), ofRandom(ofGetHeight()/3), 44);
            b.color = impolied;
            mySuperBall.push_back(b);
        }
        
        for (int i =0; i<myCity.nat_ba_no; i++) {
            superBall b;
            b.setPhysics(3.0, 0.3, 0.1);
            b.setVelocity(0, 10);
            b.setup(box2d.getWorld(), ofRandom(50,ofGetWidth()-50), ofRandom(ofGetHeight()/3), 44);
            b.color = umImpolie;
            mySuperBall.push_back(b);
        }
        for (int i =0; i<myCity.nat_ba_yes; i++) {
            superBall b;
            b.setPhysics(3.0, 0.3, 0.1);
            b.setVelocity(0, 10);
            b.setup(box2d.getWorld(), ofRandom(50,ofGetWidth()-50), ofRandom(ofGetHeight()/3), 44);
            b.color = impolied;
            mySuperBall.push_back(b);
        }
        
        
        preCityName = cityName;
        preCityYear = cityYear;
        
    }
}
//-------------------------------
void scene02::draw(){
 
    ofColor myColor;
    mouseOver ? myColor.set(255, 255, 255,150) : myColor.set(255, 255, 255, 250);
    ofSetColor(myColor);

    ofSetColor(255, 255, 255,179);
    platForm[1].draw(177,270);
    ofSetColor(255, 255, 255,179);
    platForm[2].draw(573,270);
    ofSetColor(255, 255, 255,179);
    platForm[0].draw(376,166);
    if (mySuperBall.size()>0) {
        for (int i=0; i<mySuperBall.size(); i++) {
            mySuperBall[i].draw();
        }
    }
    ofSetColor(255, 255, 255,255);
    info01.draw(406, 211);
    ofSetColor(255, 255, 255,255);
    character.draw(430, 337);
    selectLayout01.draw(236, 439);
    selectLayout02.draw(660, 439);

    if (cityName == "0") {
    font.drawString("SELECT A CITY", 231, 505);
    }else{
    ofRectangle rect;
    rect = font.getStringBoundingBox(cityName, 0, 0);
    font.drawString(cityName, int(317-rect.getWidth()/2), 503);
    myCity.draw();
    
    rect = font2.getStringBoundingBox("Population: " + myCity.pop, 0, 0);
    font2.drawString("Population: " + myCity.pop, int(317-rect.getWidth()/2), 567+30);
    rect = font2.getStringBoundingBox("Imm Pop Pct: "+ myCity.imm_pct, 0, 0);
    font2.drawString("Imm Pop Pct: " + myCity.imm_pct, int(317-rect.getWidth()/2), 567+60);
    rect = font2.getStringBoundingBox("Imm Job Pct: "+ myCity.imm_pct_job, 0, 0);
    font2.drawString("Imm Job Pct: " + myCity.imm_pct_job, int(317-rect.getWidth()/2), 567+90);
    rect = font2.getStringBoundingBox("Recent Arrived Imm +/-: "+ myCity.imm_change, 0, 0);
    font2.drawString("Recent Arrived Imm +/-: " + myCity.imm_change, int(317-rect.getWidth()/2), 567+120);


    }

    font.drawString(ofToString(cityYear), 685, 505);

  
    
   
    
    if (bCitySeclect) {
        select.draw();
    }
    
    
}
//-------------------------------
void scene02::touchDown(int id, int number, float x, float y){
    
    if (selectRect.inside(x, y)&& bCitySeclect == false) {
        select.width = 0;
        select.height = 0;
        select.pct = 0;
        bCitySeclect = true;
      
    }
    if (cityName!="0") {
        if (id == 0) {
            if (selectRect2.inside(x, y) && bYear == false) {
                yearTouch = y;
                bYear = true;
                cout<<bYear<<endl;
            }
        }
        
    }
    
    
    if (bCitySeclect) select.mouseDown(id, number, x, y);
}
//-------------------------------
void scene02::touchMove(int id, int number, float x, float y){
  
    
    if (bCitySeclect) select.mouseMove(id, number, x, y);
         
}

//-------------------------------
void scene02::touchUp(int id, int number, float x, float y){
    

    if (bCitySeclect) {
    select.mouseUp(id, number, x, y);
            
    }
    
    if(id==0) {
       
        if (bYear) {
            if(y-yearTouch>0){
                cityYear +=5;
            }else if(y-yearTouch<0){
                cityYear -=5;
            }
            
            if (cityYear>2010) {
                cityYear = 2010;
            }else if(cityYear <2000){
                cityYear = 2000;
            }
        
            yearTouch = y;
            bYear = false;
          
        }
    }
}

void scene02::reset(){
    
    mouseOver = false;
    bPressed = false;
    bCitySeclect = false;
    bBalls = false;
    cityName = "0";
    preCityName = cityName;
    cityYear = 2005;
    preCityYear = cityYear;
    
//    for (int i= 0 ; i<mySuperBall.size(); i++) {
//        mySuperBall[i].destroy();
//    }
}

