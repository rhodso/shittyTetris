//Header file auto-generated using CPP-Getter-Setter-Generator
#ifndef GAME_H
#define GAME_H

//Includes
#include "piece.h"
#include "ui.h"
#include "uielement.h"
#include "grid.h"
#include "tile.h"

class game {
    public:
        //Constructor and Destructor
        game();
        ~game();

        //Getters and Setters
        piece* getCurrentPiece();
        piece* getNextPiece();
        bool getPieceInPlay();
        ui getHud();

        void setCurrentPiece( piece* _currentPiece );
        void setNextPiece( piece* _nxtPiece );
        void setPieceInPlay( bool _pieceInPlay );
        void setHud( ui _hud );

        //Other methods
        void setupHUD();
        void drawHUD();

    private:
        //Variables
        piece* currentPiece;
        piece* nxtPiece;
        bool pieceInPlay;
        ui hud;

        enum element {lineCounter, nextPiece};

};
#endif
