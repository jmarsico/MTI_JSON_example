#include "ofApp.h"


void ofApp::setup()
{
    ofSetFrameRate(30);
    ofBackground(0);

    jThread.init();
    jThread.startThread(true);
    
    sender.setup("128.237.163.166", 12345);
}


void ofApp::update()
{
    ////update thread data/////
    jThread.lock();
    
    firstQuake = ofToFloat(jThread.quakes[0]);
    
    jThread.unlock();
    
    ofxOscMessage m;
    m.setAddress("/vibration");
    m.addFloatArg(firstQuake);
    sender.sendMessage(m);

    
    
}

void ofApp::draw()
{
    stringstream weather;
    /*
    weather << "quake0: " << ofToString(quake0) << endl
    << "quake: " << ofToString(quake1) << endl
    << "quake: " << ofToString(quake2) << endl
    << "quake: " << ofToString(quake3) << endl;
    
    ofDrawBitmapString(weather.str(), 10,10);
     */
    
    ofDrawBitmapString(ofToString(firstQuake), 10,10);
    
    
    

}
