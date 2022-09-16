//
// Created by Demon on 08/05/2022.
//

#ifndef B_YEP_400_LIL_4_1_INDIESTUDIO_THIBAULT_CAMPAGNE_TRANSFORM_HPP
#define B_YEP_400_LIL_4_1_INDIESTUDIO_THIBAULT_CAMPAGNE_TRANSFORM_HPP

#include "Component.hpp"
#include "raylib.h"

class TransformECS : public Component {
    public:
        TransformECS(float x, float y, float z, float scx, float scy, float scz, float rx, float ry, float rz) {
            position.x = x;
            position.y = y;
            position.z = z;
            scale.x = scx;
            scale.y = scy;
            scale.z = scz;
            rotation.x = rx;
            rotation.y = ry;
            rotation.z = rz;
        }

        void TransformECSPosition(float x, float y, float z) {
            position.x = x;
            position.y = y;
            position.z = z;
        }

        void TransformECSScale(float x, float y, float z) {
            scale.x = x;
            scale.y = y;
            scale.z = z;
        }

        void TransformECSRotation(float x, float y, float z) {
            rotation.x = x;
            rotation.y = y;
            rotation.z = z;
        }

        virtual ~TransformECS() = default;

        Vector3 position;
        Vector3 scale;
        Vector3 rotation;
};

#endif //B_YEP_400_LIL_4_1_INDIESTUDIO_THIBAULT_CAMPAGNE_TRANSFORM_HPP
