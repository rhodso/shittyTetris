#include "piece.h"

piece::piece(){}
piece::piece(int _x, int _y, int _type, int _spin){
    x = _x;
    y = _y;
    type = _type;
    spin = _spin;
}
piece::~piece(){}

int piece::getX(){ return x; }
int piece::getY(){ return y; }
int piece::getType(){ return type; }
int piece::getSpin(){ return spin; }

void piece::setX( int _x){ x = _x; }
void piece::setY( int _y){ y = _y; }
void piece::setXY(int _x, int _y){ x = _x; y = _y; }
void piece::setType( int _type){ type = _type; }
void piece::setSpin( int _spin){ spin = _spin; }

void piece::draw(){
    switch(type){
        case 0: //I
            switch(spin){
                case 0: // Verticle Left

                    break;
                case 1: // Horizontal Lower

                    break;
                case 2: // Verticle Right

                    break;
                case 3: // Horizontal Upper

                    break;
                default:
                    break;
            }
            break;
        case 1: //J
            switch(spin){
                case 0: //

                    break;
                case 1: //

                    break;
                case 2: //

                    break;
                case 3: //

                    break;
                default:
                    break;
            }
            break;
        case 2: //L
            switch(spin){
                case 0: //

                    break;
                case 1: //

                    break;
                case 2: //

                    break;
                case 3: //

                    break;
                default:
                    break;
            }
            break;
        case 3: //O
            switch(spin){
                case 0: //

                    break;
                case 1: //

                    break;
                case 2: //

                    break;
                case 3: //

                    break;
                default:
                    break;
            }
            break;
        case 4: //S
            switch(spin){
                case 0: //

                    break;
                case 1: //

                    break;
                case 2: //

                    break;
                case 3: //

                    break;
                default:
                    break;
            }
            break;
        case 5: //T
            switch(spin){
                case 0: //

                    break;
                case 1: //

                    break;
                case 2: //

                    break;
                case 3: //

                    break;
                default:
                    break;
            }
            break;
        case 6: //Z
            switch(spin){
                case 0: //

                    break;
                case 1: //

                    break;
                case 2: //

                    break;
                case 3: //

                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

bool piece::checkLanded(){
    return false;
}
void piece::moveDown(){

}
void piece::moveLeft(){

}
void piece::moveRight(){

}
void piece::rotate(){

}
void piece::drop(){

}

