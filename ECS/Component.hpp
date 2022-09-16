//
// Created by Demon on 08/05/2022.
//

#ifndef B_YEP_400_LIL_4_1_INDIESTUDIO_THIBAULT_CAMPAGNE_COMPONENT_HPP
#define B_YEP_400_LIL_4_1_INDIESTUDIO_THIBAULT_CAMPAGNE_COMPONENT_HPP

class Entity;

class Component {
    public:
        Component() = default;
        virtual ~Component()  = default;

        Entity *entity;

        virtual bool init() {return true;}
        virtual void draw() {}
        virtual void update() {}
};

#endif //B_YEP_400_LIL_4_1_INDIESTUDIO_THIBAULT_CAMPAGNE_COMPONENT_HPP
