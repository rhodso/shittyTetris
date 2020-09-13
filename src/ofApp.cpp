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

    debugger::log("Creating test piece");
    p = piece(5,5,0,0, ofColor::darkBlue);

    g.setTileColour(0,10,ofColor::blue);
    g.setTileColour(5,10,ofColor::green);
    g.setTileColour(0,15,ofColor::red);
    g.setTileColour(5,15,ofColor::yellow);

}

void ofApp::update(){
    //debugger::log("P - X: " + std::to_string(p.getX()) + ", Y: " + std::to_string(p.getY()));
    frameCount++;
    handleKeypresses();

    if(grid::getDoUpdate()){
        grid::saveGrid();
        grid::resetGrid();
        grid::restoreGrid();

        gme.updateHUD();
    }

    //debugger::log("Key 32 state: " + std::to_string(keys[32]));

}

void ofApp::draw(){
    ofBackground(60);
    p.draw();
    gme.drawHUD();

    /*
    if(gme.getPieceInPlay()){
        gme.getCurrentPiece()->unsetOccupied();
    }
    */

    g.drawGrid();

    grid::setOccupied();

    g.drawGridDebug();

    ofSetColor(ofColor::blue);
    ofDrawCircle(10,10,10);
    ofSetColor(ofColor::green);
    ofDrawCircle(60,10,10);
    ofSetColor(ofColor::red);
    ofDrawCircle(10,60,10);
    ofSetColor(ofColor::yellow);
    ofDrawCircle(60,60,10);
}

void ofApp::handleKeypresses(){
    //Space
    if(keys[32]){
        p.rotate();
        keys[32] = false;
    }

    //A
    if(keys[97]){
        p.moveLeft();
        keys[97] = false;
    }

    //D
    if(keys[100]){
        p.moveRight();
        keys[100] = false;
    }

    //S
    if(keys[115]){
        debugger::log("Moving piece down");
        p.moveDown();
        keys[115] = false;
    }

    //Enter
    if(keys[13]){
        //p.drop();
        keys[13] = false;
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
