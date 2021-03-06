#ifndef TILE_H
#define TILE_H

#include "ofMain.h"

class tile{
public:
	//Constructors and destructors
	tile();
	tile(float _x, float _y);
	tile(float _x, float _y, ofColor _c);
	~tile();

	//Getters and setters
	float getX();
	float getY();
	float getGridX();
	float getGridY();
	ofColor getColour();
	static float getSize();
    bool getIsOccupied();

	void setX( float _x );
	void setY( float _y );
	void setGridX( float _gridX);
	void setGridY( float _gridY);
	static void setSize( float _size );
	void setColour( ofColor _colour );
    void setIsOccupied( bool _isOccupied);

	//Draw the tile
	void draw();
    void debugDraw();

private:

	//Actual X/Y on the screen
	float x;
	float y;

	//X/Y position in the grid
	float gridX;
	float gridY;

	//Colour
	ofColor colour;

	//Size
	inline static float size = 30;

    bool isOccupied;

};

#endif // TILE_H
