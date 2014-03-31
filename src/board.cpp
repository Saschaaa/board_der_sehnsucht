#include "board.h"

//--------------------------------------------------------------
void board::setup(){

    ofSetColor(255);
    ofSetFrameRate(160);

    osc.setup("192.168.178.26", 1200);

    deleteButton.setup(1075, 300, "elements/loeschen.png");
    sendButton.setup(1075, 425, "elements/senden.png");
    drawBoard.loadImage("elements/hg.png");
    headline.loadImage("elements/schrift.png");
    background.loadImage("elements/hintergrund.png");

    redButton.setup(1100,225,155,23,64);
    blueButton.setup(1175,225,0,0,128);
    greenButton.setup(1250,225,0,139,0);

    theWriting.setup(155,23,64);

    colorhelp = 10;
    colorIndex = 1;

}

//--------------------------------------------------------------
void board::update(){

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

}





//--------------------------------------------------------------
void board::draw(){

    ofSetColor(255);

    background.draw(0,0);
    drawBoard.draw(65,130);
    headline.draw(175,20);


    theWriting.draw();

    if(colorhelp == 0){
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

    deleteButton.draw();
    sendButton.draw();

}

//--------------------------------------------------------------
void board::keyPressed(int key){

    if(key == 'x'){
        ofToggleFullscreen();
    }

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


    //schreiben nur innerhalb des drawBoards möglich
    if( !deleteButton.isClicked(x, y) && !sendButton.isClicked(x, y) && x < drawBoard.width + 65   && x > drawBoard.width - drawBoard.width +65 && y < drawBoard.height + 130  && y > drawBoard.height-drawBoard.height +130 ){
        theWriting.setNewPoint(x, y);
    }

}

//--------------------------------------------------------------
void board::mousePressed(int x, int y, int button){

    //schreiben nur innerhalb des drawBoards möglich
    if( !deleteButton.isClicked(x, y) && !sendButton.isClicked(x, y) && x < drawBoard.width + 65 && x > drawBoard.width - drawBoard.width + 65 && y < drawBoard.height + 130 && y > drawBoard.height-drawBoard.height + 130 ){
        theWriting.setFirstPoint(x, y);

    }

    if( deleteButton.isClicked(x, y) ){
        theWriting.deleteIt();
    }

    if( sendButton.isClicked(x, y) ){

        osc.sendVectorArray( theWriting.getVectorArray(), theWriting.getColor(), colorIndex );
        theWriting.deleteIt();

    }


}

//--------------------------------------------------------------
void board::mouseReleased(int x, int y, int button){

    //schreiben nur innerhalb des drawBoards möglich
    if( !deleteButton.isClicked(x, y) && !sendButton.isClicked(x, y) && x < drawBoard.width + 65 && x > drawBoard.width - drawBoard.width + 65 && y < drawBoard.height + 130 && y > drawBoard.height-drawBoard.height + 130){
        theWriting.setLastPoint(x, y);

    }


    if( redButton.isClicked(x, y) ){

        theWriting.changeColor(155,23,64);
        colorhelp = 10;
        colorIndex = 1;

    }


    if( blueButton.isClicked(x, y) ){

        theWriting.changeColor(0,0,128);
        colorhelp = 20;
        colorIndex = 2;

    }

    if( greenButton.isClicked(x, y) ){

        theWriting.changeColor(0,139,0);
        colorhelp = 30;
        colorIndex = 3;

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
