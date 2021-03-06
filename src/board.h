#pragma once

#include "ofMain.h"

#include "writing.h"
#include "button.h"
#include "oscHelper.h"
#include "colorChange.h"
#include "ofxXmlSettings.h"



class board : public ofBaseApp{

public:

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);


    int colorhelp;
    float time;
    float time2;
    float time3;

    int colorIndex;

    Writing theWriting;

    myButton deleteButton;
    myButton sendButton;
    myButton deleteLast;
    myButton successButton;

    colorChange redButton;
    colorChange blueButton;
    colorChange greenButton;

    // externe Elemente des Screens
    ofImage drawBoard;
    ofImage headline;
    ofImage background;


    oscHelper osc;

    ofxXmlSettings XML;

    int red;
    int green;
    int blue;

    string deletebutton_s;
    string deletelast_s;
    string sendbutton_s;
    string drawboard_s;
    string headline_s;
    string background_s;
    string success_s;

    string ip_s;
    int port_s;

    bool succeed;

    float startTime;
    float endTime;

    bool  bTimerReached;


};
