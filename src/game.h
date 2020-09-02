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

        //Utility methods
        void incrementScore();

        //Other methods
        void setupHUD();
        void updateHUD();
        void drawHUD();

        void updateGamestate();

    private:
        //Variables
        piece* currentPiece;
        piece* nxtPiece;
        bool pieceInPlay = false;
        ui hud;

        int score = 0;

        enum element {lineCounter, nextPiece};

};
#endif
