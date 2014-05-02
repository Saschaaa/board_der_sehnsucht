#ifndef oscHelper_h
#define oscHelper_h

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxXmlSettings.h"

class oscHelper {

public:

    void setup(string, int);
    void sendVectorArray( vector< ofPolyline >, ofColor, int );

    void generator_min();
    void generator_mid();
    void generator_max();

    void generator_dynamisch();


    void loadXML();


private:


    float l;
    float k;

    int amountPoints, amountLetters;

    ofxOscSender sender;

    ofxOscMessage m;
    ofxOscMessage m2;
    ofxOscMessage m3;
    ofxOscMessage m4;
    ofxOscMessage m5;
    ofxOscMessage m6;
    ofxOscMessage m7;
    ofxOscMessage m8;
    ofxOscMessage m9;
    ofxOscMessage m10;

    ofxXmlSettings XML;
    string address;

    ofxOscMessage min;

    ofxOscMessage mid_1;
    ofxOscMessage mid_2;

    ofxOscMessage max_1;
    ofxOscMessage max_2;
    ofxOscMessage max_3;
    ofxOscMessage max_4;
    ofxOscMessage max_5;

};

#endif
