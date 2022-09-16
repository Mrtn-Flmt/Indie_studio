#ifndef GEOMETRICRENDERER_HPP_
#define GEOMETRICRENDERER_HPP_

#include "../MyRaylib.hpp"
#include <string>
#include <vector>
#include <array>
#include "Component.hpp"

class RectangleRenderer : public Component {
    public:
        RectangleRenderer(int posX, int posY, int width, int height, Color color)
        {
            this->posX = posX;
            this->posY = posY;
            this->width = width;
            this->height = height;
            this->color = color;
        }
        RectangleRenderer(int width, int height, Color color)
        {
            this->width = width;
            this->height = height;
            this->color = color;
        }
        ~RectangleRenderer() = default;
        void draw() override
        {
            DrawRectangle(posX, posY, width, height, color);
        }
    protected:
        int posX;
        int posY;
        int width;
        int height;
        Color color;
};

class MapRectangleRenderer : public RectangleRenderer {
    public:
        MapRectangleRenderer(int width, int height, Color color) :
            RectangleRenderer(width, height, color) {}
        ~MapRectangleRenderer() = default;
        void addRectangle(Vector2 position)
        {
            positions.push_back(position);
        }
        void draw() final
        {
            for (auto pos : positions)
                DrawRectangle(pos.x, pos.y, width, height, color);
        }
    private:
        std::vector<Vector2> positions;
};

class CubeRenderer : public Component {
    public:
        CubeRenderer(Vector3 position, float width, float height, float length, Color color)
        {
            this->position = position;
            this->width = width;
            this->height = height;
            this->length = length;
            this->color = color;
        }
        CubeRenderer(float width, float height, float length, Color color)
        {
            this->width = width;
            this->height = height;
            this->length = length;
            this->color = color;
        }
        ~CubeRenderer() = default;
        void setOutline(bool outline, Color outlineColor)
        {
            this->outline = outline;
            this->outlineColor = outlineColor;
        }
        void draw() override
        {
            DrawCube(position, width, height, length, color);
            if (outline)
                DrawCubeWires(position, width, height, length, outlineColor);
        }
    protected:
        Vector3 position;
        float width;
        float height;
        float length;
        Color color;
        bool outline;
        Color outlineColor;
};

class MapCubeRenderer : public CubeRenderer {
    public:
        MapCubeRenderer(float width, float height, float length, Color color) :
            CubeRenderer(width, height, length, color) {}
        ~MapCubeRenderer() = default;
        void addCube(Vector3 position)
        {
            positions.push_back(position);
        }
        void draw() final
        {
            for (auto pos : positions) {
                DrawCube(pos, width, height, length, color);
                if (outline)
                    DrawCubeWires(pos, width, height, length, outlineColor);
            }
        }
    private:
        std::vector<Vector3> positions;
};

class CubeWiresRenderer : public Component {
    public:
        CubeWiresRenderer(Vector3 position, float width, float height, float length, Color color)
        {
            this->position = position;
            this->width = width;
            this->height = height;
            this->length = length;
            this->color = color;
        }
        ~CubeWiresRenderer() = default;
        void draw()
        {
            DrawCubeWires(position, width, height, length, color);
        }
    private:
        Vector3 position;
        float width;
        float height;
        float length;
        Color color;
};

class SphereRenderer : public Component {
    public:
        SphereRenderer(float radius, Color color)
        {
            this->radius = radius;
            this->color = color;
            outline = false;
        }
        SphereRenderer(Vector3 position, float radius, Color color)
        {
            this->position = position;
            this->radius = radius;
            this->color = color;
            outline = false;
        }
        ~SphereRenderer() = default;
        void draw() override
        {
            DrawSphere(position, radius, color);
            if (outline)
                DrawSphereWires(position, radius, outlineRing, outlineSlices, outlineColor);
        }
        void setOutline(bool outline, int outlineRing, int outlineSlices, Color outlineColor)
        {
            this->outline = outline;
            this->outlineRing = outlineRing;
            this->outlineSlices = outlineSlices;
            this->outlineColor = outlineColor;
        }
        void setRadius(float rad)
        {
            radius = rad;
        }
        void setPosition(Vector3 pos)
        {
            position = pos;
        }
        void setColor(Color color)
        {
            this->color = color;
        }
        float getRadius()
        {
            return (radius);
        }
    protected:
        Vector3 position;
        float radius;
        Color color;
        bool outline;
        int outlineRing;
        int outlineSlices;
        Color outlineColor;
};

class MapSphereRenderer : public SphereRenderer {
    public:
        MapSphereRenderer(float radius, Color color) :
            SphereRenderer(radius, color) {}
        ~MapSphereRenderer() = default;
        void draw() final
        {
            for (auto pos : positions) {
                DrawSphere(pos, radius, color);
                if (outline)
                    DrawSphereWires(pos, radius, outlineRing, outlineSlices, outlineColor);
            }
        }
        void addSphere(Vector3 position)
        {
            positions.push_back(position);
        }
    private:
        std::vector<Vector3> positions;
};

class GridRenderer : public Component {
    public:
        GridRenderer(int slices, float spacing)
        {
            this->slices = slices;
            this->spacing = spacing;
        }
        ~GridRenderer() = default;
        void draw()
        {
            DrawGrid(slices, spacing);
        }
    private:
        int slices;
        float spacing;
};

#endif /* !GEOMETRICRENDERER_HPP_ */
