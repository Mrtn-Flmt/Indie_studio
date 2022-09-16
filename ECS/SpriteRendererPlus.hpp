#ifndef GRIDRENDERER_HPP_
#define GRIDRENDERER_HPP_

#include "../MyRaylib.hpp"
#include <string>
#include <vector>
#include <array>
#include "SpriteRenderer.hpp"

class MapSpriteRenderer : public SpriteRenderer {
    public:
        MapSpriteRenderer() = default;
        MapSpriteRenderer(std::string pathImage, Vector2 Resize) : SpriteRenderer(pathImage, Resize) {}
        ~MapSpriteRenderer() = default;
        void addPosition(int x, int y)
        {
            Vector2 position;

            position.x = x;
            position.y = y;
            positions.push_back(position);
        }
        void draw() final
        {
            for (auto position : positions)
                DrawTexture(texture, position.x, position.y, WHITE);
        }
    private:
        std::vector<Vector2> positions;
};

class AnimatedSpriteRenderer : public SpriteRenderer {
    public:
        AnimatedSpriteRenderer() = default;
        AnimatedSpriteRenderer(std::string pathImage, Vector2 Resize) : SpriteRenderer(pathImage, Resize) {}
        ~AnimatedSpriteRenderer() = default;
        void addPhaseInAnimation(int x, int y, int height, int width)
        {
            std::array<int, 2> position;
            std::array<int, 2> size;

            position[0] = x;
            position[1] = y;
            size[0] = height;
            size[1] = width;
            positions.push_back(position);
            sizes.push_back(size);
        }
    private:
        std::vector<std::array<int, 2>> positions;
        std::vector<std::array<int, 2>> sizes;
};

#endif /* !GRIDRENDERER_HPP_ */
