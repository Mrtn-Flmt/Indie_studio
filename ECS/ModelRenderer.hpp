//
// Created by tcampagne on 20/05/22.
//

#ifndef YEP_400_MODELRENDERER_H
#define YEP_400_MODELRENDERER_H

#include "Component.hpp"
#include "Entity.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include "../MyRaylib.hpp"

class ModelRenderer : public Component {
public:
    MyRaylib rayLib;
    ModelRenderer() = default;

    ModelRenderer(std::string pathDir) {
        char **filesDir;
        std::string namePNG;
        int count;
        if (rayLib.myDirectoryExists(pathDir.c_str())) {
            if (rayLib.myDirectoryExists((pathDir + "IQM/").c_str())) {
                filesDir = rayLib.myGetDirectoryFiles((pathDir + "IQM/").c_str(), &count);
                for (int i = 0; i < count; i++) {
                    if (IsFileExtension(filesDir[i], ".iqm"))
                        model = rayLib.myLoadModel((pathDir + "IQM/" + filesDir[i]).c_str());
                }
            } if (rayLib.myDirectoryExists((pathDir + "/PNG/").c_str())) {
                filesDir = rayLib.myGetDirectoryFiles((pathDir + "PNG/").c_str(), &count);
                for (int i = 0; i < count; i++) {
                    if (rayLib.myIsFileExtension(filesDir[i], ".png")) {
                        namePNG = filesDir[i];
                        textureID.push_back(std::stoi(namePNG.substr(0, namePNG.find_first_of("."))));
                        texture.push_back(rayLib.myLoadTexture((pathDir + "PNG/" + filesDir[i]).c_str()));
                    }
                }
            }
        }
        for(int i = 0; i != texture.size(); i++) {
            rayLib.mySetMaterialTexture(&model.materials[i], MATERIAL_MAP_DIFFUSE, texture[i]);
            rayLib.mySetModelMeshMaterial(&model, textureID[i], i);
        }
    }

    bool init() override final {
        transform = &entity->getComponent<TransformECS>();
        return true;
    }

    void draw() override final {
        rayLib.myDrawModelEx(model, transform->position, transform->rotation, -90.0f, transform->scale, WHITE);
    }

    void update() override final {
        transform = &entity->getComponent<TransformECS>();
    }

    virtual ~ModelRenderer() = default;

private:
    Model model;
    std::vector<int> textureID;
    std::vector<Texture2D> texture;
    TransformECS *transform = nullptr;
};

#endif //YEP_400_MODELRENDERER_H
