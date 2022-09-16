#ifndef YEP_400_SPRITERENDERER_HPP
#define YEP_400_SPRITERENDERER_HPP

#include "../MyRaylib.hpp"
#include <string>
#include <vector>
#include "Component.hpp"

class SpriteRenderer : public Component {
    public:
        SpriteRenderer() = default;

        SpriteRenderer(std::string pathImage, Vector2 Resize) {
            if (Resize.x < 0)
                LoadSpriteRenderer(pathImage);
            else
                LoadSpriteRendererResize(pathImage, Resize);
        }

        bool init() final {
            return true;
        }

        void draw() override {
            DrawTexture(texture, DrawPosition.x, DrawPosition.y, WHITE);
        }

        Vector2 getDrawPosition() {return (DrawPosition);}

        void SetDrawPosition(Vector2 newDrawPosition) {DrawPosition = newDrawPosition;}

        void LoadSpriteRenderer(std::string pathImage) {
            image = LoadImage(pathImage.c_str());
            texture = LoadTextureFromImage(image);
        }

        void LoadSpriteRendererResize(std::string pathImage, Vector2 Resize) {
            image = LoadImage(pathImage.c_str());
            ImageResize(&image, Resize.x, Resize.y);
            texture = LoadTextureFromImage(image);

        }

        virtual ~SpriteRenderer() = default;
    protected:
        Image image;
        Texture2D texture;
        Vector2 DrawPosition;
        Vector2 ResizeImage;
};

// class SpriteRenderer3D : public Component {
//     public:
//         SpriteRenderer3D() = default;

//         SpriteRenderer3D(std::string pathImage, Vector2 Resize) {
//             if (Resize.x < 0)
//                 LoadSpriteRenderer3D(pathImage);
//             else
//                 LoadSpriteRendererResize3D(pathImage, Resize);
//         }

//         bool init() final {
//             return true;
//         }

//         void draw() final {
//             DrawTexture(texture3D, DrawPosition3D.x, DrawPosition3D.y, WHITE);
//         }

//         Vector3 getDrawPosition() {return (DrawPosition3D);}

//         void SetDrawPosition3D(Vector3 newDrawPosition3D) {DrawPosition3D = newDrawPosition3D;}

//         void LoadSpriteRenderer3D(std::string pathImage) {
//             image3D = LoadImage(pathImage.c_str());
//             texture3D = LoadTextureFromImage(image3D);
//         }

//         void LoadSpriteRendererResize3D(std::string pathImage, Vector2 Resize) {
//             image3D = LoadImage(pathImage.c_str());
//             ImageResize(&image3D, Resize.x, Resize.y);
//             texture3D = LoadTextureFromImage(image3D);

//         }

//         virtual ~SpriteRenderer3D() = default;
//     private:
//         Image image3D;
//         Texture2D texture3D;
//         Vector2 ResizeImage3D;
//         Vector3 DrawPosition3D;
// };

#endif //YEP_400_SPRITERENDERER_HPP
