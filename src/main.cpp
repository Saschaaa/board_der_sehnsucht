#include "ofMain.h"
#include "board.h"


//========================================================================
int main( ){

	ofSetupOpenGL(1280, 720, OF_WINDOW);			// <-------- setup the GL context
    ofSetFullscreen(false);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new board());
}
