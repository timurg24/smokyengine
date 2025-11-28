#pragma once
#include <vector>

#include "Entity/Entity.h"

template <typename T>
struct ComponentPool {
    std::vector<T> pool;
    std::vector<bool> has;

    inline void Set(Entity id, const T& data) {
        if(id >= pool.size()) {
            pool.resize(id+1);
            has.resize(id+1, false);
        }

        pool[id] = data;
        has[id] = true;
    }
};
