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

    int trgX = 0;
    int trgY = 0;

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

                            trgX = x;
                            trgY = y + 3;

                            if(grid::getTileColour(trgX, trgY) != ofColor::black){
                                y++;
                            }

                        break;
                    case 1: // Horizontal Lower
                            /*
                             *  O O O O
                             *  O O O O
                             *  2 1 3 4
                             *  O O O O
                            */

                            if(grid::getTileColour(x, y--) != ofColor::black){
                                if(grid::getTileColour(x--, y--) != ofColor::black){
                                    if(grid::getTileColour(x++, y--) != ofColor::black){
                                        if(grid::getTileColour(x -= 2, y--) != ofColor::black){
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

                            trgX = x;
                            trgY = y + 3;

                            if(grid::getTileColour(trgX, trgY) != ofColor::black){
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

                            if(grid::getTileColour(x, y--) != ofColor::black){
                                if(grid::getTileColour(x--, y--) != ofColor::black){
                                    if(grid::getTileColour(x++, y--) != ofColor::black){
                                        if(grid::getTileColour(x -= 2, y--) != ofColor::black){
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

