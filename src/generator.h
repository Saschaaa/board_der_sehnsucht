#ifndef __board_der_sehnsucht__generator__
#define __board_der_sehnsucht__generator__

#include "ofMain.h"
#include "ofxOsc.h"


class Generator{

public:

    void say();
    void generator_min();
    void generator_mid();
    void generator_max();
    void setup(string,int);

private:

    ofxOscSender sender2;
    ofxOscMessage minimum_m;
    ofxOscMessage mid_m;
    ofxOscMessage mid_m2;
    ofxOscMessage maximum_m;

};

#endif // GENERATOR_H_INCLUDED
