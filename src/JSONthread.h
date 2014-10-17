#pragma once


#include "ofMain.h"
#include "ofxJSON.h"


class JSONthread: public ofThread
{
public:
    /// 
    /// variable in an initialization list.
    void init()
    {
        //set the URL to the Kimono API: https://www.kimonolabs.com/apis/4k9ehldm
        url = "https://www.kimonolabs.com/api/8o3jrfgs?apikey=No7h5YUcyCWbbn7xjG0ukUrDZTpjWFUU";
        //see if the API works
        bool parsingSuccessful = json.open(url);
        
        if(parsingSuccessful)
        {
            ofLogNotice("JSONthread::Init") << json.getRawString(true);
 
            ofLogNotice("JSONthread::threadedFunction") << "info received";
            
            // Attempt to lock the mutex.  If blocking is turned on,
            if(lock())
            {
                ofLogNotice("JSONthread::threadedFunction") << "locked";
                //do stuff
                for(int i = 0; i < json["results"]["collection1"].size(); i++)
                {
                    
                    string q= json["results"]["collection1"][i]["amnt"].asString();
                    quakes.push_back(q);
                    
                }
                
                ofLogNotice("JSONthread::threadedFunction") << "we got quakes: " << quakes.size();
                ofLogNotice("JSONthread::threadedFunction") << "firstquake: " << quakes[0];
                
                unlock();
                ofLogNotice("JSONthread::threadedFunction") << "unlocked. going to sleep...";
                // Sleep for 30 seconds.
            }
            else
            {
                // If we reach this else statement, it means that we could not
                // lock our mutex, and so we do not need to call unlock().
                // Calling unlock without locking will lead to problems.
                ofLogWarning("JSONthread::threadedFunction") << "Unable to lock mutex.";
            }
        }
    }

    

    


    /// Our implementation of threadedFunction.
    void threadedFunction()
    {
        while(isThreadRunning())
        {
            
            ofLogNotice("JSONthread::threadedFunction") << "waiting for info...";
            bool parsingSuccessful = json.open(url);
            
            if(parsingSuccessful)
            {
                json.getRawString(true);
                ofLogNotice("JSONthread::threadedFunction") << "info received";
                            
                // Attempt to lock the mutex.  If blocking is turned on,
                if(lock())
                {
                    ofLogNotice("JSONthread::threadedFunction") << "locked";
                    //do stuff
                    for(int i = 0; i < quakes.size(); i++)
                    {
                    
                        string q= json["results"]["collection1"][i]["amnt"].asString();
                        quakes[i] = q ;
                     
                    }
                    
                    ofLogNotice("JSONthread::threadedFunction") << "we got quakes: " << quakes.size();
                    ofLogNotice("JSONthread::threadedFunction") << "firstquake: " << quakes[0];

                    unlock();
                    ofLogNotice("JSONthread::threadedFunction") << "unlocked. going to sleep...";
                    // Sleep for 30 seconds.
                    sleep(1000 * 30);
                }
                else
                {
                    // If we reach this else statement, it means that we could not
                    // lock our mutex, and so we do not need to call unlock().
                    // Calling unlock without locking will lead to problems.
                    ofLogWarning("JSONthread::threadedFunction") << "Unable to lock mutex.";
                }
            }
        }
    }
    
    ofxJSONElement json;
    std::string url;
    vector<string> quakes;
    
};
