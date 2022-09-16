//
// Created by tcampagne on 03/06/22.
//

#ifndef YEP_400_ENTITYTRANSFORMPOSITIONTEXT_HPP
#define YEP_400_ENTITYTRANSFORMPOSITIONTEXT_HPP

class PositionText {
public:
    int getLastFirstPosEntitiesNameY() {return lastFirstPosEntitiesNameY;}
    void setLastFirstPosEntitiesNameY(int newLastFirstPosEntitiesNameY) {lastFirstPosEntitiesNameY = newLastFirstPosEntitiesNameY;}
    int getFirstPosEntitiesNameY() {return firstPosEntitiesNameY;}
    void setFirstPosEntitiesNameY(int newFirstPosEntitiesNameY) {firstPosEntitiesNameY = newFirstPosEntitiesNameY;}
    int getPosEntitiesNameY() {return posEntitiesNameY;}
    void setPosEntitiesNameY(int newPosEntitiesNameY) {posEntitiesNameY = newPosEntitiesNameY;}

private:
    int lastFirstPosEntitiesNameY = 37;
    int firstPosEntitiesNameY = 37;
    int posEntitiesNameY;
};

#endif //YEP_400_ENTITYTRANSFORMPOSITIONTEXT_HPP
