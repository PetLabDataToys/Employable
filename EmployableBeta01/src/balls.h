//
//  balls.h
//  DataToyBeta02
//
//  Created by PengCheng on 3/7/13.
//
//

#ifndef __DataToyBeta02__balls__
#define __DataToyBeta02__balls__

#include "ofMain.h"
#include "ofxBox2d.h"

// ------------------------------------------------- a simple extended box2d circle
class CustomParticle : public ofxBox2dCircle {
	
public:
	CustomParticle() {
	}
    
    void setup(string &name, int &year);
    void update();
	ofColor color;
	void draw() {
		float radius = getRadius();
		
		glPushMatrix();
		glTranslatef(getPosition().x, getPosition().y, 0);
		
		ofSetColor(color.r, color.g, color.b);
		ofFill();
		ofCircle(0, 0, radius);
		
		glPopMatrix();
		
	}
    
    
    string*                         cityName;
    int*                            cityYear;
    int                             imm_num_HS;
    int                             imm_num_No;
    int                             imm_num_BA;
    int                             native_num_No;
    int                             native_num_BA;
    int                             native_num_HS;
    int                             imm_all;
    int                             Native_all;
    int                             no_balls;
    int                             hs_balls;
    int                             ba_balls;
    int                             Pop_Per_Ball;
    string                             preName;
    int                                 preYear;
};


#endif /* defined(__DataToyBeta02__balls__) */
