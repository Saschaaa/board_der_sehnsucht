//
//  colorChange.cpp
//  board_der_sehnsucht
//
//  Created by Sasa on 18.12.13.
//
//

#include "colorChange.h"

void colorChange::setup(int x, int y, int r, int g, int b){
    width = 40;
    height = 40;
    xPos = x;
    yPos = y;
    red = r;
    green = g;
    blue = b;

}

void colorChange::draw(){

    ofSetLineWidth(4);
    ofSetColor(red,green,blue);
    ofRect(xPos,yPos,width,height);

}


bool colorChange::isClicked(int x, int y){

    //hier wird geprüft ob sich die Maus innerhalb oder außerhalb der erstellten Buttons befindet
    if( (x > xPos && x < xPos+width) && (y > yPos && y < yPos+height) ){

        return TRUE;
    } else {
       ;
        return FALSE;
    }
}

