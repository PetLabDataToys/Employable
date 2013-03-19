//
//  dataBall.h
//  DataToyPrototype002
//
//  Created by PengCheng on 3/4/13.
//
//

#ifndef __DataToyPrototype002__dataBall__
#define __DataToyPrototype002__dataBall__

#include "ofMain.h"
#include "ofxBox2d.h"

// ------------------------------------------------- a simple extended box2d circle
class CustomParticle : public ofxBox2dCircle {
	
public:
	CustomParticle() {
	}
	
	void draw() {
        
		glPushMatrix();
		glTranslatef(getPosition().x-(img->getWidth()/2), getPosition().y-(img->getWidth()/2), 0);
		
		ofSetColor(255,255,255,150);
		ofFill();
		img->draw(0, 0);
		glPopMatrix();
		
	}

    ofImage* img;
    
};

class dataBall{
public:
    void setup();
    void update();
    void draw();
    
    ofxBox2d world;
    vector<CustomParticle>  IMM_Balls_NO;
    vector<CustomParticle>  IMM_Balls_HS;
    vector<CustomParticle>  IMM_Balls_BA;
    vector<CustomParticle>  Native_Balls_NO;
    vector<CustomParticle>  Native_Balls_HS;
    vector<CustomParticle>  Native_Balls_BA;
    
    //------IMG
    int All_Jobs;
    int IMM_Jobs;
    int NATIVE_Jobs;
    float IMM_pctNo;
    float IMM_pctHS;
    float IMM_pctBA;
    float NATIVE_pctNo;
    float NATIVE_pctHS;
    float NATIVE_pctBA;
    float pre_All_Jobs;
    int IMM_Pop_No;
    int IMM_Pop_HS;
    int IMM_Pop_BA;
    int NATIVE_Pop_No;
    int NATIVE_Pop_HS;
    int NATIVE_Pop_BA;
    int IMM_Number_NO;
    int IMM_Number_HS;
    int IMM_Number_BA ;
    int NATIVE_Number_NO ;
    int NATIVE_Number_HS ;
    int NATIVE_Number_BA ;
    
    //others-----------------
    ofImage icons[13];
    ofPoint gravity;
    int totalBall;
    
    int *educationID;
    int Pop_Per_Ball;
    float startTime;
    float startTime1;
    float endTime;
    float endTime1;
    float size;
    ofPoint offset;
    
    };

#endif /* defined(__DataToyPrototype002__dataBall__) */
