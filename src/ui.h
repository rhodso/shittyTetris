//Header file auto-generated using CPP-Getter-Setter-Generator
#ifndef UI_H
#define UI_H

//Includes
#include "uielement.h"
#include <vector>

class ui {
    public:
        //Constructor and Destructor
        ui();
        ~ui();

        //Getters and Setters
        std::vector<uiElement*> getElementList();

        void setElementList( std::vector<uiElement*> _elementList );

        //Other methods
        void addToElementList(uiElement* _element);

    private:
        //Variables
        std::vector<uiElement*> elementList;

};
#endif
