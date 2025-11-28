#include "Entity.h"

Entity GenerateID(std::string name) {
    Entity id;
    
    for (char c : name) {
        id += c;
    }

    return id;
}