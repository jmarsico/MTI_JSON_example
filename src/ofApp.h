#pragma once


#include "ofMain.h"
#include "ofxJSON.h"
#include "JSONthread.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    //JSON & Weather stuff
    ofxJSONElement json;
    std::string url;
    
    JSONthread jThread;
    
    float humidity, pressure, temp, visibility, wind;

};
