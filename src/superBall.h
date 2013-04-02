//
//  superBall.h
//  DataToyBeta02
//
//  Created by PengCheng on 3/7/13.
//
//

#ifndef __DataToyBeta02__superBall__
#define __DataToyBeta02__superBall__

#include "ofMain.h"
#include "ofxBox2d.h"


class superBall : public ofxBox2dCircle{
public:
    superBall();
    ofColor color;
    int cs;
    void draw();
    float alpha;
};

#endif /* defined(__DataToyBeta02__superBall__) */
