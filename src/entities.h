#pragma once
#include <unordered_map>
#include <string>
#include <typeindex>




class Entity {
private:
    int id;
    std::unordered_map<std::type_index, void*> components;

public:
    Entity(int id) : id(id) {}

    template <typename T>
    void addComponent(T* component) {
        components[std::type_index(typeid(T))] = static_cast<void*>(component);
    }

    template <typename T>
    T* getComponent() {
        auto it = components.find(std::type_index(typeid(T)));
        if (it != components.end()) {
            return static_cast<T*>(it->second);
        }
        return nullptr;
    }
};

