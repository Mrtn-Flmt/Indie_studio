//
// Created by tcampagne on 06/06/22.
//

#include "BomberMan.hpp"
#include "ECS/SpriteRenderer.hpp"

void InitEntityToEntityManager(EntityManager *manager) {
    Entity *greathall = new Entity("GreatHall");
    Entity *camera = new Entity("Camera");
    Entity *dumbledore = new Entity("Dumbledore");
    Entity *mcgonagal = new Entity("McGonagal");
    manager->addEntity(camera);
    manager->addEntity(greathall);
    manager->addEntity(dumbledore);
    manager->addEntity(mcgonagal);
    greathall->addComponent<ModelRenderer>("Models/GreatHall/");
    mcgonagal->addComponent<ModelRenderer>("Models/McGonagal/");
    dumbledore->addComponent<ModelRenderer>("Models/Dumbledore/");
    camera->addComponent<CameraECS>();

}
