#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
	ofxiPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_LEFT);
	ofSetCircleResolution(100);
    ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofxAccelerometer.setup();
    
    reset =                     false;
    level =                     0;
    eductionID =                0;
    //sences
    myScene02.setup(level,ofxAccelerometer.getForce());
    myScene03.setup(level,ofxAccelerometer.getForce());
    
	// initialize the accelerometer
	balls.assign(10, Ball());
	arrow.loadImage("images/arrow.png");
	arrow.setAnchorPercent(1.0, 0.5);
    
	// initialize all of the Ball particles
	for(int i=0; i<balls.size(); i++){
		balls[i].init(i);
	}
    //background image
    bg.loadImage("image/bg01.png");
    bg1.loadImage("image/bg02.png");
    
    myidentity.setup(level, eductionID, reset);
}


//--------------------------------------------------------------
void testApp::update() {
    
       
   
    switch (level) {
        case 0:
        {
            
            myidentity.update();
            for(int i=0; i < balls.size(); i++){
                balls[i].update();
            }
        }
            break;
            
        case 1:
        {
            if (reset) {
                myScene02.reset();
                reset = false;
            }
            myScene02.update();
            myidentity.update();
           
        }
            break;
            
        case 2:
        {
            if (reset) {
                myScene03.reset();
                reset = false;
            }
            myScene03.update();
            myidentity.update();
            
        }
            break;
            
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw() {
    
    switch (level) {
        case 0:{
            ofSetColor(255, 255, 255,255);
            bg.draw(0, 0);
            ofSetColor(255, 255, 255,255);
            bg1.draw(0, 0);
            myidentity.draw();
        }
            break;
            
       case 1:{
            ofSetColor(255, 255, 255,255);
            bg.draw(0, 0);
            myScene02.draw();
            myidentity.draw();
            }
            break;
            
        case 2:{
            ofSetColor(255, 255, 255,255);
            bg.draw(0, 0);
            myScene03.draw();
            myidentity.draw();
        }
            break;
    }
    
//    ofSetColor(54);
//    ofPushStyle();
//    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
//    for(int i = 0; i< balls.size(); i++){
//        balls[i].draw();
//    }
//    ofPopStyle();
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
   
	balls[touch.id].moveTo(touch.x, touch.y);
	balls[touch.id].bDragged = true;
  
    myScene02.touchDown(touch.id, touch.numTouches, touch.x, touch.y);
    myScene03.touchDown(touch.id, touch.numTouches, touch.x, touch.y);
    myidentity.touchDown(touch.id, touch.numTouches, touch.x, touch.y);
    
   
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
   
	balls[touch.id].moveTo(touch.x, touch.y);
	balls[touch.id].bDragged = true;
    

    myScene02.touchMove(touch.id, touch.numTouches, touch.x, touch.y);
    myScene03.touchMove(touch.id, touch.numTouches, touch.x, touch.y);
    myidentity.touchMove(touch.id, touch.numTouches, touch.x, touch.y);
   
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){
  
	balls[touch.id].bDragged = false;
  
    myScene02.touchUp(touch.id, touch.numTouches, touch.x, touch.y);
    myScene03.touchUp(touch.id, touch.numTouches, touch.x, touch.y);
    myidentity.touchUp(touch.id, touch.numTouches, touch.x, touch.y);
    
    
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){
   
}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::lostFocus(){
    
}

//--------------------------------------------------------------
void testApp::gotFocus(){
    
}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){
    
}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

