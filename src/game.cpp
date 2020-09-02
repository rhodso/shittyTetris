//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include "game.h"
#include "debugger.h"


//Constructor and Destructor
game::game(){
    currentPiece = nullptr;
    nxtPiece = nullptr;
}
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

void game::incrementScore(){ score++; }

//Other methods
void game::setupHUD(){
    debugger::log("Adding UI elements to hud");

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
    lineCounter->setText("Line Counter\n9999");
    hud.addToElementList(lineCounter);

    //Setup next piece uiElement
    uiElement* nextPiece = new uiElement(
                grid::getOffsetX() - 50,
                grid::getOffsetY(),
                100,
                0,
                false,
                ofColor::black,
                ofColor::white
                );
    nextPiece->setText("Next Piece\nLOL");
    hud.addToElementList(nextPiece);

}

void game::updateHUD(){
    uiElement* element;

    //Update line count first
    element = hud.getElementList()[0];
    element->setText("Line Counter\n" + std::to_string(score));

    //Get next piece type
    std::string type = "";
    switch(nxtPiece->getType()){
    case 0:
        type = "I";
        break;
    case 1:
        type = "J";
        break;
    case 2:
        type = "L";
        break;
    case 3:
        type = "O";
        break;
    case 4:
        type = "S";
        break;
    case 5:
        type = "T";
        break;
    case 6:
        type = "Z";
        break;
    }

    //Update next piece
    element = hud.getElementList()[1];
    element->setText("Next Piece\n" + type);
}

void game::drawHUD(){
    for( uiElement* e : hud.getElementList()){
        e->draw();
    }
}

void game::updateGamestate(){
    if(pieceInPlay){
        //Update the game based on the state of the current piece
        if(currentPiece->checkLanded()){
            //Piece has landed, handle adding it to the grid etc
            //TODO
        } else {
            //Piece hasn't landed, handle moving it down
            //TODO
        }
    } else {
        //Piece isn't in play, spawn a new one
        if(nxtPiece == nullptr){
            //Must be at the start of the game, need to spawn a new piece
            nxtPiece = new piece(
                        grid::getGW()/2,
                        grid::getGH(),
                        0,
                        0
                        );
        }

        currentPiece = nxtPiece;
        nxtPiece = new piece(
                    grid::getGW()/2,
                    grid::getGH(),
                    rand() % 6,
                    0
                    );
    }
}
