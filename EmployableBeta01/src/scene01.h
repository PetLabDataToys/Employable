//
//  scene.h
//  DataToyPrototype002
//
//  Created by PengCheng on 3/2/13.
//
//

#ifndef __DataToyPrototype002__scene__
#define __DataToyPrototype002__scene__

#include "ofMain.h"
#include "particle.h"
#include "vectorField.h"


class scene01{
public:

    scene01();
    void    setup(int &level);
    void    update();
    void    draw();
    void    touchDown(int id, int number, float x, float y);
    void    touchMove(int id, int number, float x, float y);
    void    touchUp(int id, int number, float x, float y);
    vector<particle>        particles;
    vectorField             VF;
    
    ofImage                 bg;
    ofImage                 icons[6];
    int                         b[6];
 
    ofPoint                 AddOutwardCirclePos;
    
    bool                    bAddOutwardCircle;
};

#endif /* defined(__DataToyPrototype002__scene__) */
