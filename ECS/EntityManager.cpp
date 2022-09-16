#include "EntityManager.hpp"
#include "Entity.hpp"
#include "CameraECS.hpp"

#include "EntityManager.hpp"
#include "Entity.hpp"
#include "CameraECS.hpp"
#include "ModelRenderer.hpp"

void EntityManager::draw() {
    for (auto& entity : entities) {
        if (entity->hasComponent<ModelRenderer>()) {
            BeginMode3D(getEntityCamera());
            entity->draw();
            EndMode3D();
        } else
            entity->draw();
    }
}

void EntityManager::update() {
    for (auto& entity : entities)
        if (!entity->hasComponent<CameraECS>())
            entity->update();
}

void EntityManager::refresh() {

}

void EntityManager::addEntity(Entity *entity) {
    std::unique_ptr<Entity> uniquePtr { entity };
    entities.emplace_back(std::move(uniquePtr));
}

void EntityManager::eraseEntity(Entity *entity) {

}

Entity *EntityManager::cloneEntity(Entity *entity) {
    return nullptr;
}

void EntityManager::stockEntitiesName() {
    for (auto &entity : entities)
        storageOfEntitiesName.push_back(entity->name);
}

Camera3D EntityManager::getEntityCamera() {
    Camera3D camera;
    for (auto &entity : entities) {
        if (entity->name == "Camera" || entity->name == "camera") {
            return entity->getComponent<CameraECS>().getCamera();
        }
    }
    return camera;
}