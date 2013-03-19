//
//  cityData.h
//  DataToyBeta02
//
//  Created by PengCheng on 3/7/13.
//
//

#ifndef __DataToyBeta02__cityData__
#define __DataToyBeta02__cityData__

#include "ofMain.h"
#include "MpiData.h"
class cityData{
public:
    void setup(string &name,int &year);
    void update();
    void draw();
    void touchDown(int id, int number, float x, float y);
    void touchMove(int id, int number, float x, float y);
    void touchUp(int id, int number, float x, float y);
    
    
    MpiData                         dBase;
    string*                         cityName;
    int*                            cityYear;
    string                          preName;
    string                          pop;
    string                          imm_pct;
    string                          imm_pct_job;
    string                          imm_change;
    int                             preYear;
    
    int                             imm_no_no;
    int                             imm_hs_no;
    int                             imm_ba_no;
    
    int                             imm_no_yes;
    int                             imm_hs_yes;
    int                             imm_ba_yes;
    
    int                             nat_no_no;
    int                             nat_hs_no;
    int                             nat_ba_no;
    
    int                             nat_no_yes;
    int                             nat_hs_yes;
    int                             nat_ba_yes;
    
    int                             ball_size;
    float                           alpha;
    float                           size;
    float                           shape;
    int                             popPreBall;
                        
};

#endif /* defined(__DataToyBeta02__cityData__) */
