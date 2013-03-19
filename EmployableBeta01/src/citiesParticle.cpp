//
//  citiesParticle.cpp
//  DataToyPrototype002
//
//  Created by PengCheng on 3/2/13.
//
//

#include "citiesParticle.h"

citiesParticle::citiesParticle(){

    CR = 3;
    size = 70;
    font.loadFont("fonts/[z] Arista light.ttf", 14);
    name = "name";
    
    h = ofRandom(255);
    s = ofMap(31, 0, 100, 0, 255);
    b = ofMap(92, 0, 100, 0, 255);
    a = 255;
    
}

void citiesParticle::draw(){
    ofPushStyle();
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofSetCircleResolution(CR);
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    c.setHsb(h, s, b, a);
    ofSetColor(c);
    ofCircle(0, 0, size);
    ofSetColor(0, 0, 0,180);
    ofRectangle bounds;
    bounds = font.getStringBoundingBox(name, 0, 0);
    font.drawString(name, 0- bounds.getWidth()/2, bounds.getHeight()/2);
    ofPopMatrix();
    ofPopStyle();
}