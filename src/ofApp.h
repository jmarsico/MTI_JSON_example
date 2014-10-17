#pragma once


#include "ofMain.h"
#include "ofxJSON.h"
#include "JSONthread.h"
#include "ofxOsc.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    JSONthread jThread;
    
    vector<float> quakes;
    float firstQuake;
    
    ofxOscSender sender;

};
