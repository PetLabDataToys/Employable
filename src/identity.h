//
//  identity.h
//  DataToyPrototype002
//
//  Created by PengCheng on 3/2/13.
//
//

#ifndef __DataToyPrototype002__identity__
#define __DataToyPrototype002__identity__

#include "ofMain.h"
#define num 11

class identity{

public:
    identity();
    void setup(int &level, int &educationID, bool &reset);
    void update();
    void draw();
    void touchDown(int id, int number, float x, float y);
    void touchMove(int id, int number, float x, float y);
    void touchUp(int id, int number, float x, float y);
    
    bool                bMultiTouches;
    bool                bDelay;
    bool                bFail;
    bool                bSound;
    bool                *myReset;
    float               dis;
    float               preDis;
    float               startTime;
    float               delay;
    float               blinkDelay;
    
    
    int                 touchId;
    int                 touchSize;
    int                 *myLevel;
    int                 *myEducation;
    ofImage             circle[3];
    ofPoint             touches[num];
    
    ofTrueTypeFont          font;
    
    ofSoundPlayer           sound1;
    ofSoundPlayer           sound2;
    
};
#endif /* defined(__DataToyPrototype002__identity__) */
