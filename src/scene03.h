//
//  scene03.h
//  DataToyPrototype002
//
//  Created by PengCheng on 3/2/13.
//
//

#ifndef __DataToyPrototype002__scene03__
#define __DataToyPrototype002__scene03__

#include "ofMain.h"
#include "Box2D.h"
#include "citySelect.h"
#include "cityData.h"
#include "superBall.h"


class scene03{
public:
    scene03();
    void    setup(int &level,ofPoint &grav);
    void    update();
    void    draw();
    void    touchDown(int id, int number, float x, float y);
    void    touchMove(int id, int number, float x, float y);
    void    touchUp(int id, int number, float x, float y);
    void    reset();
    
    bool                    mouseOver;
    bool                    bPressed;
    bool                    bCitySeclect;
    bool                    bBalls;
    bool                    bYear;
    float                   startTime;
    float                   ButtonSize;
    
    
    string                  cityName;
    string                  preCityName;
    int                     cityYear;
    int                     preCityYear;
    int                     lastSize;
    
    ofTrueTypeFont          font2;
    ofImage                 platForm[3];
    ofImage                 character;
    ofImage                 selectLayout01;
    ofImage                 selectLayout02;
    ofImage                 info01;
    ofImage                 icons[25];
    ofTrueTypeFont          font;
    ofRectangle             selectRect;
    ofRectangle             selectRect2;
    citySelect              select;
    cityData                myCity;
    vector<superBall>       mySuperBall;
    ofxBox2d                box2d;
    ofPoint                 *gravity;
    float                   yearTouch;
    float                   preYearTouch;
    
};

#endif /* defined(scene03) */
