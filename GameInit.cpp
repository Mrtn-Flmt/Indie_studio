/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-thibault.campagne
** File description:
** GameInit
*/

#include "BomberMan.hpp"

void InitEntityToGameEntityManager(EntityManager *game)
{
    Entity *map = new Entity("map");
    Entity *ground = new Entity("ground");
    Entity *player1 = new Entity("player1");
    Entity *player2 = new Entity("player2");
    CollisionRenderer *colliders = new CollisionRenderer();

    game->addEntity(map);
    game->addEntity(ground);
    game->addEntity(player1);
    game->addEntity(player2);
    map->addComponent<MapCubeRenderer>(1, 1, 1, RED);
    for (float x = 8.0f; x >= -8.0f; x -= 16.0f)
        for (float z = 7.0f; z >= -7.0f; z--) {
            map->getComponent<MapCubeRenderer>().addCube(Vector3 {x, 0.0f, z});
        }
    for (float z = 7.0f; z >= -7.0f; z -= 14.0f)
        for (float x = 7.0f; x >= -7.0f; x--) {
            map->getComponent<MapCubeRenderer>().addCube(Vector3 {x, 0.0f, z});
        }
    for (float z = 5.0f; z >= -5.0f; z -= 2.0f) {
        for (float x = 6.0f; x >= -6.0f; x -= 2.0f) {
            map->getComponent<MapCubeRenderer>().addCube(Vector3 {x, 0.0f, z});
            colliders->newCollider(Vector3 {x, 0.0f, z}, Vector3 {1.0f, 1.0f, 1.0f});
        }
    }
    map->getComponent<MapCubeRenderer>().setOutline(true, YELLOW);
    ground->addComponent<MapCubeRenderer>(1, 1, 1, LIGHTGRAY);
    for (float x = 7.0f; x >= -7.0f; x -= 1.0f)
        for (float z = 6.0f; z >= -6.0f; z -= 1.0f)
            ground->getComponent<MapCubeRenderer>().addCube(Vector3 {x, -1.0f, z});
    ground->getComponent<MapCubeRenderer>().setOutline(true, YELLOW);
    player1->addComponent<PlayerComponent>(Vector3 {7.0f, 0.0f, 6.0f}, std::vector<KeyboardKey> {KEY_W, KEY_S, KEY_D, KEY_A, KEY_SPACE});
    player1->getComponent<PlayerComponent>().setColliders(colliders);
    player2->addComponent<PlayerComponent>(Vector3 {-7.0f, 0.0f, -6.0f}, std::vector<KeyboardKey> {KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT, KEY_ENTER});
    player2->getComponent<PlayerComponent>().setColliders(colliders);
    player2->getComponent<PlayerComponent>().setPlayerColor(BLUE);
}