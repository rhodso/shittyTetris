#ifndef PIECE_H
#define PIECE_H

#include "ofMain.h"
#include "grid.h"
#include "debugger.h"

class piece
{
public:
    piece();
    piece(int _x, int _y, int _type, int _spin);
    piece(int _x, int _y, int _type, int _spin, ofColor _c);
    ~piece();

    int getX();
    int getY();
    int getType();
    int getSpin();
    ofColor getColour();

    void setX( int _x );
    void setY( int _y );
    void setXY( int _x, int _y);
    void setType( int _type );
    void setSpin( int _spin );
    void setColor( ofColor _c);

    void draw();
    bool checkLanded();
    void moveDown();
    void moveLeft();
    void moveRight();
    void rotate();
    void drop();


private:
   //type {I, J, L, O, S, T, Z};

    int x;
    int y;
    int type;
    int spin;
    ofColor c;

};

#endif // PIECE_H
