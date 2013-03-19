//
//  scene.cpp
//  DataToyPrototype002
//
//  Created by PengCheng on 3/2/13.
//
//

#include "scene01.h"

scene01::scene01(){
    bAddOutwardCircle =         false;
}

//-------------------------------
void    scene01::setup(int &level){

    //icons
    for (int i =0; i<5; i++) {
        icons[i].loadImage("images/icon0" + ofToString(i+1)+".png");
    }
    //vectorfiled
    for (int i = 0; i < 50; i++){
		particle p;
        p.img = &icons[int(ofRandom(0,5))];
		p.setInitialCondition(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0, 0);
		p.damping = ofRandom(0.07, 0.08);
		particles.push_back(p);
	}
    
	VF.setupField(ofGetWidth()/50, ofGetHeight()/50,ofGetWidth(), ofGetHeight());
    //bg
    bg.loadImage("image/bg01.png");
    
    
    
}

//-------------------------------
void    scene01::update(){
    //vectorfiled
    
    if (bAddOutwardCircle) {
        VF.addOutwardCircle(AddOutwardCirclePos.x,AddOutwardCirclePos.y, 180, 5) ;
        VF.addOutwardCircle(AddOutwardCirclePos.x+150,AddOutwardCirclePos.y, 180, 5) ;
    }
    

    
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
    }
    
    for (int i = 0; i < particles.size(); i++){
        
        particles[i].addAttractionForce(-500, particles[i].initialY, 2000, 1.1);
        
        ofVec2f frc;
        frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
        particles[i].addForce(frc.x, frc.y);
        
        for (int j = 0; j < i; j++){
            particles[i].addRepulsionForce(particles[j], 50, 0.4);
        }
    }
    
    for (int i = 0; i < particles.size(); i++){
        
        particles[i].addDampingForce();
        particles[i].update();
        
        if (particles[i].pos.x < 0) {
            particles[i].setInitialCondition(ofGetWidth(), ofRandom(ofGetHeight()), -10, 0);
            
        }
    }
    
    VF.fadeField(0.97f);
    
}

//-------------------------------
void    scene01::draw(){

    ofSetColor(255, 255, 255,255);
    bg.draw(0,0);
//  VF.draw();
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }
}

//-------------------------------
void scene01::touchDown(int id, int number, float x, float y){

    if (id == 0) {
        AddOutwardCirclePos.set(x, y);
        bAddOutwardCircle = true;
    }
   
}

//-------------------------------
void    scene01::touchMove(int id, int number, float x, float y){

    if (id == 0) {
        AddOutwardCirclePos.set(x, y);
    }
    
  
}

//-------------------------------
void    scene01::touchUp(int id, int number, float x, float y){

//    if (id == 0) {
//        bAddOutwardCircle = false;
//    }
//   

}


















