#include "ofApp.h"

void ofApp::setup(){
	//Setup variables
    debugger::log("Initalising...");
	srand (time(NULL));
	grid::setDoUpdate(true);
	debugger::setDebug(debug);

    //Log that application setup has started
    debugger::log("Setup started");

	//Setup game vars
	frameCount = 0;

	//Setup grid vars
    debugger::log("Setting up grid..");
    g.setGH(20);
    g.setGW(10);
    tile::setSize(45);
    g.setLineColour(ofColor::fromHex(0xCCCCCC));
	g.createGrid();

    gme.setupHUD();
    gme.updateGamestate();

	//Setup completed, log
	debugger::log("Setup complete");
}

void ofApp::update(){
    frameCount++;
    gme.updateHUD();
}

void ofApp::draw(){
    ofBackground(60);
    g.drawGrid();
    gme.drawHUD();
}

void ofApp::handleKeypresses(){
    //I key
    if(keys[105]){
        gme.incrementScore();
        keys[100] = false;
    }
}

void ofApp::keyPressed(int key){
	//Log key press
	std::string msg = "Key "; msg += key; msg += "("; msg += std::to_string(key); msg += ")"; msg += " pressed on frame "; msg += std::to_string(frameCount);
	debugger::log(msg);

	//Show specified key as being pressed
	keys[key] = true;
}

//Not used
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}
