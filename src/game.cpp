//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include "game.h"
#include "debugger.h"


//Constructor and Destructor
game::game(){}
game::~game(){}

//Getters and Setters
piece* game::getCurrentPiece(){ return currentPiece; }
piece* game::getNextPiece(){ return nxtPiece; }
bool game::getPieceInPlay(){ return pieceInPlay; }
ui game::getHud(){ return hud; }

void game::setCurrentPiece( piece* _currentPiece){ currentPiece = _currentPiece; }
void game::setNextPiece( piece* _nxtPiece){ nxtPiece = _nxtPiece; }
void game::setPieceInPlay( bool _pieceInPlay){ pieceInPlay = _pieceInPlay; }
void game::setHud( ui _hud){ hud = _hud; }

//Other methods
void game::setupHUD(){
    debugger::log("Adding UI elements to hud");
    uiElement* testElement = new uiElement();

    /*
    debugger::log("Setting up testElement");
    testElement->setX(100);
    testElement->setY(100);
    testElement->setL(25);
    testElement->setH(25);
    testElement->setBgColour(ofColor::red);
    testElement->setTextColour(ofColor::white);
    testElement->setAlignLeft(true);

    testElement->setText("Test");
    hud.addToElementList(testElement);


    debugger::log("Added test element");
    */


    //Setup lineCounter uiElement
    uiElement* lineCounter = new uiElement(
                (grid::getOffsetX() + (grid::getGW()*tile::getSize())),
                grid::getOffsetY(),
                100,
                0,
                true,
                ofColor::black,
                ofColor::white
                );
    lineCounter->setText("Line Counter");
    hud.addToElementList(lineCounter);

    //Setup next piece uiElement
    uiElement* nextPiece = new uiElement(
                grid::getOffsetX(),
                grid::getOffsetY(),
                100,
                0,
                false,
                ofColor::black,
                ofColor::white
                );
    nextPiece->setText("Next Piece");
    hud.addToElementList(nextPiece);

}

void game::drawHUD(){
    debugger::log("Started drawing ui elements");
    for( uiElement* e : hud.getElementList()){
        e->draw();
    }
}
