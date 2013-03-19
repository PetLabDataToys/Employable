
//
//  cityData.cpp
//  DataToyBeta02
//
//  Created by PengCheng on 3/7/13.
//
//

#include "cityData.h"

void cityData::setup(string &name, int &year){
    dBase.loadCities( "cities.csv");
    dBase.loadYear(2000, "2000.csv");
    dBase.loadYear(2010, "2010.csv");
    dBase.loadYear(2005, "2005.csv");

    cityName = &name;
    cityYear = &year;
    preName = *cityName;
    preYear = *cityYear;
    pop ="0";
    imm_pct = "0";
    imm_pct_job = "0";
    popPreBall = 30000;
}


void cityData::update(){
    
    if (*cityName !=preName || *cityYear !=preYear) {
    
        int city = dBase.getCityId(*cityName);
        int year = dBase.getYearId(*cityYear);
        
        pop = ofToString(dBase.getNumVal(MPI_NUM_POPULATION,dBase.getCityId(*cityName)),dBase.getYearId(*cityYear));
        imm_pct = ofToString(dBase.getPctVal(MPI_PCT_POPULATION_SHARE, dBase.getCityId(*cityName) , dBase.getYearId(*cityYear)));
        imm_pct_job = ofToString(dBase.getPctVal(MPI_PCT_EMPLOYED_SHARE, dBase.getCityId(*cityName),dBase.getYearId(*cityYear)));
        
        int imm_pop = dBase.getNumVal(MPI_NUM_IMMIGRANTS,city, year);
        int nat_pop = dBase.getNumVal(MPI_NUM_NATIVE,city, year);
        // imm data
        imm_no_no =1 +int( imm_pop * dBase.getPctVal(MPI_PCT_DEGREE_IMMIGRANTS_NO, city,year)/100*dBase.getPctVal(MPI_PCT_UNEMPLOY_IMMIGRANTS_NO_DEGREE, city,year)/100/popPreBall);
        
        imm_hs_no =1+ int(imm_pop * dBase.getPctVal(MPI_PCT_DEGREE_IMMIGRANTS_HIGHSCHOOL, city, year)/100 * dBase.getPctVal(MPI_PCT_UNEMPLOY_IMMIGRANTS_HIGHSCHOOL_DEGREE, city,year)/100/popPreBall);
        
        imm_ba_no =1 + int(imm_pop * dBase.getPctVal(MPI_PCT_DEGREE_IMMIGRANTS_BA, city,year)/100 * dBase.getPctVal(MPI_PCT_UNEMPLOY_IMMIGRANTS_BA_DEGREE, city,year)/100/popPreBall);
        
        imm_no_yes =1 + int((imm_pop * dBase.getPctVal(MPI_PCT_DEGREE_IMMIGRANTS_NO, city,year)/100/popPreBall)- imm_no_no);
        imm_hs_yes =1 +int((imm_pop * dBase.getPctVal(MPI_PCT_DEGREE_IMMIGRANTS_HIGHSCHOOL, city,year)/100 /popPreBall)- imm_hs_no);
        imm_ba_yes =1 +int((imm_pop * dBase.getPctVal(MPI_PCT_DEGREE_IMMIGRANTS_BA, city,year)/100 /popPreBall)- imm_ba_no);
        
        // native data
        nat_no_no =1 +int( nat_pop * dBase.getPctVal(MPI_PCT_DEGREE_NATIVE_NO, city,year)/100*dBase.getPctVal(MPI_PCT_UNEMPLOY_NATIVE_NO_DEGREE, city,year)/100/popPreBall);
        
        nat_hs_no =1 +int( nat_pop * dBase.getPctVal(MPI_PCT_DEGREE_NATIVE_HIGHSCHOOL, city,year)/100*dBase.getPctVal(MPI_PCT_UNEMPLOY_NATIVE_HIGHSCHOOL_DEGREE, city,year)/100/popPreBall);
        
        nat_ba_no =1 +int( nat_pop * dBase.getPctVal(MPI_PCT_DEGREE_NATIVE_BA, city,year)/100*dBase.getPctVal(MPI_PCT_UNEMPLOY_NATIVE_BA_DEGREE, city,year)/100/popPreBall);
        
        
        nat_no_yes =1 + int((nat_pop * dBase.getPctVal(MPI_PCT_DEGREE_NATIVE_NO, city,year)/100/popPreBall)- nat_no_no);
        nat_hs_yes =1 + int((nat_pop * dBase.getPctVal(MPI_PCT_DEGREE_NATIVE_HIGHSCHOOL, city,year)/100/popPreBall)- nat_hs_no);
        nat_ba_yes =1 + int((nat_pop * dBase.getPctVal(MPI_PCT_DEGREE_NATIVE_BA, city,year)/100/popPreBall)- nat_ba_no);
        
        
        if (nat_hs_yes > 33) {
            nat_hs_yes = 33;
        }
        if (nat_no_yes > 33) {
            nat_no_yes = 33;
        }
        if (nat_ba_yes > 33) {
            nat_ba_yes = 33;
        }
        
        size = ofMap(dBase.getPctVal(MPI_PCT_POPULATION_SHARE, dBase.getCityId(*cityName) , dBase.getYearId(*cityYear)), dBase.getMinPctVal(MPI_PCT_POPULATION_SHARE,-1,dBase.getYearId(*cityYear)), dBase.getMaxPctVal(MPI_PCT_POPULATION_SHARE,-1,dBase.getYearId(*cityYear)), 15, 60);
        
        shape = ofMap(dBase.getPctVal(MPI_PCT_EMPLOYED_SHARE, dBase.getCityId(*cityName),dBase.getYearId(*cityYear)), dBase.getMinPctVal(MPI_PCT_EMPLOYED_SHARE,-1,dBase.getYearId(*cityYear)), dBase.getMaxPctVal(MPI_PCT_EMPLOYED_SHARE,-1,dBase.getYearId(*cityYear)), 3, 12);
        
        if (*cityYear == 2010) {
            int k1 = dBase.getNumVal(MPI_NUM_IMMIGRANTS, dBase.getCityId(*cityName), dBase.getYearId(2010))*dBase.getPctVal(MPI_PCT_RECENT_ARRIVALS, dBase.getCityId(*cityName),dBase.getYearId(2010));
            
            int k2 =   dBase.getNumVal(MPI_NUM_IMMIGRANTS, dBase.getCityId(*cityName), dBase.getYearId(2005))* dBase.getPctVal(MPI_PCT_RECENT_ARRIVALS,dBase.getCityId(*cityName), dBase.getYearId(2005));

            int k =  k1 - k2;
            imm_change = ofToString(k/100);
            if (k>0) {
                alpha = 255;
            }else{
                alpha = 128;
            }
        }else if (*cityYear == 2005){
        
                int k1 = dBase.getNumVal(MPI_NUM_IMMIGRANTS, dBase.getCityId(*cityName), dBase.getYearId(2005))* dBase.getPctVal(MPI_PCT_RECENT_ARRIVALS,dBase.getCityId(*cityName), dBase.getYearId(2005));
                
                int k2 =   dBase.getNumVal(MPI_NUM_IMMIGRANTS, dBase.getCityId(*cityName), dBase.getYearId(2000))* dBase.getPctVal(MPI_PCT_RECENT_ARRIVALS,dBase.getCityId(*cityName), dBase.getYearId(2000));
                
                int k =  k1 - k2;
                imm_change = ofToString(k/100) ;
                if (k>0) {
                    alpha = 255;
                }else{
                    alpha = 128;
                }
        }else{
            imm_change = "No Earlier Data";
            alpha = 255;
            
        }
    }

}


void cityData::draw(){
    ofPushStyle();
    ofSetCircleResolution(int(shape));
    ofSetColor(237, 0, 140,int(alpha));
    ofCircle(318, 369, int(size));
    ofPopStyle();
}

