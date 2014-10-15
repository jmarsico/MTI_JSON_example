#include "ofApp.h"


void ofApp::setup()
{
    ofSetFrameRate(30);
    ofBackground(0);

    
    quake0 = quake1 = quake2 = quake3 = 0;
    jThread.init();
    jThread.startThread(true);
}


void ofApp::update()
{
    ////update thread data/////
    jThread.lock();
    
        quake0 = ofToFloat(jThread.quake0);
        quake1 = ofToFloat(jThread.quake1);
        quake2 = ofToFloat(jThread.quake2);
        quake3 = ofToFloat(jThread.quake3);
    
    jThread.unlock();
}

void ofApp::draw()
{
    stringstream weather;
    
    weather << "quake0: " << ofToString(quake0) << endl
    << "quake: " << ofToString(quake1) << endl
    << "quake: " << ofToString(quake2) << endl
    << "quake: " << ofToString(quake3) << endl;
    
    ofDrawBitmapString(weather.str(), 10,10);
    
    

}
