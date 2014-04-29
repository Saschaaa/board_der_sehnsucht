#include "board.h"

//--------------------------------------------------------------
void board::setup(){

    ofSetColor(255);
    ofSetFrameRate(60);
    ofHideCursor();


    bTimerReached = false;
    startTime = ofGetElapsedTimeMillis();
    endTime = 3000;


   	if( XML.loadFile("mySettings.xml") ){
		cout << "loaded" << endl;
	}else{
		cout << "not_loaded" << endl;
	}

    red		= XML.getValue("BACKGROUND:COLOR:RED", 0);
	green	= XML.getValue("BACKGROUND:COLOR:GREEN", 0);
	blue	= XML.getValue("BACKGROUND:COLOR:BLUE", 0);

	deletebutton_s = XML.getValue("SETTINGS:ELEMENTS:DELETEBUTTON", "");
	sendbutton_s = XML.getValue("SETTINGS:ELEMENTS:SENDBUTTON", "");
	deletelast_s = XML.getValue("SETTINGS:ELEMENTS:DELETELAST", "");
	drawboard_s = XML.getValue("SETTINGS:ELEMENTS:DRAWBOARD", "");
	background_s = XML.getValue("SETTINGS:ELEMENTS:BACKGROUND", "");
	headline_s = XML.getValue("SETTINGS:ELEMENTS:HEADLINE", "");
	success_s = XML.getValue("SETTINGS:ELEMENTS:SUCCESSBUTTON", "");

	ip_s = XML.getValue("SETTINGS:OSC:IP", "");
	port_s = XML.getValue("SETTINGS:OSC:PORT", 0);

	succeed = false;

    osc.setup(ip_s, port_s);
    osc.loadXML();

    deleteButton.setup(50, 625, deletebutton_s);
    deleteLast.setup(320, 625, deletelast_s);
    sendButton.setup(950, 625, sendbutton_s);
    successButton.setup(950, 625, success_s);
    drawBoard.loadImage(drawboard_s);
    headline.loadImage(headline_s);
    background.loadImage(background_s);

	theWriting.setup(red,green,blue);



}

//--------------------------------------------------------------
void board::update(){

//----------------------------------------SEHNSUCHTSGENERATOR--------------------------------

  /*  if(ofGetElapsedTimeMillis() - time >= 5000){

        osc.generator_dynamisch();
        time = ofGetElapsedTimeMillis();

    }
*/

}



//--------------------------------------------------------------
void board::draw(){


    float timer = ofGetElapsedTimeMillis() - startTime;

    if(timer >= endTime && !bTimerReached) {

        bTimerReached = true;
        succeed = false;

    }


//----------------------------------------SCREENELEMENTE ZEICHNEN-----------------------------------------------------
    ofSetColor(255);

    background.draw(0,0);
    drawBoard.draw(50,130);
    headline.draw(70,20);

    theWriting.draw();

    deleteButton.draw();
    sendButton.draw();
    deleteLast.draw();

    if(succeed){

           successButton.draw();

    }

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

    if(key == 'n'){

        successButton.draw();
    }

    if (key == 's'){
		succeed = !succeed;
        if (succeed){
           cout << "heppa" << endl;;
           //successButton.draw();

        }else{
            cout << "out"  << endl;;
        }
	}

	if(key == ' ') {
        bTimerReached = false;                     // reset the timer
        startTime = ofGetElapsedTimeMillis();  // get the start time
        endTime = 3000; // in milliseconds
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
    if( x < drawBoard.width + 30   && x > drawBoard.width - drawBoard.width + 50 && y < drawBoard.height + 110  && y > drawBoard.height-drawBoard.height +130 ){

        theWriting.setNewPoint(x, y);

    }


}

//--------------------------------------------------------------
void board::mousePressed(int x, int y, int button){


    //---------------------------------------------------------NEUER STARTPUNKT------------------------------------------
    if( x < drawBoard.width + 30 && x > drawBoard.width - drawBoard.width + 50 && y < drawBoard.height + 110 && y > drawBoard.height-drawBoard.height + 130 ){

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
        succeed = true;
        bTimerReached = false;
        startTime = ofGetElapsedTimeMillis();
        endTime = 3000;
    }

    else if(deleteLast.isClicked(x,y)){

        theWriting.deleteLast();

    }

}

//--------------------------------------------------------------
void board::mouseReleased(int x, int y, int button){


    //-----------------------------------------------------LETZTEN PUNKT SETZEN--------------------------------------------------------------------------
    if( !deleteButton.isClicked(x, y) && !sendButton.isClicked(x, y) && !deleteLast.isClicked(x,y)){

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
