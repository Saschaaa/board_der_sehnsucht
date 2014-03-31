//
//  colorChange.h
//  board_der_sehnsucht
//
//  Created by Sasa on 18.12.13.
//
//

#ifndef __board_der_sehnsucht__colorChange__
#define __board_der_sehnsucht__colorChange__

#include <iostream>
#include "ofMain.h"

class colorChange{
public:

    void setup(int,int,int,int,int);
    void changeColor();
    void draw();

    bool isClicked(int, int);

    int height;
    int width;
    int xPos;
    int yPos;
    int red;
    int green;
    int blue;

};

#endif /* defined(__board_der_sehnsucht__colorChange__) */
