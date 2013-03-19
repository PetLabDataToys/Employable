//
//  citiesParticle.h
//  DataToyPrototype002
//
//  Created by PengCheng on 3/2/13.
//
//

#ifndef __DataToyPrototype002__citiesParticle__
#define __DataToyPrototype002__citiesParticle__

#include "ofMain.h"
#include "particle.h"
class citiesParticle : public particle{

public:
    citiesParticle();
    void                draw();
    
    float               h;
    float               s;
    float               b;
    float               a;
    ofColor             c;
    int                 CR;
    float               size;
    string              name;
    ofTrueTypeFont      font;
};

#endif /* defined(__DataToyPrototype002__citiesParticle__) */
