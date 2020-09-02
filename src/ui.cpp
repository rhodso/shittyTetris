//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include "ui.h"


//Constructor and Destructor
ui::ui(){}
ui::~ui(){ elementList.clear(); }

//Getters and Setters
std::vector<uiElement*> ui::getElementList(){ return elementList; }

void ui::setElementList( std::vector<uiElement*> _elementList){ elementList = _elementList; }

//Other methods
void ui::addToElementList(uiElement *_element){ elementList.push_back(_element); }
