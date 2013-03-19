//
//  superBall.cpp
//  DataToyBeta02
//
//  Created by PengCheng on 3/7/13.
//
//

#include "superBall.h"

superBall::superBall(){
    color.set(30, 0, 255);
    cs =30;
    alpha = 179;
}

void superBall::draw(){
    
   
    float radius = getRadius();
    glPushMatrix();
    glTranslatef(getPosition().x, getPosition().y, 0);
    ofSetCircleResolution(cs);
    ofSetColor(color.r, color.g, color.b, alpha);
    ofFill();
    ofCircle(0, 0, radius);
    glPopMatrix();
    

}
