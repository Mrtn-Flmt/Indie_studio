//
// Created by Demon on 08/05/2022.
//

#ifndef B_YEP_400_LIL_4_1_INDIESTUDIO_THIBAULT_CAMPAGNE_ENTITY_HPP
#define B_YEP_400_LIL_4_1_INDIESTUDIO_THIBAULT_CAMPAGNE_ENTITY_HPP

#include "ECS.hpp"
#include <memory>
#include <vector>
#include "Component.hpp"
#include "Transform.hpp"
#include "EntityManager.hpp"

class Entity {
    public:
        Entity(std::string nameEntity) {
            this->addComponent<TransformECS>(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
            name = nameEntity;
        }
        virtual ~Entity() = default;

        template<typename T, typename... TArgs>
        inline T& addComponent(TArgs&&... args) {
            T* comp(new T(std::forward<TArgs>(args)...));
            std::unique_ptr<Component> uptr { comp };
            components.emplace_back(std::move(uptr));
            comp->entity = this;
            if (comp->init()) {
                compArray[getComponentTypeID<T>()] = comp;
                compBitset[getComponentTypeID<T>()] = true;
                return *comp;
            }
            return *static_cast<T*>(nullptr);
        }

        template<typename T>
        inline T& getComponent() const {
            auto ptr(compArray[getComponentTypeID<T>()]);
            return *static_cast<T*>(ptr);
        }

        template<typename T>
        inline bool hasComponent() const {
            return compBitset[getComponentTypeID<T>()];
        }

        inline bool isActive() const {
            return active;
        }

        inline void destroy() {
            active = false;
        }

        inline void draw() {
            for (auto& comp : components) {
                comp->draw();
            }
        }

        inline void update() {
            for (auto& comp : components)
                comp->update();
        }

        std::string name;

    private:
        bool active;
        ComponentArray compArray;
        ComponentBitset compBitset;
        std::vector<std::unique_ptr<Component>> components;
};

#endif //B_YEP_400_LIL_4_1_INDIESTUDIO_THIBAULT_CAMPAGNE_ENTITY_HPP
