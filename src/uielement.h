//Header file auto-generated using CPP-Getter-Setter-Generator
#ifndef UIELEMENT_H
#define UIELEMENT_H

//Includes
#include "ofMain.h"
#include "grid.h"
#include "ofMain.h"
#include <string>

class uiElement {
    public:
        //Constructor and Destructor
        uiElement();
        uiElement(int _x, int _y, int _l, int _h);
        uiElement(int _x, int _y, int _l, int _h, bool _alignLeft);
        uiElement(int _x, int _y, int _l, int _h, bool _alignLeft, ofColor _bgColour, ofColor _textColour);
        ~uiElement();

        //Getters and Setters
        int getX();
        int getY();
        int getL();
        int getH();
        bool getAlignLeft();
        std::string getText();
        ofColor getBgColour();
        ofColor getTextColour();

        void setX( int _x );
        void setY( int _y );
        void setL( int _l );
        void setH( int _h );
        void setAlignLeft( bool _alignLeft );
        void setText( std::string _text );
        void setBgColour( ofColor _bgColour );
        void setTextColour( ofColor _textColour );

        //Other methods
        void draw();

    private:
        //Variables
        int x; //Top left x
        int y; //Top left y
        int l; //Length
        int h; //Height
        bool alignLeft;
        std::string text;
        ofColor bgColour;
        ofColor textColour;

};
#endif
