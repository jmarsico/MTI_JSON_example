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

    JSONthread jThread;
    
    float quake0, quake1, quake2 ,quake3;

};
