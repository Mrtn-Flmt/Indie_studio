//
// Created by Demon on 09/05/2022.
//

#ifndef B_YEP_400_LIL_4_1_INDIESTUDIO_THIBAULT_CAMPAGNE_ENTITYMANAGER_HPP
#define B_YEP_400_LIL_4_1_INDIESTUDIO_THIBAULT_CAMPAGNE_ENTITYMANAGER_HPP

#include <vector>
#include <memory>
#include <string>
#include "../MyRaylib.hpp"

class Entity;

class EntityManager {
public:
    EntityManager() = default;
    ~EntityManager() = default;

    void draw();
    void update();
    void refresh();

    Camera3D getEntityCamera();
    void stockEntitiesName();

    void addEntity(Entity *entity);
    void eraseEntity(Entity *entity);
    Entity *cloneEntity(Entity *entity);

    std::vector<std::string> storageOfEntitiesName;
    std::vector<std::unique_ptr<Entity>> entities;
};

#endif //B_YEP_400_LIL_4_1_INDIESTUDIO_THIBAULT_CAMPAGNE_ENTITYMANAGER_HPP
