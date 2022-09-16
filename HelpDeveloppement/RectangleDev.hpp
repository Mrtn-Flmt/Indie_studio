//
// Created by tcampagne on 03/06/22.
//

#ifndef YEP_400_RECTANGLE_HPP
#define YEP_400_RECTANGLE_HPP

#include "../MyRaylib.hpp"
#include "Text.hpp"

class RectangleDev{
public:
    std::vector<Rectangle> getTransform() {return transform;}
    void setTransform(std::vector<Rectangle> newTransform) {transform = newTransform;}
    std::vector<Rectangle> getRectangleEntitySelected() {return rectangleEntitySelected;}
    void setRectangleEntitySelected(std::vector<Rectangle> newRectangleSelected) {rectangleEntitySelected = newRectangleSelected;}
    Rectangle getScissorArea() {return scissorArea;}
    void setScissorArea(Rectangle newScissorArea) {scissorArea = newScissorArea;}
    Rectangle getRectangleEntity() {return rectangleEntity;}
    void setRectangleEntity(Rectangle newRectangleEntity) {rectangleEntity = newRectangleEntity;}

private:
    Rectangle scissorArea = {1590, 30, 300, 170};
    Rectangle rectangleEntity = {1590, 5, 300, 30};
    std::vector<Rectangle> transform;
    std::vector<Rectangle> rectangleEntitySelected;
};

#endif //YEP_400_RECTANGLE_HPP
