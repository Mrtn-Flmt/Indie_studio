#ifndef GEOANIMATIONRENDERER_HPP_
#define GEOANIMATIONRENDERER_HPP_

#include "../MyRaylib.hpp"
#include <string>
#include <vector>
#include <array>
#include "Component.hpp"
#include "GeometricRenderer.hpp"

#define inner_wall_list std::vector<Vector3>{{6.0f, 0.0f, 5.0f}, {4.0f, 0.0f, 5.0f}, {2.0f, 0.0f, 5.0f}, {0.0f, 0.0f, 5.0f}, {-2.0f, 0.0f, 5.0f}, {-4.0f, 0.0f, 5.0f}, {-6.0f, 0.0f, 5.0f}, {6.0f, 0.0f, 3.0f}, {4.0f, 0.0f, 3.0f}, {2.0f, 0.0f, 3.0f}, {0.0f, 0.0f, 3.0f}, {-2.0f, 0.0f, 3.0f}, {-4.0f, 0.0f, 3.0f}, {-6.0f, 0.0f, 3.0f}, {6.0f, 0.0f, 1.0f}, {4.0f, 0.0f, 1.0f}, {2.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {-2.0f, 0.0f, 1.0f}, {-4.0f, 0.0f, 1.0f}, {-6.0f, 0.0f, 1.0f}, {6.0f, 0.0f, -1.0f}, {4.0f, 0.0f, -1.0f}, {2.0f, 0.0f, -1.0f}, {0.0f, 0.0f, -1.0f}, {-2.0f, 0.0f, -1.0f}, {-4.0f, 0.0f, -1.0f}, {-6.0f, 0.0f, -1.0f}, {6.0f, 0.0f, -3.0f}, {4.0f, 0.0f, -3.0f}, {2.0f, 0.0f, -3.0f}, {0.0f, 0.0f, -3.0f}, {-2.0f, 0.0f, -3.0f}, {-4.0f, 0.0f, -3.0f}, {-6.0f, 0.0f, -3.0f}, {6.0f, 0.0f, -5.0f}, {4.0f, 0.0f, -5.0f}, {2.0f, 0.0f, -5.0f}, {0.0f, 0.0f, -5.0f}, {-2.0f, 0.0f, -5.0f}, {-4.0f, 0.0f, -5.0f}, {-6.0f, 0.0f, -5.0f}}

class ExplosionRenderer : public Component {
    public:
        bool compareVector3WithList(Vector3 position)
        {
            for (auto pos : inner_wall_list)
                if (position.x == pos.x && position.z == pos.z)
                    return (true);
            return (false);
        }
        ExplosionRenderer(Vector3 position)
        {
            bool left, right, top, bot;

            origin_stage = new MapSphereRenderer(0.5, BLACK);
            stage_1 = new MapSphereRenderer(0.5, BLACK);
            stage_2 = new MapSphereRenderer(0.5, BLACK);
            stage_3 = new MapSphereRenderer(0.5, BLACK);
            stage_4 = new MapSphereRenderer(0.5, BLACK);
            origin_stage->addSphere(position);
            left = right = top = bot = true;

            if (position.x + 1.0f != 8.0f && !compareVector3WithList(Vector3{position.x + 1.0f, position.y, position.z}))
                stage_1->addSphere(Vector3{position.x + 1.0f, position.y, position.z});
            else
                left = false;
            if (left == true && position.x + 2.0f != 8.0f && !compareVector3WithList(Vector3{position.x + 2.0f, position.y, position.z}))
                stage_2->addSphere(Vector3{position.x + 2.0f, position.y, position.z});
            else
                left = false;
            if (left == true && position.x + 3.0f != 8.0f && !compareVector3WithList(Vector3{position.x + 3.0f, position.y, position.z}))
                stage_3->addSphere(Vector3{position.x + 3.0f, position.y, position.z});
            else
                left = false;
            if (left == true && position.x + 4.0f != 8.0f && !compareVector3WithList(Vector3{position.x + 4.0f, position.y, position.z}))
                stage_4->addSphere(Vector3{position.x + 4.0f, position.y, position.z});
            else
                left = false;
            
            if (position.x - 1.0f != -8.0f && !compareVector3WithList(Vector3{position.x - 1.0f, position.y, position.z}))
                stage_1->addSphere(Vector3{position.x - 1.0f, position.y, position.z});
            else
                right = false;
            if (right == true && position.x - 2.0f != -8.0f && !compareVector3WithList(Vector3{position.x - 2.0f, position.y, position.z}))
                stage_2->addSphere(Vector3{position.x - 2.0f, position.y, position.z});
            else
                right = false;
            if (right == true && position.x - 3.0f != -8.0f && !compareVector3WithList(Vector3{position.x - 3.0f, position.y, position.z}))
                stage_3->addSphere(Vector3{position.x - 3.0f, position.y, position.z});
            else
                right = false;
            if (right == true && position.x - 4.0f != -8.0f && !compareVector3WithList(Vector3{position.x - 4.0f, position.y, position.z}))
                stage_4->addSphere(Vector3{position.x - 4.0f, position.y, position.z});
            else
                right = false;

            if (position.z + 1.0f != 8.0f && !compareVector3WithList(Vector3{position.x, position.y, position.z + 1.0f}))
                stage_1->addSphere(Vector3{position.x, position.y, position.z + 1.0f});
            else
                top = false;
            if (top == true && position.z + 2.0f != 8.0f && !compareVector3WithList(Vector3{position.x, position.y, position.z + 2.0f}))
                stage_2->addSphere(Vector3{position.x, position.y, position.z + 2.0f});
            else
                top = false;
            if (top == true && position.z + 3.0f != 8.0f && !compareVector3WithList(Vector3{position.x, position.y, position.z + 3.0f}))
                stage_3->addSphere(Vector3{position.x, position.y, position.z + 3.0f});
            else
                top = false;
            if (top == true && position.z + 4.0f != 8.0f && !compareVector3WithList(Vector3{position.x, position.y, position.z + 4.0f}))
                stage_4->addSphere(Vector3{position.x, position.y, position.z + 4.0f});
            else
                top = false;

            if (position.z - 1.0f != -8.0f && !compareVector3WithList(Vector3{position.x, position.y, position.z - 1.0f}))
                stage_1->addSphere(Vector3{position.x, position.y, position.z - 1.0f});
            else
                bot = false;
            if (bot == true && position.z - 2.0f != -8.0f && !compareVector3WithList(Vector3{position.x, position.y, position.z - 2.0f}))
                stage_2->addSphere(Vector3{position.x, position.y, position.z - 2.0f});
            else
                bot = false;
            if (bot == true && position.z - 3.0f != -8.0f && !compareVector3WithList(Vector3{position.x, position.y, position.z - 3.0f}))
                stage_3->addSphere(Vector3{position.x, position.y, position.z - 3.0f});
            else
                bot = false;
            if (bot == true && position.z - 4.0f != -8.0f && !compareVector3WithList(Vector3{position.x, position.y, position.z - 4.0f}))
                stage_4->addSphere(Vector3{position.x, position.y, position.z - 4.0f});
            else
                bot = false;
        }
        ~ExplosionRenderer()
        {
            delete origin_stage;
            delete stage_1;
            delete stage_2;
            delete stage_3;
            delete stage_4;
        }
        void update() final
        {
            if (origin_stage->getRadius() > 0.0f)
                origin_stage->setRadius(origin_stage->getRadius() - 0.02f);
            if (stage_1->getRadius() > 0.0f && origin_stage->getRadius() < 0.4f)
                stage_1->setRadius(stage_1->getRadius() - 0.02f);
            if (stage_2->getRadius() > 0.0f && stage_1->getRadius() < 0.4f)
                stage_2->setRadius(stage_2->getRadius() - 0.02f);
            if (stage_3->getRadius() > 0.0f && stage_2->getRadius() < 0.4f)
                stage_3->setRadius(stage_3->getRadius() - 0.02f);
            if (stage_4->getRadius() > 0.0f && stage_3->getRadius() < 0.4f)
                stage_4->setRadius(stage_4->getRadius() - 0.02f);
        }
        void draw() final
        {
            origin_stage->draw();
            if (origin_stage->getRadius() < 0.4f)
                stage_1->draw();
            if (stage_1->getRadius() < 0.4f)
                stage_2->draw();
            if (stage_2->getRadius() < 0.4f)
                stage_3->draw();
            if (stage_3->getRadius() < 0.4f)
                stage_4->draw();
        }
        bool getState()
        {
            return (stage_4->getRadius() <= 0.0f);
        }
    private:
        MapSphereRenderer *origin_stage;
        MapSphereRenderer *stage_1;
        MapSphereRenderer *stage_2;
        MapSphereRenderer *stage_3;
        MapSphereRenderer *stage_4;
};

class BombRenderer : public Component {
    public:
        BombRenderer(Vector3 pos)
        {
            float x_plus, z_plus;
            float x_pos, z_pos;

            for (x_plus = -7.0f; x_plus < pos.x; x_plus += 1.0f);
            for (z_plus = -7.0f; z_plus < pos.z; z_plus += 1.0f);
            x_pos = (x_plus - pos.x <= 0.5f) ? x_plus : x_plus - 1.0f;
            z_pos = (z_plus - pos.z <= 0.5f) ? z_plus : z_plus - 1.0f;
            position = Vector3 {x_pos, 0.0f, z_pos};
            bomb = new SphereRenderer(position, 0.1, RED);
        }
        ~BombRenderer()
        {
            delete explosion;
        }
        void draw()
        {
            if (bomb != nullptr)
                bomb->draw();
            else
                explosion->draw();
        }
        void update()
        {
            if (bomb == nullptr)
                explosion->update();
            else {
                if (bomb->getRadius() != 0.5)
                    bomb->setRadius(bomb->getRadius() + 0.01f);
                if (bomb->getRadius() >= 0.5) {
                    delete bomb;
                    bomb = nullptr;
                    explosion = new ExplosionRenderer(position);
                }
            }
        }
        bool getState()
        {
            if (explosion != nullptr)
                return (explosion->getState());
            return (false);
        }
    private:
        Vector3 position;
        SphereRenderer *bomb;
        ExplosionRenderer *explosion = nullptr;
};

#endif /* !GEOANIMATIONRENDERER_HPP_ */
