#ifndef PLAYERCOMPONENT_HPP_
#define PLAYERCOMPONENT_HPP_

#include "../MyRaylib.hpp"
#include <string>
#include <vector>
#include <array>
#include "Component.hpp"
#include "CollisionRenderer.hpp"
#include "GeoAnimationRenderer.hpp"

enum BombState {
    PUT,
    EXPLODING,
    FINISHED
};

class PlayerComponent : public Component {
    public:
        PlayerComponent(Vector3 pos, std::vector<KeyboardKey> keys)
        {
            position = pos;
            player = new SphereRenderer(pos, 0.4f, YELLOW);
            player->setOutline(true, 16, 16, GREEN);
            keyUp = keys[0];
            keyDown = keys[1];
            keyRight = keys[2];
            keyLeft = keys[3];
            keyBomb = keys[4];
        }
        ~PlayerComponent()
        {
            delete player;
        }
        void draw()
        {
            player->setPosition(position);
            player->draw();
            if (bomb != nullptr)
                bomb->draw();
        }
        void update()
        {
            float x, z;

            if (movingUp && (!IsKeyDown(keyUp) || position.z >= 6.0f))
                movingUp = false;
            if (movingDown && (!IsKeyDown(keyDown) || position.z <= -6.0f))
                movingDown = false;
            if (movingLeft && (!IsKeyDown(keyLeft) || position.x >= 7.0f))
                movingLeft = false;
            if (movingRight && (!IsKeyDown(keyRight) || position.x <= -7.0f))
                movingRight = false;
            if (IsKeyDown(keyUp) && position.z < 6.1f)
                movingUp = true;
            if (IsKeyDown(keyDown) && position.z > -6.1f)
                movingDown = true;
            if (IsKeyDown(keyLeft) && position.x < 7.1f)
                movingLeft = true;
            if (IsKeyDown(keyRight) && position.x > -7.1f)
                movingRight = true;
            if (IsKeyPressed(keyBomb) && bomb == nullptr)
                bomb = new BombRenderer(position);
            if (movingUp && colliders->collision(position, Vector3 {0.8f, 0.8f, 0.8f}, UP))
                movingUp = false;
            if (movingUp)
                position = Vector3 {position.x, position.y, position.z + 0.1f};
            if (movingDown && colliders->collision(position, Vector3 {0.8f, 0.8f, 0.8f}, DOWN))
                movingDown = false;
            if (movingDown)
                position = Vector3 {position.x, position.y, position.z - 0.1f};
            if (movingLeft && colliders->collision(position, Vector3 {0.8f, 0.8f, 0.8f}, LEFT))
                movingLeft = false;
            if (movingLeft)
                position = Vector3 {position.x + 0.1f, position.y, position.z};
            if (movingRight && colliders->collision(position, Vector3 {0.8f, 0.8f, 0.8f}, RIGHT))
                movingRight = false;
            if (movingRight)
                position = Vector3 {position.x - 0.1f, position.y, position.z};
            if (bomb != nullptr && bomb->getState()) {
                delete bomb;
                bomb = nullptr;
            }
            if (bomb != nullptr)
                bomb->update();
        }
        void setColliders(CollisionRenderer *colliders)
        {
            this->colliders = colliders;
        }
        void setPlayerColor(Color color)
        {
            player->setColor(color);
        }
    private:
        Vector3 position;
        bool movingUp = false;
        bool movingDown = false;
        bool movingRight = false;
        bool movingLeft = false;
        KeyboardKey keyUp;
        KeyboardKey keyDown;
        KeyboardKey keyRight;
        KeyboardKey keyLeft;
        KeyboardKey keyBomb;
        BombRenderer *bomb = nullptr;
        SphereRenderer *player;
        CollisionRenderer *colliders;
};

#endif /* !PLAYERCOMPONENT_HPP_ */