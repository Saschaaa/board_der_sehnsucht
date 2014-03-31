#include "button.h"

void myButton::setup(int x, int y, string url){


    //lŠdt nun extern erstellte Buttons
    button.loadImage(url);

    xPos = x;
    yPos = y;

    height = button.getHeight();
    width = button.getWidth();

}

void myButton::draw(){

    //externe Buttons werden gezeichnet
    ofSetColor(255);
    button.draw(xPos,yPos);

}

bool myButton::isClicked(int x, int y){

    //hier wird geprŸft ob sich die Maus innerhalb oder au§erhalb der erstellten Buttons befindet
    if( (x > xPos && x < xPos+width) && (y > yPos && y < yPos+height) ){
        return TRUE;
    } else {
        return FALSE;
    }
}
