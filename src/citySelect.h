//
//  citySelect.h
//  DataToyBeta02
//
//  Created by PengCheng on 3/6/13.
//
//

#ifndef __DataToyBeta02__citySelect__
#define __DataToyBeta02__citySelect__

#include "ofMain.h"
#include "MpiData.h"
#include "cityData.h"

class citySelect{

public:
    
    
    citySelect();
    void setup(string &name,int &year,bool &select, bool & bBalls);
    void update();
    void draw();
    void mouseDown(int id, int number, float x, float y);
    void mouseMove(int id, int number, float x, float y);
    void mouseUp(int id, int number, float x, float y);

    float width;
    float height;
    float speed;
    float pct;
    float W;
    float H;
    float space;
    float offSet;
    
    ofPoint             boxPos;
    string*             cityName;
    int*                cityYear;
    bool *              bSelect;
    bool *             bBall;
    bool                bDone;
    ofTrueTypeFont      font;
    MpiData             dBase;
    ofPoint             pos;
    ofPoint             prePos;
    ofPoint             prePos1;
    vector<ofRectangle> rects;
    vector<ofColor>     colors;
    vector<ofPoint>     circles;
    vector<float>       size;
    vector<float>       shape;
    vector<float>       alpha;
    ofPoint             temPos;
    
};

#endif /* defined(__DataToyBeta02__citySelect__) */
