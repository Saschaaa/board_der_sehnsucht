#include "board.h"

//--------------------------------------------------------------
void board::setup(){

    ofSetColor(255);
    ofSetFrameRate(60);
    ofHideCursor();


    osc.setup("192.168.1.107", 1200);

    deleteLast.setup(975, 125, "elements/pfeil.png");
    deleteButton.setup(975, 250, "elements/loeschen4.png");
    sendButton.setup(975, 375, "elements/senden4.png");
    drawBoard.loadImage("elements/drawboard.png");
    headline.loadImage("elements/wonachsehnstdudich3.png");
    background.loadImage("elements/ruine_blau.png");

    //redButton.setup(1000,225,155,23,64);
    //blueButton.setup(1075,225,0,0,128);
    //greenButton.setup(1150,225,0,139,0);

    theWriting.setup(128,0,0);

   // colorhelp = 10;
   //  colorIndex = 1;

}

//--------------------------------------------------------------
void board::update(){

//----------------------------------------SEHNSUCHTSGENERATOR--------------------------------


 /* if(ofGetElapsedTimeMillis() - time >= 4000){
    osc.generator_dynamisch();
    time = ofGetElapsedTimeMillis();
}
*/



/*
    if(ofGetElapsedTimeMillis() - time >= 4000){

        osc.generator_min();
        time = ofGetElapsedTimeMillis();

    }

    if(ofGetElapsedTimeMillis() - time2 >= 5000) {

        osc.generator_mid();
        time2 = ofGetElapsedTimeMillis();

    }

    if(ofGetElapsedTimeMillis() - time3 >= 6000) {

        osc.generator_max();
        time3 = ofGetElapsedTimeMillis();

    }
*/


  /*  if(ofGetElapsedTimeMillis() - time >= 5000){

        osc.generator_dynamisch();
        time = ofGetElapsedTimeMillis();

    }
*/

}



//--------------------------------------------------------------
void board::draw(){


//----------------------------------------SCREENELEMENTE ZEICHNEN-----------------------------------------------------
    ofSetColor(255);

    background.draw(0,0);
    drawBoard.draw(100,130);
    headline.draw(175,20);

    theWriting.draw();

 /*   if(colorhelp == 0){

        redButton.draw();
        blueButton.draw();
        greenButton.draw();

    }

    if(colorhelp == 10){

        ofFill();
        redButton.draw();
        ofNoFill();
        blueButton.draw();
        greenButton.draw();

    }

    if(colorhelp == 20){

        ofNoFill();
        redButton.draw();
        ofFill();
        blueButton.draw();
        ofNoFill();
        greenButton.draw();

    }

    if(colorhelp == 30){

        ofNoFill();
        redButton.draw();
        blueButton.draw();
        ofFill();
        greenButton.draw();

    }

    */

    deleteButton.draw();
    sendButton.draw();
    deleteLast.draw();

}

//--------------------------------------------------------------
void board::keyPressed(int key){

//---------------------------------------------FULLSCREENMODUS--------------------------------
    if(key == 'x'){

        ofToggleFullscreen();

    }

//-------------------------------------------SEHNSUCHTSGENERATOR----------------------------
    if(key == 'c'){

        osc.generator_min();

    }

    if(key == 'v'){

        osc.generator_mid();

    }

    if(key == 'b'){

        osc.generator_max();

    }

}

//--------------------------------------------------------------
void board::keyReleased(int key){

}

//--------------------------------------------------------------
void board::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void board::mouseDragged(int x, int y, int button){


    //--------------------------------------------------PUNKTE DER SEHNSUCHT HINZUFÜGEN---------------------------
    if( x < drawBoard.width + 100   && x > drawBoard.width - drawBoard.width + 100 && y < drawBoard.height + 130  && y > drawBoard.height-drawBoard.height +130 ){

        theWriting.setNewPoint(x, y);

    }




}

//--------------------------------------------------------------
void board::mousePressed(int x, int y, int button){


    //---------------------------------------------------------NEUER STARTPUNKT------------------------------------------
    if( x < drawBoard.width + 100 && x > drawBoard.width - drawBoard.width + 100 && y < drawBoard.height + 100 && y > drawBoard.height-drawBoard.height + 100 ){

        theWriting.setFirstPoint(x, y);

    }


    //--------------------------------------------------------SEHNSUCHT LÖSCHEN-------------------------------------------------------
    else if( deleteButton.isClicked(x, y) ){

        theWriting.deleteIt();

    }


    //--------------------------------------------------------SEHNSUCHT SCHICKEN-------------------------------------------------------
    else if( sendButton.isClicked(x, y) ){

        osc.sendVectorArray( theWriting.getVectorArray(), theWriting.getColor(), colorIndex );
        theWriting.deleteIt();

    }

    else if(deleteLast.isClicked(x,y)){

        theWriting.deleteLast();

    }


   //-------------------------------------------------------------FARBAUSWAHL--------------------------------------------------------------
    else if( redButton.isClicked(x, y) ){

        theWriting.changeColor(155,23,64);
        colorhelp = 10;
        colorIndex = 1;

    }


    else if( blueButton.isClicked(x, y) ){

        theWriting.changeColor(0,0,128);
        colorhelp = 20;
        colorIndex = 2;

    }

    else if( greenButton.isClicked(x, y) ){

        theWriting.changeColor(0,139,0);
        colorhelp = 30;
        colorIndex = 3;

    }


}

//--------------------------------------------------------------
void board::mouseReleased(int x, int y, int button){


    //-----------------------------------------------------LETZTEN PUNKT SETZEN--------------------------------------------------------------------------
    if( !deleteButton.isClicked(x, y) && !sendButton.isClicked(x, y) && !deleteLast.isClicked(x,y) && x < drawBoard.width + 65 && x > drawBoard.width - drawBoard.width + 65 && y < drawBoard.height + 130 && y > drawBoard.height-drawBoard.height + 130){

        theWriting.setLastPoint(x, y);

    }
}

//--------------------------------------------------------------
void board::windowResized(int w, int h){

}

//--------------------------------------------------------------
void board::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void board::dragEvent(ofDragInfo dragInfo){

}
