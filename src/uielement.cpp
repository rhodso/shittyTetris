//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include "uielement.h"
#include "debugger.h"

//Class-only method
ofRectangle getBitmapStringBoundingBox(string _text);

//Constructor and Destructor
uiElement::uiElement(){}
uiElement::uiElement(int _x, int _y, int _l, int _h){
    x = _x;
    y = _y;
    l = _l;
    h = _h;
}
uiElement::uiElement(int _x, int _y, int _l, int _h, bool _alignLeft){
    x = _x;
    y = _y;
    l = _l;
    h = _h;
    alignLeft = _alignLeft;
}
uiElement::uiElement(int _x, int _y, int _l, int _h, bool _alignLeft, ofColor _bgColour, ofColor _textColour){
    x = _x;
    y = _y;
    l = _l;
    h = _h;
    alignLeft = _alignLeft;
    bgColour = _bgColour;
    textColour = _textColour;
}
uiElement::~uiElement(){}

//Getters and Setters
int uiElement::getX(){ return x; }
int uiElement::getY(){ return y; }
int uiElement::getL(){ return l; }
int uiElement::getH(){ return h; }
bool uiElement::getAlignLeft(){ return alignLeft; }
std::string uiElement::getText(){ return text; }
ofColor uiElement::getBgColour(){ return bgColour; }
ofColor uiElement::getTextColour(){ return textColour; }

void uiElement::setX( int _x){ x = _x; }
void uiElement::setY( int _y){ y = _y; }
void uiElement::setL( int _l){ l = _l; }
void uiElement::setH( int _h){ h = _h; }
void uiElement::setAlignLeft( bool _alignLeft ){ alignLeft = _alignLeft; }
void uiElement::setText( std::string _text){ text = _text; }
void uiElement::setBgColour( ofColor _bgColour){ bgColour = _bgColour; }
void uiElement::setTextColour( ofColor _textColour){ textColour = _textColour; }

//Other methods
void uiElement::draw(){
    //debugger::log("Entering draw for testElement");

    ofRectangle rect = getBitmapStringBoundingBox(text);
    //debugger::log("Got bounding box");
    rect.x = x;
    rect.y = y;
    ofSetColor(bgColour);
    if(!alignLeft){
        x -= l;
    }

    //debugger::log("Drawing rect");
    ofDrawRectangle(rect.x, rect.y, rect.width, rect.height);

    //debugger::log("Drawing text");
    ofSetColor(textColour);
    ofDrawBitmapString(text, rect.x, rect.y + 11);
}

//Stolen from https://forum.openframeworks.cc/t/how-to-get-size-of-ofdrawbitmapstring/22578/7
ofRectangle getBitmapStringBoundingBox(string _text){
    debugger::log("Entered getBitmapStringBoundingBox");
    vector<string> lines = ofSplitString(_text, "\n");
    int maxLineLength = 0;
    for(int i = 0; i < (int)lines.size(); i++) {
        // tabs are not rendered
        const string & line(lines[i]);
        int currentLineLength = 0;
        for(int j = 0; j < (int)line.size(); j++) {
            if (line[j] == '\t') {
                currentLineLength += 8 - (currentLineLength % 8);
            } else {
                currentLineLength++;
            }
        }
        maxLineLength = MAX(maxLineLength, currentLineLength);
    }

    int fontSize = 8;
    float leading = 1.7;
    int height = lines.size() * fontSize * leading - 1;
    int width = maxLineLength * fontSize;

    return ofRectangle(0,0,width, height);
}
