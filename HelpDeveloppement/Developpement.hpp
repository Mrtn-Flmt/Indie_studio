//
// Created by tcampagne on 03/06/22.
//

#ifndef YEP_400_DEVELOPPEMENT_HPP
#define YEP_400_DEVELOPPEMENT_HPP

#include "BooleanCondition.hpp"
#include "Gestion.hpp"
#include "PositionRect.hpp"
#include "PositionText.hpp"
#include "Text.hpp"
#include "RectangleDev.hpp"
#include "../ECS/Transform.hpp"
#include <sstream>
#include <memory>

class EntityManager;

class Developpement : public Gestion, public PositionText, public PositionRect, public boolCondition, public RectangleDev, public Text{
public:
    MyRaylib rayLib;
    Developpement() = default;
    template <typename T>
    std::string to_string_with_precision(const T a_value, const int n = 6)
    {
        std::ostringstream out;
        out.precision(n);
        out << std::fixed << a_value;
        return out.str();
    }

    void SetTransformValueInBeginAdd(std::vector<std::string> tempTransformValue, int key);
    void SetTransformValueInMiddleAdd(std::vector<std::string> tempTransformValue, int key);
    void SetTransformECSToTransformValue(std::vector<std::string> tempTransformValue, std::unique_ptr<Entity> &entity);

    void init(EntityManager *manager);
    void RectEntitySelectEvent();
    void LoadEntityDataNewGame(EntityManager *manager);
    void SaveEntityDataNewGame(EntityManager *manager);
    void TransformEntitySelectedGestion(EntityManager *manager);
    void EntitySelectedGestion(EntityManager *manager);
    void Draw();
    void CheckTransformSelected();
    void SetTransformValueToTransformECS(EntityManager *manager);
    void SetNewTransformValueByAdd(std::vector<std::string> tempTransformValue, EntityManager *manager);
    void SetNewTransformValueByRemove(std::vector<std::string> tempTransformValue);
    void CheckKeepMouseOnTextEntity();
    void CheckRectangleEntitySelected();
    void RemoveGestionEntitySelected(std::vector<std::string> entitiesName, EntityManager *manager);
    void SelectionOfEntity(std::vector<std::string> entitiesName, EntityManager *manager);
    void ScrollSystemEntitiesSelection(EntityManager *manager);
    void LongRectangleEntity();
    void ShortRectangleEntity();
};

#endif //YEP_400_DEVELOPPEMENT_HPP
