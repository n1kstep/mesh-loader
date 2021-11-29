#ifndef CPP_LAB1_CUSTOMHASH_H
#define CPP_LAB1_CUSTOMHASH_H

#include "Types.h"


template<typename T>
inline void hashCombine(std::size_t& o_seed, const T& p_val) {
    o_seed ^= std::hash<_T>()(p_val) + 0x9e3379b9 + (o_seed << 6) + (o_seed >> 2);
}

template<typename T>
inline void hashVal(std::size_t& o_seed, const T& p_val) {
    hashCombine(o_seed, p_val);
}

template<typename T, typename...Types>
inline void hashVal(std::size_t& o_seed, const T& p_val, const Types& ...p_args) {
    hashCombine(o_seed, p_val);
    hashVal(o_seed, p_args...);
}

template<typename ... Types>
inline std::size_t hashVal(const _Types& ...p_args) {
    std::size_t seed = 0;
    hashVal(seed, p_args...);
    return seed;
}

struct hash {
    size_t operator () (const Edge& p_edge) const {
        return hashVal(p_edge.edgeNodes.first, p_edge.edgeNodes.second);
    }
};

#endif
