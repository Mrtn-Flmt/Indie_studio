//
// Created by tcampagne on 06/06/22.
//

#ifndef YEP_400_BOMBERMAN_HPP
#define YEP_400_BOMBERMAN_HPP

#include <iostream>
#include "ECS/Entity.hpp"
#include "ECS/Transform.hpp"
#include "ECS/ModelRenderer.hpp"
#include "ECS/EntityManager.hpp"
#include "ECS/CameraECS.hpp"
#include "ECS/SpriteRenderer.hpp"
#include "ECS/SpriteRendererPlus.hpp"
#include "ECS/GeometricRenderer.hpp"
#include "ECS/GeoAnimationRenderer.hpp"
#include "ECS/PlayerComponent.hpp"
#include "ECS/CollisionRenderer.hpp"
#include "raylib.h"
#include "rlgl.h"
#include "HelpDeveloppement/Developpement.hpp"
#include "PreMenu.hpp"
#include "Menu.hpp"

void InitEntityToEntityManager(EntityManager *manager);
void InitEntityToEntityLoad(EntityManager *load);
void InitEntityToEntityMenu(EntityManager *menu, Font font);
void EntitySelectionGestionMenu(EntityManager *menu);
void InitEntityPreMenu(EntityManager *premenu, Font font);
void GestionPreMenu(EntityManager *premenu, PreMenu *Premenu);
void InitEntityToEntityTuto(EntityManager *tuto);
void InitEntityToGameEntityManager(EntityManager *game);

#endif //YEP_400_BOMBERMAN_HPP
