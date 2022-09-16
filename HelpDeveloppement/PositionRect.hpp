//
// Created by tcampagne on 03/06/22.
//

#ifndef YEP_400_ENTITYTRANSFORMPOSITIONRECT_HPP
#define YEP_400_ENTITYTRANSFORMPOSITIONRECT_HPP

class PositionRect {
public:
    int getPosEntitiesRect() {return posEntitiesRect;}
    void setPosEntitiesRect(int newPos) {posEntitiesRect = newPos;}
    int getFirstPosEntitiesRect() {return firstPosEntitiesRect;}
    void setFirstPosEntitiesRect(int newFirstPosEntitiesRect) {firstPosEntitiesRect = newFirstPosEntitiesRect;}
    int getLastFirstPosEntitiesRect() {return lastFirstPosEntitiesRect;}
    void setLastFirstPosEntitiesRect(int newLastFirstPosEntitiesRect) {lastFirstPosEntitiesRect = newLastFirstPosEntitiesRect;}
private:
    int lastFirstPosEntitiesRect = 35;
    int firstPosEntitiesRect = 35;
    int posEntitiesRect = firstPosEntitiesRect;
};

#endif //YEP_400_ENTITYTRANSFORMPOSITIONRECT_HPP
