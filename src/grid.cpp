#include "grid.h"
#include "debugger.h"
#include <thread>
#include <vector>

//Constructor
grid::grid(){}
grid::~grid(){
	//Clear the gameSpace to avoid memory leaks
	gameSpace.clear();
}


//Getters and setters
bool grid::getDoUpdate(){ return doUpdate; }
std::vector<std::vector<tile>> grid::getGameSpace(){ return gameSpace; }
int grid::getGH(){ return gH; }
int grid::getGW(){ return gW; }
int grid::getOffsetX(){ return offsetX; }
int grid::getOffsetY(){ return offsetY; }
ofColor grid::getLineColour(){ return lineColour; }

void grid::setDoUpdate( bool _doUpdate){ doUpdate = _doUpdate; }
void grid::setGameSpace( std::vector<std::vector<tile>> _gameSpace){ gameSpace = _gameSpace; }
void grid::setGH( int _gH){ gH = _gH; }
void grid::setGW( int _gW){ gW = _gW; }
void grid::setOffsetX( int _offsetX){ offsetX = _offsetX; }
void grid::setOffsetY( int _offsetY){ offsetY = _offsetY; }
void grid::setLineColour( ofColor _lineColour){ lineColour = _lineColour; }

//Methods to allow other classes to interface with the grid easily
void grid::setTileColour(int _x, int _y, ofColor _colour){ gameSpace[_x][_y].setColour(_colour); }
ofColor grid::getTileColour(int _x, int _y){ return gameSpace[_x][_y].getColour(); }
void grid::setTileIsOccupied(int _x, int _y, bool _isOccupied){ gameSpace[_x][_y].setIsOccupied(_isOccupied); }
bool grid::getTileIsOccupied(int _x, int _y){ return gameSpace[_x][_y].getIsOccupied(); }

//Other methods
void grid::createGrid(){
	//Log starting
	debugger::log("Creating new grid...");

	//Setting up the offset for the grid
	debugger::log("Setting vars");
	offsetX = (ofGetWidth()/2) - ((gW/2) * tile::getSize());
	offsetY = (ofGetHeight()/2) - ((gH/2) * tile::getSize());

	//Display vars
	std::string msg = "Height = "; msg += std::to_string(gH);
	debugger::log(msg);
	msg = "Width = "; msg += std::to_string(gW);
	debugger::log(msg);
	msg = "X offset = "; msg += std::to_string(offsetX);
	debugger::log(msg);
	msg = "Y offset = "; msg += std::to_string(offsetY);
	debugger::log(msg);
	msg = "Tile Size = "; msg += std::to_string(tile::getSize());
	debugger::log(msg);

	//Clear gameSpace
	gameSpace.clear();

	//Setup the tiles and add to gameSpace
    for(int i = 0; i < gW; i++){
		std::vector<tile> tmp;
        for(int j = 0; j < gH; j++){
			//Create tile and assign X/Y/black
            tile a = tile(((tile::getSize()*i) + offsetX), ((tile::getSize()*j) + offsetY), ofColor::black);
            a.setGridX(i);
            a.setGridY(j);

			//Push to back of tile queue
			tmp.push_back(a);
		}
		//Push completed "row" to back of tile vector
		gameSpace.push_back(tmp);
	}

	//Grid created, log
	debugger::log("Game created");
}

void grid::drawGrid(){
	//Tiles drawing setup
	ofFill();
	ofSetLineWidth(5);

	//Draw the tiles
    for(vector<tile> x : gameSpace){
        for(tile t : x){
            t.draw();
        }
    }

	//Lines drawing setup
	ofNoFill();
	ofSetLineWidth(5);
	ofSetColor(grid::getLineColour());
	float s = tile::getSize();

	//Draw the lines
	for(int i = 0; i < gH; i++){
		for(int j = 0; j < gW; j++){
			ofDrawRectangle(
						((s*j) + offsetX)-(s/2), //X
						((s*i) + offsetY)-(s/2), //Y
						s,    //Width
						s );  //Height
		}
	}
    ofFill();
}

void grid::drawGridDebug(){
    //Draw the tiles
    for(vector<tile> x : gameSpace){
        for(tile t : x){
            t.debugDraw();
        }
    }
}

void grid::resetGrid(){
    //This could be multithreaded if optimisations are needed
        for(int i = 0; i < gW; i++){
            for(int j = 0; j < gH; j++){
                setTileColour(i,j,ofColor::black);
            }
        }
}

void grid::setOccupied(){
    //For each tile, if the colour is black then set it to not occupied, if not, then it is
    for(vector<tile> x : gameSpace){
        for(tile t : x){
            t.setIsOccupied( t.getColour() != ofColor::black );
            //if(debugger::getDebug()){ t.debugDraw(); }
        }
    }

}

void grid::saveGrid(){
    for(vector<tile> x : gameSpace){
        for(tile t : x){ //For each tile in gameSpace
            if(t.getColour() != ofColor::black){ //If the colour isn't black
                tileList.push_back(t); //Add to list
            }
        }
    }
}

void grid::restoreGrid(){
    //For each tile, restore to the grid
    for(tile t : tileList){
        setTileColour(t.getGridX(), t.getGridY(), t.getColour());
    }
    //Emptry list from previous frame
    tileList.clear();

}
