#include "piece.h"

piece::piece(){}
piece::piece(int _x, int _y, int _type, int _spin){
    x = _x;
    y = _y;
    type = _type;
    spin = _spin;
}
piece::piece(int _x, int _y, int _type, int _spin, ofColor _c){
    x = _x;
    y = _y;
    type = _type;
    spin = _spin;
    c = _c;
}
piece::~piece(){}

int piece::getX(){ return x; }
int piece::getY(){ return y; }
int piece::getType(){ return type; }
int piece::getSpin(){ return spin; }
ofColor piece::getColour(){ return c; }

void piece::setX( int _x){ x = _x; }
void piece::setY( int _y){ y = _y; }
void piece::setXY(int _x, int _y){ x = _x; y = _y; }
void piece::setType( int _type){ type = _type; }
void piece::setSpin( int _spin){ spin = _spin; }
void piece::setColor(ofColor _c){ c = _c; }

void piece::draw(){

    ofSetColor(c);

    switch(type){
        case 0: //I
            switch(spin){
                case 0: // Vertical Left
                        /*
                         *  O 4 O O
                         *  O 3 O O
                         *  O 1 O O
                         *  O 2 O O
                        */

                        grid::setTileColour(x,y,c); //1
                        grid::setTileColour(x,y+1,c); //2
                        grid::setTileColour(x,y-1,c); //3
                        grid::setTileColour(x,y-2,c); //4

                    break;
                case 1: // Horizontal Lower
                        /*
                         *  O O O O
                         *  O O O O
                         *  2 1 3 4
                         *  O O O O
                        */

                        grid::setTileColour(x,y,c); //1
                        grid::setTileColour(x-1,y,c); //2
                        grid::setTileColour(x+1,y,c); //3
                        grid::setTileColour(x+2,y,c); //4

                    break;
                case 2: // Vertical Right
                        /*
                         *  O O 4 O
                         *  O O 3 O
                         *  O O 1 O
                         *  O O 2 O
                        */

                        grid::setTileColour(x+1,y,c); //1
                        grid::setTileColour(x+1,y+1,c); //2
                        grid::setTileColour(x+1,y-1,c); //3
                        grid::setTileColour(x+1,y-2,c); //4

                    break;
                case 3: // Horizontal Upper
                        /*
                         *  O O O O
                         *  2 1 3 4
                         *  O O O O
                         *  O O O O
                        */

                        grid::setTileColour(x,y-1,c); //1
                        grid::setTileColour(x-1,y-1,c); //2
                        grid::setTileColour(x+1,y-1,c); //3
                        grid::setTileColour(x+2,y-1,c); //4

                    break;
                default:
                    break;
            }
            break;
        case 1: //J
            switch(spin){
                case 0: //
                    /*
                     *  O 4 O O
                     *  O 3 O O
                     *  2 1 O O
                     *  O O O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x-1,y,c); //2
                    grid::setTileColour(x,y-1,c); //3
                    grid::setTileColour(x,y-2,c); //4

                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  O 1 3 4
                     *  O O O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x,y-1,c); //2
                    grid::setTileColour(x+1,y,c); //3
                    grid::setTileColour(x+2,y,c); //4

                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O 1 2 O
                     *  O 3 O O
                     *  O 4 O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x+1,y,c); //2
                    grid::setTileColour(x,y+1,c); //3
                    grid::setTileColour(x,y+2,c); //4

                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  4 3 1 O
                     *  O O 2 O
                     *  O O O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x-1,y,c); //2
                    grid::setTileColour(x-2,y,c); //3
                    grid::setTileColour(x,y+1,c); //4

                    break;
                default:
                    break;
            }
            break;
        case 2: //L
            switch(spin){
                case 0: //
                    /*
                     *  O 4 O O
                     *  O 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x+1,y,c); //2
                    grid::setTileColour(x,y-1,c); //3
                    grid::setTileColour(x,y-2,c); //4

                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O 1 3 4
                     *  O 2 O O
                     *  O O O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x,y+1,c); //2
                    grid::setTileColour(x+1,y,c); //3
                    grid::setTileColour(x+2,y,c); //4

                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  2 1 O O
                     *  O 3 O O
                     *  O 4 O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x-1,y,c); //2
                    grid::setTileColour(x,y+1,c); //3
                    grid::setTileColour(x,y+2,c); //4

                    break;
                case 3: //
                    /*
                     *  O O 2 O
                     *  4 3 1 O
                     *  O O O O
                     *  O O O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x,y-1,c); //2
                    grid::setTileColour(x-1,y,c); //3
                    grid::setTileColour(x-2,y,c); //4

                    break;
                default:
                    break;
            }
            break;
        case 3: //O

                //Spin doesn't make a diference lol
                grid::setTileColour(x,y,c);
                grid::setTileColour(x+1,y,c);
                grid::setTileColour(x,y+1,c);
                grid::setTileColour(x+1,y+1,c);

            break;
        case 4: //S
            switch(spin){
                    case 0: //
                    /*
                     *  O O O O
                     *  O 2 o O
                     *  3 1 o O
                     *  4 O O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x,y-1,c); //2
                    grid::setTileColour(x-1,y,c); //3
                    grid::setTileColour(x-1,y+1,c); //4

                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  4 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x+1,y,c); //2
                    grid::setTileColour(x,y-1,c); //3
                    grid::setTileColour(x-1,y-1,c); //4


                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O O 4 O
                     *  O 1 3 O
                     *  O 2 O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x,y+1,c); //2
                    grid::setTileColour(x+1,y,c); //3
                    grid::setTileColour(x+1,y-1,c); //4

                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  2 1 O O
                     *  O 3 4 O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x-1,y,c); //2
                    grid::setTileColour(x,y+1,c); //3
                    grid::setTileColour(x+1,y+1,c); //4


                    break;
                default:
                    break;
            }
            break;
        case 5: //T
            switch(spin){
                case 0: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  3 1 4 O
                     *  O 2 O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x,y+1,c); //2
                    grid::setTileColour(x-1,y,c); //3
                    grid::setTileColour(x+1,y,c); //4

                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O 3 O O
                     *  2 1 O O
                     *  O 4 O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x-1,y,c); //2
                    grid::setTileColour(x,y-1,c); //3
                    grid::setTileColour(x,y+1,c); //4

                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  4 1 3 O
                     *  O 4 O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x,y-1,c); //2
                    grid::setTileColour(x+1,y,c); //3
                    grid::setTileColour(x-1,y,c); //4

                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O 4 O O
                     *  O 1 2 O
                     *  O 3 O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x+1,y,c); //2
                    grid::setTileColour(x,y+1,c); //3
                    grid::setTileColour(x,y-1,c); //4

                    break;
                default:
                    break;
            }
            break;
        case 6: //Z
            switch(spin){
                case 0: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  3 1 O O
                     *  4 O O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x,y-1,c); //2
                    grid::setTileColour(x-1,y,c); //3
                    grid::setTileColour(x-1,y+1,c); //4

                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  4 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x+1,y,c); //2
                    grid::setTileColour(x,y-1,c); //3
                    grid::setTileColour(x-1,y-1,c); //4

                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O O 4 O
                     *  O 1 3 O
                     *  O 2 O O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x,y+1,c); //2
                    grid::setTileColour(x+1,y,c); //3
                    grid::setTileColour(x+1,y-1,c); //4

                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  2 1 O O
                     *  O 3 4 O
                    */

                    grid::setTileColour(x,y,c); //1
                    grid::setTileColour(x-1,y,c); //2
                    grid::setTileColour(x,y+1,c); //3
                    grid::setTileColour(x+1,y+1,c); //4

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
    switch(type){
        case 0: //I
            switch(spin){
                case 0: // Vertical Left
                        /*
                         *  O 4 O O
                         *  O 3 O O
                         *  O 1 O O
                         *  O 2 O O
                        */




                    break;
                case 1: // Horizontal Lower
                        /*
                         *  O O O O
                         *  O O O O
                         *  2 1 3 4
                         *  O O O O
                        */


                    break;
                case 2: // Vertical Right
                        /*
                         *  O O 4 O
                         *  O O 3 O
                         *  O O 1 O
                         *  O O 2 O
                        */


                    break;
                case 3: // Horizontal Upper
                        /*
                         *  O O O O
                         *  2 1 3 4
                         *  O O O O
                         *  O O O O
                        */


                    break;
                default:
                    break;
            }
            break;
        case 1: //J
            switch(spin){
                case 0: //
                    /*
                     *  O 4 O O
                     *  O 3 O O
                     *  2 1 O O
                     *  O O O O
                    */


                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  O 1 3 4
                     *  O O O O
                    */


                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O 1 2 O
                     *  O 3 O O
                     *  O 4 O O
                    */

                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  4 3 1 O
                     *  O O 2 O
                     *  O O O O
                    */


                    break;
                default:
                    break;
            }
            break;
        case 2: //L
            switch(spin){
                case 0: //
                    /*
                     *  O 4 O O
                     *  O 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */


                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  O 1 3 4
                     *  O 2 O O
                    */


                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O 2 1 O
                     *  O O 3 O
                     *  O O 4 O
                    */


                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O 2 O
                     *  4 3 1 O
                     *  O O O O
                    */


                    break;
                default:
                    break;
            }
            break;
        case 3: //O


            break;
        case 4: //S
            switch(spin){
                    case 0: //
                    /*
                     *  O O O O
                     *  O 2 o O
                     *  3 1 o O
                     *  4 O O O
                    */

                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  4 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */



                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O O 4 O
                     *  O 1 3 O
                     *  O 2 O O
                    */


                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  2 1 O O
                     *  O 3 4 O
                    */



                    break;
                default:
                    break;
            }
            break;
        case 5: //T
            switch(spin){
                case 0: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  3 1 4 O
                     *  O 2 O O
                    */


                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O 3 O O
                     *  2 1 O O
                     *  O 4 O O
                    */


                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  O 1 3 O
                     *  O 4 O O
                    */


                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  4 1 2 O
                     *  O 3 O O
                    */


                    break;
                default:
                    break;
            }
            break;
        case 6: //Z
            switch(spin){
                case 0: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  3 1 O O
                     *  4 O O O
                    */


                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  4 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */


                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O O 4 O
                     *  O 1 3 O
                     *  O 2 O O
                    */


                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  2 1 O O
                     *  O 3 4 O
                    */

                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    return false;

}
void piece::moveDown(){

    if(y < grid::getGH()){
        switch(type){
            case 0: //I
                switch(spin){
                    case 0: // Vertical Left
                            /*
                             *  O 4 O O
                             *  O 3 O O
                             *  O 1 O O
                             *  O 2 O O
                            */

                            debugger::log("Piece is vertical left");
                            debugger::log("My coords (at 1) are X:" + std::to_string((int) x)+ " Y: " + std::to_string((int) y));

                            if(grid::getTileIsOccupied(x, (y+2))){
                                debugger::log("Tile below (X:" + std::to_string((int) x) + ", Y:" + std::to_string((int)  (y+2)) + ") is not occupied");
                                y++;
                            } else {
                                debugger::log("Tile below (X:" + std::to_string((int) x) + ", Y:" + std::to_string((int)  (y+2)) + ") is occupied");
                            }

                        break;
                    case 1: // Horizontal Lower
                            /*
                             *  O O O O
                             *  O O O O
                             *  2 1 3 4
                             *  O O O O
                            */

                            debugger::log("Piece is horizontal lower");

                            if(grid::getTileIsOccupied(x, y++)){
                                if(grid::getTileIsOccupied((x-1), y++)){
                                    if(grid::getTileIsOccupied((x+1), y++)){
                                        if(grid::getTileIsOccupied((x+2), y++)){
                                            y++;
                                        }
                                    }
                                }
                            }

                        break;
                    case 2: // Vertical Right
                            /*
                             *  O O 4 O
                             *  O O 3 O
                             *  O O 1 O
                             *  O O 2 O
                            */

                            debugger::log("Piece is vertical right");

                            if(grid::getTileIsOccupied(x, (y+3))){
                                y++;
                            }


                        break;
                    case 3: // Horizontal Upper
                            /*
                             *  O O O O
                             *  2 1 3 4
                             *  O O O O
                             *  O O O O
                            */

                            debugger::log("Piece is Horizontal upper");

                            if(grid::getTileIsOccupied(x, y++)){
                                if(grid::getTileIsOccupied((x-1), y++)){
                                    if(grid::getTileIsOccupied((x+1), y++)){
                                        if(grid::getTileIsOccupied((x+2), y++)){
                                            y++;
                                        }
                                    }
                                }
                            }

                        break;
                    default:
                        break;
                }
                break;
//            case 1: //J
//                switch(spin){
//                    case 0: //
//                        /*
//                         *  O 4 O O
//                         *  O 3 O O
//                         *  2 1 O O
//                         *  O O O O
//                        */


//                        break;
//                    case 1: //
//                        /*
//                         *  O O O O
//                         *  O 2 O O
//                         *  O 1 3 4
//                         *  O O O O
//                        */


//                        break;
//                    case 2: //
//                        /*
//                         *  O O O O
//                         *  O 1 2 O
//                         *  O 3 O O
//                         *  O 4 O O
//                        */

//                        break;
//                    case 3: //
//                        /*
//                         *  O O O O
//                         *  4 3 1 O
//                         *  O O 2 O
//                         *  O O O O
//                        */


//                        break;
//                    default:
//                        break;
//                }
//                break;
//            case 2: //L
//                switch(spin){
//                    case 0: //
//                        /*
//                         *  O 4 O O
//                         *  O 3 O O
//                         *  O 1 2 O
//                         *  O O O O
//                        */


//                        break;
//                    case 1: //
//                        /*
//                         *  O O O O
//                         *  O O O O
//                         *  O 1 3 4
//                         *  O 2 O O
//                        */


//                        break;
//                    case 2: //
//                        /*
//                         *  O O O O
//                         *  O 2 1 O
//                         *  O O 3 O
//                         *  O O 4 O
//                        */


//                        break;
//                    case 3: //
//                        /*
//                         *  O O O O
//                         *  O O 2 O
//                         *  4 3 1 O
//                         *  O O O O
//                        */


//                        break;
//                    default:
//                        break;
//                }
//                break;
//            case 3: //O


//                break;
//            case 4: //S
//                switch(spin){
//                        case 0: //
//                        /*
//                         *  O O O O
//                         *  O 2 o O
//                         *  3 1 o O
//                         *  4 O O O
//                        */

//                        break;
//                    case 1: //
//                        /*
//                         *  O O O O
//                         *  4 3 O O
//                         *  O 1 2 O
//                         *  O O O O
//                        */



//                        break;
//                    case 2: //
//                        /*
//                         *  O O O O
//                         *  O O 4 O
//                         *  O 1 3 O
//                         *  O 2 O O
//                        */


//                        break;
//                    case 3: //
//                        /*
//                         *  O O O O
//                         *  O O O O
//                         *  2 1 O O
//                         *  O 3 4 O
//                        */



//                        break;
//                    default:
//                        break;
//                }
//                break;
//            case 5: //T
//                switch(spin){
//                    case 0: //
//                        /*
//                         *  O O O O
//                         *  O O O O
//                         *  3 1 4 O
//                         *  O 2 O O
//                        */


//                        break;
//                    case 1: //
//                        /*
//                         *  O O O O
//                         *  O 3 O O
//                         *  2 1 O O
//                         *  O 4 O O
//                        */


//                        break;
//                    case 2: //
//                        /*
//                         *  O O O O
//                         *  O 2 O O
//                         *  O 1 3 O
//                         *  O 4 O O
//                        */


//                        break;
//                    case 3: //
//                        /*
//                         *  O O O O
//                         *  O O O O
//                         *  4 1 2 O
//                         *  O 3 O O
//                        */


//                        break;
//                    default:
//                        break;
//                }
//                break;
//            case 6: //Z
//                switch(spin){
//                    case 0: //
//                        /*
//                         *  O O O O
//                         *  O 2 O O
//                         *  3 1 O O
//                         *  4 O O O
//                        */


//                        break;
//                    case 1: //
//                        /*
//                         *  O O O O
//                         *  4 3 O O
//                         *  O 1 2 O
//                         *  O O O O
//                        */


//                        break;
//                    case 2: //
//                        /*
//                         *  O O O O
//                         *  O O 4 O
//                         *  O 1 3 O
//                         *  O 2 O O
//                        */


//                        break;
//                    case 3: //
//                        /*
//                         *  O O O O
//                         *  O O O O
//                         *  2 1 O O
//                         *  O 3 4 O
//                        */

//                        break;
//                    default:
//                        break;
//                }
//                break;
//            default:
//                break;
//        }
    }
    }
}
void piece::moveLeft(){
    switch(type){
        case 0: //I
            switch(spin){
                case 0: // Vertical Left
                        /*
                         *  O 4 O O
                         *  O 3 O O
                         *  O 1 O O
                         *  O 2 O O
                        */



                    break;
                case 1: // Horizontal Lower
                        /*
                         *  O O O O
                         *  O O O O
                         *  2 1 3 4
                         *  O O O O
                        */


                    break;
                case 2: // Vertical Right
                        /*
                         *  O O 4 O
                         *  O O 3 O
                         *  O O 1 O
                         *  O O 2 O
                        */


                    break;
                case 3: // Horizontal Upper
                        /*
                         *  O O O O
                         *  2 1 3 4
                         *  O O O O
                         *  O O O O
                        */


                    break;
                default:
                    break;
            }
            break;
        case 1: //J
            switch(spin){
                case 0: //
                    /*
                     *  O 4 O O
                     *  O 3 O O
                     *  2 1 O O
                     *  O O O O
                    */


                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  O 1 3 4
                     *  O O O O
                    */


                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O 1 2 O
                     *  O 3 O O
                     *  O 4 O O
                    */

                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  4 3 1 O
                     *  O O 2 O
                     *  O O O O
                    */


                    break;
                default:
                    break;
            }
            break;
        case 2: //L
            switch(spin){
                case 0: //
                    /*
                     *  O 4 O O
                     *  O 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */


                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  O 1 3 4
                     *  O 2 O O
                    */


                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O 2 1 O
                     *  O O 3 O
                     *  O O 4 O
                    */


                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O 2 O
                     *  4 3 1 O
                     *  O O O O
                    */


                    break;
                default:
                    break;
            }
            break;
        case 3: //O


            break;
        case 4: //S
            switch(spin){
                    case 0: //
                    /*
                     *  O O O O
                     *  O 2 o O
                     *  3 1 o O
                     *  4 O O O
                    */

                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  4 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */



                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O O 4 O
                     *  O 1 3 O
                     *  O 2 O O
                    */


                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  2 1 O O
                     *  O 3 4 O
                    */



                    break;
                default:
                    break;
            }
            break;
        case 5: //T
            switch(spin){
                case 0: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  3 1 4 O
                     *  O 2 O O
                    */


                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O 3 O O
                     *  2 1 O O
                     *  O 4 O O
                    */


                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  O 1 3 O
                     *  O 4 O O
                    */


                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  4 1 2 O
                     *  O 3 O O
                    */


                    break;
                default:
                    break;
            }
            break;
        case 6: //Z
            switch(spin){
                case 0: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  3 1 O O
                     *  4 O O O
                    */


                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  4 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */


                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O O 4 O
                     *  O 1 3 O
                     *  O 2 O O
                    */


                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  2 1 O O
                     *  O 3 4 O
                    */

                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

}
void piece::moveRight(){
    switch(type){
        case 0: //I
            switch(spin){
                case 0: // Vertical Left
                        /*
                         *  O 4 O O
                         *  O 3 O O
                         *  O 1 O O
                         *  O 2 O O
                        */



                    break;
                case 1: // Horizontal Lower
                        /*
                         *  O O O O
                         *  O O O O
                         *  2 1 3 4
                         *  O O O O
                        */


                    break;
                case 2: // Vertical Right
                        /*
                         *  O O 4 O
                         *  O O 3 O
                         *  O O 1 O
                         *  O O 2 O
                        */


                    break;
                case 3: // Horizontal Upper
                        /*
                         *  O O O O
                         *  2 1 3 4
                         *  O O O O
                         *  O O O O
                        */


                    break;
                default:
                    break;
            }
            break;
        case 1: //J
            switch(spin){
                case 0: //
                    /*
                     *  O 4 O O
                     *  O 3 O O
                     *  2 1 O O
                     *  O O O O
                    */


                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  O 1 3 4
                     *  O O O O
                    */


                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O 1 2 O
                     *  O 3 O O
                     *  O 4 O O
                    */

                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  4 3 1 O
                     *  O O 2 O
                     *  O O O O
                    */


                    break;
                default:
                    break;
            }
            break;
        case 2: //L
            switch(spin){
                case 0: //
                    /*
                     *  O 4 O O
                     *  O 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */


                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  O 1 3 4
                     *  O 2 O O
                    */


                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O 2 1 O
                     *  O O 3 O
                     *  O O 4 O
                    */


                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O 2 O
                     *  4 3 1 O
                     *  O O O O
                    */


                    break;
                default:
                    break;
            }
            break;
        case 3: //O


            break;
        case 4: //S
            switch(spin){
                    case 0: //
                    /*
                     *  O O O O
                     *  O 2 o O
                     *  3 1 o O
                     *  4 O O O
                    */

                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  4 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */



                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O O 4 O
                     *  O 1 3 O
                     *  O 2 O O
                    */


                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  2 1 O O
                     *  O 3 4 O
                    */



                    break;
                default:
                    break;
            }
            break;
        case 5: //T
            switch(spin){
                case 0: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  3 1 4 O
                     *  O 2 O O
                    */


                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O 3 O O
                     *  2 1 O O
                     *  O 4 O O
                    */


                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  O 1 3 O
                     *  O 4 O O
                    */


                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  4 1 2 O
                     *  O 3 O O
                    */


                    break;
                default:
                    break;
            }
            break;
        case 6: //Z
            switch(spin){
                case 0: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  3 1 O O
                     *  4 O O O
                    */


                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  4 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */


                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O O 4 O
                     *  O 1 3 O
                     *  O 2 O O
                    */


                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  2 1 O O
                     *  O 3 4 O
                    */

                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

}
void piece::rotate(){
    if(spin == 3){
        spin = 0;
    } else {
        spin++;
    }
    debugger::log("Spin is now " + std::to_string(spin));
}
void piece::drop(){
    while(!checkLanded()){
        moveDown();
    }
}
void piece::unsetOccupied(){
    switch(type){
        case 0: //I
            switch(spin){
                case 0: // Vertical Left
                        /*
                         *  O 4 O O
                         *  O 3 O O
                         *  O 1 O O
                         *  O 2 O O
                        */

                        grid::setTileIsOccupied(x,y,false); //1
                        grid::setTileIsOccupied(x,y+1,false); //2
                        grid::setTileIsOccupied(x,y-1,false); //3
                        grid::setTileIsOccupied(x,y-2,false); //4

                    break;
                case 1: // Horizontal Lower
                        /*
                         *  O O O O
                         *  O O O O
                         *  2 1 3 4
                         *  O O O O
                        */

                        grid::setTileIsOccupied(x,y,false); //1
                        grid::setTileIsOccupied(x-1,y,false); //2
                        grid::setTileIsOccupied(x+1,y,false); //3
                        grid::setTileIsOccupied(x+2,y,false); //4

                    break;
                case 2: // Vertical Right
                        /*
                         *  O O 4 O
                         *  O O 3 O
                         *  O O 1 O
                         *  O O 2 O
                        */

                        grid::setTileIsOccupied(x+1,y,false); //1
                        grid::setTileIsOccupied(x+1,y+1,false); //2
                        grid::setTileIsOccupied(x+1,y-1,false); //3
                        grid::setTileIsOccupied(x+1,y-2,false); //4

                    break;
                case 3: // Horizontal Upper
                        /*
                         *  O O O O
                         *  2 1 3 4
                         *  O O O O
                         *  O O O O
                        */

                        grid::setTileIsOccupied(x,y-1,false); //1
                        grid::setTileIsOccupied(x-1,y-1,false); //2
                        grid::setTileIsOccupied(x+1,y-1,false); //3
                        grid::setTileIsOccupied(x+2,y-1,false); //4

                    break;
                default:
                    break;
            }
            break;
        case 1: //J
            switch(spin){
                case 0: //
                    /*
                     *  O 4 O O
                     *  O 3 O O
                     *  2 1 O O
                     *  O O O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x-1,y,false); //2
                    grid::setTileIsOccupied(x,y-1,false); //3
                    grid::setTileIsOccupied(x,y-2,false); //4

                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  O 1 3 4
                     *  O O O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x,y-1,false); //2
                    grid::setTileIsOccupied(x+1,y,false); //3
                    grid::setTileIsOccupied(x+2,y,false); //4

                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O 1 2 O
                     *  O 3 O O
                     *  O 4 O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x+1,y,false); //2
                    grid::setTileIsOccupied(x,y+1,false); //3
                    grid::setTileIsOccupied(x,y+2,false); //4

                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  4 3 1 O
                     *  O O 2 O
                     *  O O O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x-1,y,false); //2
                    grid::setTileIsOccupied(x-2,y,false); //3
                    grid::setTileIsOccupied(x,y+1,false); //4

                    break;
                default:
                    break;
            }
            break;
        case 2: //L
            switch(spin){
                case 0: //
                    /*
                     *  O 4 O O
                     *  O 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x+1,y,false); //2
                    grid::setTileIsOccupied(x,y-1,false); //3
                    grid::setTileIsOccupied(x,y-2,false); //4

                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O 1 3 4
                     *  O 2 O O
                     *  O O O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x,y+1,false); //2
                    grid::setTileIsOccupied(x+1,y,false); //3
                    grid::setTileIsOccupied(x+2,y,false); //4

                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  2 1 O O
                     *  O 3 O O
                     *  O 4 O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x-1,y,false); //2
                    grid::setTileIsOccupied(x,y+1,false); //3
                    grid::setTileIsOccupied(x,y+2,false); //4

                    break;
                case 3: //
                    /*
                     *  O O 2 O
                     *  4 3 1 O
                     *  O O O O
                     *  O O O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x,y-1,false); //2
                    grid::setTileIsOccupied(x-1,y,false); //3
                    grid::setTileIsOccupied(x-2,y,false); //4

                    break;
                default:
                    break;
            }
            break;
        case 3: //O

                //Spin doesn't make a diference lol
                grid::setTileIsOccupied(x,y,false);
                grid::setTileIsOccupied(x+1,y,false);
                grid::setTileIsOccupied(x,y+1,false);
                grid::setTileIsOccupied(x+1,y+1,false);

            break;
        case 4: //S
            switch(spin){
                    case 0: //
                    /*
                     *  O O O O
                     *  O 2 o O
                     *  3 1 o O
                     *  4 O O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x,y-1,false); //2
                    grid::setTileIsOccupied(x-1,y,false); //3
                    grid::setTileIsOccupied(x-1,y+1,false); //4

                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  4 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x+1,y,false); //2
                    grid::setTileIsOccupied(x,y-1,false); //3
                    grid::setTileIsOccupied(x-1,y-1,false); //4


                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O O 4 O
                     *  O 1 3 O
                     *  O 2 O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x,y+1,false); //2
                    grid::setTileIsOccupied(x+1,y,false); //3
                    grid::setTileIsOccupied(x+1,y-1,false); //4

                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  2 1 O O
                     *  O 3 4 O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x-1,y,false); //2
                    grid::setTileIsOccupied(x,y+1,false); //3
                    grid::setTileIsOccupied(x+1,y+1,false); //4


                    break;
                default:
                    break;
            }
            break;
        case 5: //T
            switch(spin){
                case 0: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  3 1 4 O
                     *  O 2 O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x,y+1,false); //2
                    grid::setTileIsOccupied(x-1,y,false); //3
                    grid::setTileIsOccupied(x+1,y,false); //4

                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  O 3 O O
                     *  2 1 O O
                     *  O 4 O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x-1,y,false); //2
                    grid::setTileIsOccupied(x,y-1,false); //3
                    grid::setTileIsOccupied(x,y+1,false); //4

                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  4 1 3 O
                     *  O 4 O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x,y-1,false); //2
                    grid::setTileIsOccupied(x+1,y,false); //3
                    grid::setTileIsOccupied(x-1,y,false); //4

                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O 4 O O
                     *  O 1 2 O
                     *  O 3 O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x+1,y,false); //2
                    grid::setTileIsOccupied(x,y+1,false); //3
                    grid::setTileIsOccupied(x,y-1,false); //4

                    break;
                default:
                    break;
            }
            break;
        case 6: //Z
            switch(spin){
                case 0: //
                    /*
                     *  O O O O
                     *  O 2 O O
                     *  3 1 O O
                     *  4 O O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x,y-1,false); //2
                    grid::setTileIsOccupied(x-1,y,false); //3
                    grid::setTileIsOccupied(x-1,y+1,false); //4

                    break;
                case 1: //
                    /*
                     *  O O O O
                     *  4 3 O O
                     *  O 1 2 O
                     *  O O O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x+1,y,false); //2
                    grid::setTileIsOccupied(x,y-1,false); //3
                    grid::setTileIsOccupied(x-1,y-1,false); //4

                    break;
                case 2: //
                    /*
                     *  O O O O
                     *  O O 4 O
                     *  O 1 3 O
                     *  O 2 O O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x,y+1,false); //2
                    grid::setTileIsOccupied(x+1,y,false); //3
                    grid::setTileIsOccupied(x+1,y-1,false); //4

                    break;
                case 3: //
                    /*
                     *  O O O O
                     *  O O O O
                     *  2 1 O O
                     *  O 3 4 O
                    */

                    grid::setTileIsOccupied(x,y,false); //1
                    grid::setTileIsOccupied(x-1,y,false); //2
                    grid::setTileIsOccupied(x,y+1,false); //3
                    grid::setTileIsOccupied(x+1,y+1,false); //4

                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

