//
//  stopClock.h
//  DataToyPrototype002
//
//  Created by PengCheng on 3/3/13.
//
//

#ifndef __DataToyPrototype002__stopClock__
#define __DataToyPrototype002__stopClock__

#include "ofMain.h"


class stopClork{
public:
    stopClork();
    void setup(int &_year);
    void update(float a);
    void draw();
    void touchDown(int id, int number, float x, float y);
    void touchMove(int id, int number, float x, float y);
    void touchUp(int id, int number, float x, float y);

    ofImage img01;
    ofImage img02;
    ofImage img03;
    ofImage img04;
    ofImage img05;
    
    bool    bClorkPressed;
    bool    bBallStart;
    bool    bTimeChange;
    int     *year;
    int     mylevel;
    float startTime;
    float angle;
    float preAngle;
    float alpha;
    ofPoint prePos;
    ofPoint pos;
    ofPoint offSet;
    
    
     
  
    
};

#endif /* defined(__DataToyPrototype002__stopClock__) */
