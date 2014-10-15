#include "ofApp.h"


void ofApp::setup()
{
    ofSetFrameRate(30);
    ofBackground(0);

    
    humidity = pressure = temp = visibility = wind = 0;
    jThread.init();
    jThread.startThread(true);
}


void ofApp::update()
{
    ////update thread data/////
    jThread.lock();
    
    humidity = ofToFloat(jThread.humidity);
    pressure = ofToFloat(jThread.pressure);
    temp = ofToFloat(jThread.temp);
    visibility = ofToFloat(jThread.visibility);
    wind = ofToFloat(jThread.wind);
    
    jThread.unlock();
}

void ofApp::draw()
{
    stringstream weather;
    
    weather << "humidity: " << ofToString(humidity) << endl
    << "pressure: " << ofToString(pressure) << endl
    << "temp: " << ofToString(temp) << endl
    << "visibility: " << ofToString(visibility) << endl
    << "wind: " << wind << endl;
    
    ofDrawBitmapString(weather.str(), 10,10);
    
    

}
