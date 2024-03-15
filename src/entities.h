#pragma once // Include guard to prevent multiple inclusion
#include <unordered_map> // Include necessary library for unordered_map
#include <string> // Include necessary library for string
#include <typeindex> // Include necessary library for type_index

class Entity { // Define a class named Entity
private:
    int id; // Member variable to store entity ID
    std::unordered_map<std::type_index, void*> components; // Map to store components of different types

public:
    // Constructor to initialize the entity with an ID
    Entity(int id) : id(id) {}

    // Method to add a component to the entity
    template <typename T>
    void addComponent(T* component) {
        // Store the component in the map using its type as the key
        components[std::type_index(typeid(T))] = static_cast<void*>(component);
    }

    // Method to get a component of a specific type from the entity
    template <typename T>
    T* getComponent() {
        auto it = components.find(std::type_index(typeid(T))); // Find the component in the map
        if (it != components.end()) { // If component is found
            return static_cast<T*>(it->second); // Cast and return the component pointer
        }
        return nullptr; // Return nullptr if component is not found
    }
};
