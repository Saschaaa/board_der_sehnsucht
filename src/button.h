#ifndef button_h
#define button_h

#include "ofMain.h"

class myButton {

public:

    void setup(int , int , string );
    bool isClicked(int , int );
    void draw();



private:

    int xPos;
    int yPos;

    int height;
    int width;



    ofImage button;

};

#endif

