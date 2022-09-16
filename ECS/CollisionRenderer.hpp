#ifndef COLLISIONRENDERER_HPP_
#define COLLISIONRENDERER_HPP_

#include "../MyRaylib.hpp"
#include <string>
#include <vector>
#include <array>

enum direction {
    UP,
    DOWN,
    RIGHT,
    LEFT
};

class CollisionRenderer {
    public:
        CollisionRenderer() = default;
        ~CollisionRenderer() = default;
        void newCollider(Vector3 pos, Vector3 size)
        {
            positions.push_back(pos);
            sizes.push_back(size);
        }
        bool collision(Vector3 pos, Vector3 size, direction direc)
        {
            std::vector<Vector3>::iterator it_pos;
            std::vector<Vector3>::iterator it_size;
            float object_top_collider = pos.z + (size.z / 2);
            float object_bot_collider = pos.z - (size.z / 2);
            float object_left_collider = pos.x + (size.x / 2);
            float object_right_collider = pos.x - (size.x / 2);
            float it_top_collider;
            float it_bot_collider;
            float it_left_collider;
            float it_right_collider;

            for (it_pos = std::begin(positions), it_size = std::begin(sizes);
                it_pos != std::end(positions); it_pos++, it_size++) {
                it_top_collider = it_pos->z + (it_size->z / 2);
                it_bot_collider = it_pos->z - (it_size->z / 2);
                it_left_collider = it_pos->x + (it_size->x / 2);
                it_right_collider = it_pos->x - (it_size->x / 2);
                if (direc == UP)
                    if (object_top_collider >= it_bot_collider &&
                        object_bot_collider < it_bot_collider) {
                        if (object_left_collider > it_right_collider &&
                            object_left_collider < it_left_collider) {
                            return (true);
                        }
                        if (object_right_collider < it_left_collider &&
                            object_right_collider > it_right_collider) {
                            return (true);
                        }
                    }
                if (direc == DOWN)
                    if (object_bot_collider <= it_top_collider &&
                        object_top_collider > it_top_collider) {
                        if (object_left_collider > it_right_collider &&
                            object_left_collider < it_left_collider) {
                            return (true);
                        }
                        if (object_right_collider < it_left_collider &&
                            object_right_collider > it_right_collider) {
                            return (true);
                        }
                    }
                if (direc == LEFT)
                    if (object_left_collider >= it_right_collider &&
                        object_right_collider < it_right_collider) {
                        if (object_bot_collider < it_top_collider &&
                            object_bot_collider > it_bot_collider) {
                            return (true);
                        }
                        if (object_top_collider > it_bot_collider &&
                            object_top_collider < it_top_collider) {
                            return (true);
                        }
                    }
                if (direc == RIGHT)
                    if (object_right_collider <= it_left_collider &&
                        object_left_collider > it_left_collider) {
                        if (object_top_collider > it_bot_collider &&
                            object_top_collider < it_top_collider) {
                            return (true);
                        }
                        if (object_bot_collider < it_top_collider &&
                            object_bot_collider > it_bot_collider) {
                            return (true);
                        }
                    }
            }
            return (false);
        }
        void dump()
        {
            std::vector<Vector3>::iterator it_pos;
            std::vector<Vector3>::iterator it_size;

            for (it_pos = std::begin(positions), it_size = std::begin(sizes); it_pos != std::end(positions); it_pos++, it_size++)
                std::cout << "collider :\n\tpositions : " << it_pos->x << ", " << it_pos->y << ", " << it_pos->z << "\n\tsize : " << it_size->x << ", " << it_size->y << ", " << it_size->z << std::endl;
        }
    private:
        std::vector<Vector3> positions;
        std::vector<Vector3> sizes;
};

#endif /* !COLLISIONRENDERER_HPP_ */
