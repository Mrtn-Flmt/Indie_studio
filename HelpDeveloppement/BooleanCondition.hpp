//
// Created by tcampagne on 03/06/22.
//

#ifndef YEP_400_BOOLEAN_HPP
#define YEP_400_BOOLEAN_HPP

class boolCondition {
public:
    bool getEntitySelected() {return entitySelected;}
    void setEntitySelected(bool newEntitySelected) {entitySelected = newEntitySelected;}
    bool getMouseOnTextEntity() {return mouseOnTextEntity;}
    void setMouseOnTextEntity(bool newMouseOnTextEntity) {mouseOnTextEntity = newMouseOnTextEntity;}
    bool getScissorMode() {return scissorMode;}
    void setScissorMode(bool newScissorMode) {scissorMode = newScissorMode;}
    bool getMouseOnText() {return mouseOnText;}
    void setMouseOnText(bool newMouseOnText) {mouseOnText = newMouseOnText;}
    bool getKeepMouseOnTextEntity() {return keepMouseOnTextEntity;}
    void setKeepMouseOnTextEntity(bool newKeepMouseOnTextEntity) {keepMouseOnTextEntity = newKeepMouseOnTextEntity;}
    bool getNegative() {return negative;}
    void setNegative(bool newNegative) {negative = newNegative;}

private:
    bool scissorMode = false;
    bool entitySelected = false;
    bool mouseOnText = false;
    bool mouseOnTextEntity = false;
    bool keepMouseOnTextEntity = false;
    bool negative = false;
};

#endif //YEP_400_BOOLEAN_HPP
