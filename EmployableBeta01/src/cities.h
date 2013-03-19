//
//  cities.h
//  DataToyPrototype002
//
//  Created by PengCheng on 3/2/13.
//
//

#ifndef __DataToyPrototype002__cities__
#define __DataToyPrototype002__cities__

#include "ofMain.h"
#include "citiesParticle.h"
#include "MpiData.h"
#include "dataBall.h"
class cities{

public:
    cities();
    void setup(vector<particle> particles,int &myCase, string &name,int &year,  dataBall& _dataBall);
    void update();
    void draw();
    void touchDown(int id, int number, float x, float y);
    void touchMove(int id, int number, float x, float y);
    void touchUp(int id, int number, float x, float y);
    
    vector <citiesParticle *>       myParticles;
    int*                            level;
    int*                            myYear;
    string*                         myName;
    ofImage                         icons[5];
    ofPoint                         touchPos;
    MpiData                         dBase;
    
    dataBall*                       myBall;
    bool                            bDestry;
   
};

#endif /* defined(__DataToyPrototype002__cities__) */
