#pragma once // Include guard to prevent multiple inclusion

#include <unordered_map> // Include necessary library for unordered_map
#include <string> // Include necessary library for string
#include <typeindex> // Include necessary library for type_index

/**
 * @class Entity
 * @brief Class representing an entity that can hold various components.
 */
class Entity {
private:
    std::string id; ///< Member variable to store entity ID
    std::unordered_map<std::type_index, void*> components; ///< Map to store components of different types

public:
    /**
     * @brief Constructor to initialize the entity with an ID.
     * @param id The ID of the entity.
     */
    Entity(std::string id) : id(id) {}

    /**
     * @brief Adds a component to the entity.
     * @tparam T The type of the component.
     * @param component Pointer to the component to be added.
     */
    template <typename T>
    void addComponent(T* component) {
        components[std::type_index(typeid(T))] = static_cast<void*>(component);
    }

    /**
     * @brief Retrieves a component of a specific type from the entity.
     * @tparam T The type of the component.
     * @return Pointer to the component if found, otherwise nullptr.
     */
    template <typename T>
    T* getComponent() {
        auto it = components.find(std::type_index(typeid(T)));
        if (it != components.end()) {
            return static_cast<T*>(it->second);
        }
        return nullptr;
    }
};