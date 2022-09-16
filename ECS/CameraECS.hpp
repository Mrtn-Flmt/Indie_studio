//
// Created by tcampagne on 06/06/22.
//

#ifndef YEP_400_CAMERACOMP_HPP
#define YEP_400_CAMERACOMP_HPP

#include "Component.hpp"
#include "Entity.hpp"
#include "../MyRaylib.hpp"

class CameraECS : public Component {
    public:
        CameraECS() {
            camera.projection = CAMERA_PERSPECTIVE;
            camera.up = Vector3 {0.0f, 0.1f, 0.0f};
            camera.fovy = 45.0f;
            camera.target = Vector3 {6.0f, 40.0f, -180.0f};
            camera.position = Vector3 {-4.0f, 30.0f, 202.0f};
            rayLib.mySetCameraMode(camera, CAMERA_CUSTOM);
            updating = true;
        }
        virtual ~CameraECS() = default;

        bool init() override final {
            &entity->getComponent<TransformECS>();
            return true;
        }

        void draw() override final {}

        void update() override final {
            rayLib.myUpdateCamera(&camera);
            if (updating) {
                if (camera.position.z != -40 )
                    camera.position.z -= 0.5f;
            }
        }
        void setGameplayOptions()
        {
            camera.target = Vector3 {0.0f, 0.0f, 0.0f};
            camera.position = Vector3 {0.0f, 20.0f, -1.0f};
            rayLib.myUpdateCamera(&camera);
            updating = false;
        }
        void setMenuOptions()
        {
            camera.target = Vector3 {6.0f, 40.0f, -180.0f};
            camera.position = Vector3 {-4.0f, 30.0f, 202.0f};
            rayLib.myUpdateCamera(&camera);
            updating = true;
        }
        void dump()
        {
            std::cout << camera.position.x << " " << camera.position.y << " " << camera.position.z << std::endl;
            std::cout << camera.target.x << " " << camera.target.y << " " << camera.target.z << std::endl;
            std::cout << updating << std::endl;
        }

        Camera3D getCamera() {return camera;}
        void setCamera(Camera3D newCamera) {camera = newCamera;}
        TransformECS *setTransform() {return transform;}
        void setTransform(TransformECS *newTranform) {transform = newTranform;}
        bool updating;

    private:
        Camera3D camera;
        MyRaylib rayLib;
        TransformECS *transform = nullptr;
};

#endif //YEP_400_CAMERACOMP_HPP
