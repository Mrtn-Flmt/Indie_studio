//
// Created by tcampagne on 03/06/22.
//

#include "../ECS/Entity.hpp"
#include "../ECS/CameraECS.hpp"
#include "Developpement.hpp"

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 6)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}

void Developpement::init(EntityManager *manager) {
    std::string directoryRepo = GetPrevDirectoryPath(GetWorkingDirectory());
    std::vector<std::string> entitiesName;
    std::vector<Rectangle> rectangleEntitySelected;
    std::vector<Rectangle> transform;
    std::vector<std::string> transformValue;

    directoryRepo += "/EntitiesDataNewGame/";
    setDirectoryRepo(directoryRepo);
    transform.push_back({ 1590, 55, 90, 30 });
    transform.push_back({ 1700, 55, 90, 30 });
    transform.push_back({ 1810, 55, 90, 30 });
    transform.push_back({ 1590, 105, 90, 30 });
    transform.push_back({ 1700, 105, 90, 30 });
    transform.push_back({ 1810, 105, 90, 30 });
    transform.push_back({ 1590, 155, 90, 30 });
    transform.push_back({ 1700, 155, 90, 30 });
    transform.push_back({ 1810, 155, 90, 30 });
    for (int i = 0; i < 9; i++)
        transformValue.push_back(" ");
    setTransformValue(transformValue);
    setTransform(transform);
    for (int i = 0; i < manager->storageOfEntitiesName.size(); i++)
        entitiesName.push_back(manager->storageOfEntitiesName[i]);
    setEntitiesName(entitiesName);
    for (int i = 0; i < getEntitiesName().size(); i++) {
        rectangleEntitySelected.push_back({1595, (float)getPosEntitiesRect(), 290, 20});
        setPosEntitiesRect(getPosEntitiesRect() + 25);
    }
    setRectangleEntitySelected(rectangleEntitySelected);
}

void Developpement::LoadEntityDataNewGame(EntityManager *manager) {
    std::vector<float> valueDataTransformEntity;

    for (auto &entity: manager->entities) {
        valueDataTransformEntity.erase(valueDataTransformEntity.begin(), valueDataTransformEntity.end());
        if (rayLib.myDirectoryExists("EntitiesDataNewGame") &&
            rayLib.myFileExists(("EntitiesDataNewGame/" + entity->name).c_str())) {
            setDataTransformEntity(rayLib.myLoadFileText(("EntitiesDataNewGame/" + entity->name).c_str()));
            for (int j = 0; j < getTransform().size(); j++) {
                if (getDataTransformEntity().find_first_of(';') < getDataTransformEntity().find_first_of('\n')) {
                    valueDataTransformEntity.push_back(stof(
                            getDataTransformEntity().substr(0, getDataTransformEntity().find_first_of(';'))));
                    setDataTransformEntity(
                            getDataTransformEntity().erase(0, getDataTransformEntity().find_first_of(';') + 1));
                } else {
                    valueDataTransformEntity.push_back(stof(
                            getDataTransformEntity().substr(0, getDataTransformEntity().find_first_of('\n'))));
                    setDataTransformEntity(
                            getDataTransformEntity().erase(0, getDataTransformEntity().find_first_of('\n') + 1));
                }
            }
            setValueDataTransformEntity(valueDataTransformEntity);
            entity->getComponent<TransformECS>().position.x = getValueDataTransformEntity()[0];
            entity->getComponent<TransformECS>().position.y = getValueDataTransformEntity()[1];
            entity->getComponent<TransformECS>().position.z = getValueDataTransformEntity()[2];
            entity->getComponent<TransformECS>().rotation.x = getValueDataTransformEntity()[3];
            entity->getComponent<TransformECS>().rotation.y = getValueDataTransformEntity()[4];
            entity->getComponent<TransformECS>().rotation.z = getValueDataTransformEntity()[5];
            entity->getComponent<TransformECS>().scale.x = getValueDataTransformEntity()[6];
            entity->getComponent<TransformECS>().scale.y = getValueDataTransformEntity()[7];
            entity->getComponent<TransformECS>().scale.z = getValueDataTransformEntity()[8];
        }
    }
}

void Developpement::SaveEntityDataNewGame(EntityManager *manager) {
    if (rayLib.myIsKeyPressed(KEY_R)) {
        for (auto &entity : manager->entities) {
            if (rayLib.myDirectoryExists("EntitiesDataNewGame")) {
                setPathSaveDataTransformEntity("EntitiesDataNewGame/" + entity->name);
                setDataTransformEntity(to_string_with_precision(entity->getComponent<TransformECS>().position.x, 2) + ";"
                        + to_string_with_precision(entity->getComponent<TransformECS>().position.y, 2) +
                        ";" +
                        to_string_with_precision(entity->getComponent<TransformECS>().position.z, 2) +
                        "\n" +
                        to_string_with_precision(entity->getComponent<TransformECS>().rotation.x, 2) + ";"
                        + to_string_with_precision(entity->getComponent<TransformECS>().rotation.y, 2) +
                        ";" +
                        to_string_with_precision(entity->getComponent<TransformECS>().rotation.z, 2) +
                        "\n" +
                        to_string_with_precision(entity->getComponent<TransformECS>().scale.x, 2) + ";"
                        + to_string_with_precision(entity->getComponent<TransformECS>().scale.y, 2) + ";" +
                        to_string_with_precision(entity->getComponent<TransformECS>().scale.z, 2) + "\0");
                rayLib.mySaveFileText(getPathSaveDataTransformEntity().c_str(),
                                      (char *) getDataTransformEntity().c_str());
            }
            rayLib.mySaveFileText((getDirectoryRepo() + entity->name).c_str(), (char*)getDataTransformEntity().c_str());
        }
    }
}

void Developpement::CheckTransformSelected() {
    for (int i = 0; i < 9; i++) {
        if (rayLib.myCheckCollisionPointRec(rayLib.myGetMousePosition(), getTransform()[i]) &&
            rayLib.myIsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !getMouseOnTextEntity()) {
            setIndexTransform(i);
            setMouseOnText(true);
            break;
        }
    }
}

void Developpement::SetTransformValueToTransformECS(EntityManager *manager) {
    if (getMouseOnText() && (rayLib.myIsKeyPressed(KEY_KP_ENTER) || rayLib.myIsKeyPressed(KEY_ENTER))) {
        for (auto &entity : manager->entities) {
            if (entity->name == getEntityTextSelected()) {
                entity->getComponent<TransformECS>().position.x = stof(getTransformValue()[0]);
                entity->getComponent<TransformECS>().position.y = stof(getTransformValue()[1]);
                entity->getComponent<TransformECS>().position.z = stof(getTransformValue()[2]);
                entity->getComponent<TransformECS>().rotation.x = stof(getTransformValue()[3]);
                entity->getComponent<TransformECS>().rotation.y = stof(getTransformValue()[4]);
                entity->getComponent<TransformECS>().rotation.z = stof(getTransformValue()[5]);
                entity->getComponent<TransformECS>().scale.x = stof(getTransformValue()[6]);
                entity->getComponent<TransformECS>().scale.y = stof(getTransformValue()[7]);
                entity->getComponent<TransformECS>().scale.z = stof(getTransformValue()[8]);
            }
        }
        setMouseOnText(false);
    }
}

void Developpement::SetTransformValueInBeginAdd(std::vector<std::string> tempTransformValue, int key) {
    tempTransformValue[getIndexTransform()].erase(tempTransformValue[getIndexTransform()].begin(), tempTransformValue[getIndexTransform()].end());
    tempTransformValue[getIndexTransform()].push_back((char) key);
    tempTransformValue[getIndexTransform()].push_back('\0');
    setLetterCount(getLetterCount() + 1);
    setTransformValue(tempTransformValue);
}

void Developpement::SetTransformValueInMiddleAdd(std::vector<std::string> tempTransformValue, int key) {
    tempTransformValue[getIndexTransform()].erase(tempTransformValue[getIndexTransform()].end() - 1);
    tempTransformValue[getIndexTransform()].push_back((char) key);
    tempTransformValue[getIndexTransform()].push_back('\0');
    setLetterCount(getLetterCount() + 1);
    setTransformValue(tempTransformValue);
}

void Developpement::SetTransformECSToTransformValue(std::vector<std::string> tempTransformValue,
                                                    std::unique_ptr<Entity> &entity) {
    tempTransformValue[0] = to_string_with_precision(entity->getComponent<TransformECS>().position.x, 2);
    tempTransformValue[1] = to_string_with_precision(entity->getComponent<TransformECS>().position.y, 2);
    tempTransformValue[2] = to_string_with_precision(entity->getComponent<TransformECS>().position.z, 2);
    tempTransformValue[3] = to_string_with_precision(entity->getComponent<TransformECS>().rotation.x, 2);
    tempTransformValue[4] = to_string_with_precision(entity->getComponent<TransformECS>().rotation.y, 2);
    tempTransformValue[5] = to_string_with_precision(entity->getComponent<TransformECS>().rotation.z, 2);
    tempTransformValue[6] = to_string_with_precision(entity->getComponent<TransformECS>().scale.x, 2);
    tempTransformValue[7] = to_string_with_precision(entity->getComponent<TransformECS>().scale.y, 2);
    tempTransformValue[8] = to_string_with_precision(entity->getComponent<TransformECS>().scale.z, 2);
    setTransformValue(tempTransformValue);
}

void Developpement::SetNewTransformValueByAdd(std::vector<std::string> tempTransformValue, EntityManager *manager) {
    if (getMouseOnText()) {
        if (getLetterCount() == 0)
            setNegative(false);
        if (rayLib.myIsKeyPressed(KEY_KP_SUBTRACT) || rayLib.myIsKeyPressed(KEY_SIX)) {
            setNegative(true);
        }
        setFramesCounter(getFramesCounter() + 1);
        rayLib.mySetMouseCursor(MOUSE_CURSOR_IBEAM);
        int key = rayLib.myGetCharPressed();
        while (key > 0) {
            tempTransformValue = getTransformValue();
            if (!getNegative() && ((key >= 48 && key <= 57) || key == 46 ) && getLetterCount() < 6) {
                if (getLetterCount() == 0) {
                    SetTransformValueInBeginAdd(tempTransformValue, key);
                } else if (getLetterCount() == 3) {
                    if (key == 46)
                        SetTransformValueInMiddleAdd(tempTransformValue, key);
                } else {
                    SetTransformValueInMiddleAdd(tempTransformValue, key);
                }
            } if (getNegative() && ((key >= 48 && key <= 57) || key == 45 || key == 46) && getLetterCount() < 7) {
                if (getLetterCount() == 0) {
                    SetTransformValueInBeginAdd(tempTransformValue, key);
                } else if (getLetterCount() == 4) {
                    if (key == 46) {
                        SetTransformValueInMiddleAdd(tempTransformValue, key);
                    }
                } else {
                    SetTransformValueInMiddleAdd(tempTransformValue, key);
                }
            }
            key = rayLib.myGetCharPressed();
        }
    } else {
        rayLib.mySetMouseCursor(MOUSE_CURSOR_DEFAULT);
        setLetterCount(0);
        for (auto &entity : manager->entities) {
            if (entity->name == getEntityTextSelected() && !getNegative()) {
                SetTransformECSToTransformValue(tempTransformValue, entity);
            } if (entity->name == getEntityTextSelected() && getNegative()) {
                SetTransformECSToTransformValue(tempTransformValue, entity);
            }
        }
        setIndexTransform(-1);
        setFramesCounter(0);
    }
}

void Developpement::SetNewTransformValueByRemove(std::vector<std::string> tempTransformValue) {
    if (rayLib.myIsKeyPressed(KEY_BACKSPACE) && getMouseOnText()) {
        tempTransformValue = getTransformValue();
        setLetterCount(getLetterCount() - 1);
        if (getLetterCount() < 0)
            setLetterCount(0);
        tempTransformValue[getIndexTransform()].erase(getLetterCount());
        tempTransformValue[getIndexTransform()].push_back('\0');
        setTransformValue(tempTransformValue);
    }
}

void Developpement::TransformEntitySelectedGestion(EntityManager *manager) {
    std::vector<std::string> tempTransformValue = getTransformValue();

    if (getEntitySelected()) {
        CheckTransformSelected();
        SetTransformValueToTransformECS(manager);
        SetNewTransformValueByAdd(tempTransformValue, manager);
        SetNewTransformValueByRemove(tempTransformValue);
    }
}

void Developpement::CheckKeepMouseOnTextEntity() {
    if (getMouseOnTextEntity() && !rayLib.myCheckCollisionPointRec(rayLib.myGetMousePosition(), getRectangleEntitySelected()[getIndexSelectEntity()]) && getKeepMouseOnTextEntity())
        setKeepMouseOnTextEntity(false);
}

void Developpement::CheckRectangleEntitySelected() {
    for (int i = 0; getMouseOnTextEntity() && i < getEntitiesName().size(); i++) {
        if (rayLib.myCheckCollisionPointRec(rayLib.myGetMousePosition(), getRectangleEntitySelected()[i]) && getScissorMode()) {
            setIndexSelectEntity(i);
            setKeepMouseOnTextEntity(true);
        }
    }
}

void Developpement::RemoveGestionEntitySelected(std::vector<std::string> entitiesName, EntityManager *manager) {
    if (getEntitySelected() && !getMouseOnText() && rayLib.myIsKeyPressed(KEY_BACKSPACE)) {
        setEntityTextSelected(" ");
        entitiesName.erase(entitiesName.begin(), entitiesName.end());
        for (int i = 0; i < manager->storageOfEntitiesName.size(); i++)
            entitiesName.push_back(manager->storageOfEntitiesName[i]);
        setEntitySelected(false);
        setEntitiesName(entitiesName);
    }
}

void Developpement::SelectionOfEntity(std::vector<std::string> entitiesName, EntityManager *manager) {
    if (getKeepMouseOnTextEntity() && getMouseOnTextEntity() && rayLib.myIsMouseButtonPressed(MOUSE_BUTTON_LEFT) && getIndexSelectEntity() < getEntitiesName().size()) {
        entitiesName = getEntitiesName();
        setEntityTextSelected(getEntitiesName()[getIndexSelectEntity()]);
        entitiesName.erase(entitiesName.begin(), entitiesName.end());
        for (int i = 0; i < manager->storageOfEntitiesName.size(); i++)
            entitiesName.push_back(manager->storageOfEntitiesName[i]);
        for (int i = 0; i < manager->storageOfEntitiesName.size(); i++) {
            if (getEntityTextSelected() == manager->storageOfEntitiesName[i]) {
                entitiesName.erase(entitiesName.begin() + i);
            }
        }
        setEntitiesName(getEntitiesName());
        setRectangleEntity({1590, 5, 300, 30});
        setMouseOnTextEntity(false);
        setScissorMode(false);
        setEntitySelected(true);
    }
}

void Developpement::ScrollSystemEntitiesSelection(EntityManager *manager) {
    std::vector<Rectangle> tempRectangleEntitySelected = getRectangleEntitySelected();

    if (getMouseOnTextEntity()) {
        setFirstPosEntitiesRect(getFirstPosEntitiesRect() + (rayLib.myGetMouseWheelMove() * getScrollSpeed()));
        setFirstPosEntitiesNameY(getFirstPosEntitiesNameY() + rayLib.myGetMouseWheelMove() * getScrollSpeed());
        if (getFirstPosEntitiesRect() <= 35 && (getFirstPosEntitiesRect() + ((getEntitiesName().size() - 1) * 25) + 20) >= 195.0f) {
            setPosEntitiesRect(getFirstPosEntitiesRect());
            setLastFirstPosEntitiesRect(getFirstPosEntitiesRect());
            setLastFirstPosEntitiesNameY(getFirstPosEntitiesNameY());
            for (int i = 0; i < getEntitiesName().size(); i++) {
                tempRectangleEntitySelected[i].y = (float) getPosEntitiesRect();
                setPosEntitiesRect(getPosEntitiesRect() + 25);
            }
            setRectangleEntitySelected(tempRectangleEntitySelected);
        } if (getFirstPosEntitiesRect() > 35){
            setFirstPosEntitiesRect(35);
            setFirstPosEntitiesNameY(37);
        } if (getEntitiesName().size() >= 7 && (getFirstPosEntitiesRect() + ((getEntitiesName().size() - 1) * 25) + 20) < 195.0f) {
            tempRectangleEntitySelected = getRectangleEntitySelected();
            setPosEntitiesRect(177);
            for (int i = getEntitiesName().size() - 1; i >= 0; i--) {
                tempRectangleEntitySelected[i].y = (float)getPosEntitiesRect();
                setPosEntitiesRect(getPosEntitiesRect() - 25);
            }
            setRectangleEntitySelected(tempRectangleEntitySelected);
            setFirstPosEntitiesRect(getRectangleEntitySelected()[0].y);
            setFirstPosEntitiesNameY(getFirstPosEntitiesRect() + 2);
        }
    } else {
        for (auto &entity : manager->entities)
            if (entity->hasComponent<CameraECS>())
                entity->update();
    }
}

void Developpement::LongRectangleEntity() {
    if (rayLib.myCheckCollisionPointRec(rayLib.myGetMousePosition(), getRectangleEntity()) &&
        rayLib.myIsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        setRectangleEntity({1590, 5, 300, 200});
        setMouseOnTextEntity(true);
        setScissorMode(true);
    }
}

void Developpement::ShortRectangleEntity() {
    if (getMouseOnTextEntity() && rayLib.myIsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        setRectangleEntity({1590, 5, 300, 30});
        setMouseOnTextEntity(false);
        setScissorMode(false);
    }
}

void Developpement::EntitySelectedGestion(EntityManager *manager) {
    std::vector<std::string> entitiesName = getEntitiesName();

    CheckKeepMouseOnTextEntity();
    CheckRectangleEntitySelected();
    RemoveGestionEntitySelected(entitiesName, manager);
    SelectionOfEntity(entitiesName, manager);
    ScrollSystemEntitiesSelection(manager);
    LongRectangleEntity();
    ShortRectangleEntity();
}

void Developpement::Draw() {
    rayLib.myDrawRectangle(1460, 0, 450, 40, DARKGRAY);
    rayLib.myDrawText("Entity", 1480, 12, 20, RAYWHITE);

    if (getEntitySelected() && getTransformValue().size() != 0) {
        rayLib.myDrawRectangle(1460, 45, 450, 150, DARKGRAY);

        for (int i = 0; i < 9; i++) {
            rayLib.myDrawRectangleRec(getTransform()[i], LIGHTGRAY);
            rayLib.myDrawText(getTransformValue()[i].c_str(), (int) getTransform()[i].x + 5, (int) getTransform()[i].y + 8, 20, BLACK);
            rayLib.myDrawText("Position", 1480, 60, 20, RAYWHITE);
            rayLib.myDrawText("x", 1575, 60, 20, RAYWHITE);
            rayLib.myDrawText("y", 1685, 60, 20, RAYWHITE);
            rayLib.myDrawText("z", 1795, 60, 20, RAYWHITE);
            rayLib.myDrawText("Rotation", 1480, 110, 20, RAYWHITE);
            rayLib.myDrawText("x", 1575, 110, 20, RAYWHITE);
            rayLib.myDrawText("y", 1685, 110, 20, RAYWHITE);
            rayLib.myDrawText("z", 1795, 110, 20, RAYWHITE);
            rayLib.myDrawText("Scale", 1480, 160, 20, RAYWHITE);
            rayLib.myDrawText("x", 1575, 160, 20, RAYWHITE);
            rayLib.myDrawText("y", 1685, 160, 20, RAYWHITE);
            rayLib.myDrawText("z", 1795, 160, 20, RAYWHITE);
        }
        if (getIndexTransform() != -1 && ((getFramesCounter() / 20) % 2) == 0) {
            rayLib.myDrawText("|", (int) getTransform()[getIndexTransform()].x + 8 +
                                   rayLib.myMeasureText(getTransformValue()[getIndexTransform()].c_str(), 20),
                              (int) getTransform()[getIndexTransform()].y + 8, 20, MAROON);
        }
    }

    rayLib.myDrawRectangleRec(getRectangleEntity(), LIGHTGRAY);

    if (getEntityTextSelected().c_str() != nullptr) {
        rayLib.myDrawText(getEntityTextSelected().c_str(), 1600, 12, 19, BLACK);
    }
    if (getScissorMode()) {
        rayLib.myBeginScissorMode((int) getScissorArea().x, (int) getScissorArea().y, (int) getScissorArea().width,
                                  (int) getScissorArea().height);
        if (getKeepMouseOnTextEntity() && getIndexSelectEntity() < getEntitiesName().size()) {
            rayLib.myDrawRectangleRec(getRectangleEntitySelected()[getIndexSelectEntity()], WHITE);
        }
        setPosEntitiesNameY(getFirstPosEntitiesNameY());
        for (int i = 0; i < getEntitiesName().size(); i++) {
            rayLib.myDrawText(getEntitiesName()[i].c_str(), 1600, getPosEntitiesNameY(), 19, BLACK);
            setPosEntitiesNameY(getPosEntitiesNameY() + 25);
        }
        rayLib.myEndScissorMode();
    }
}