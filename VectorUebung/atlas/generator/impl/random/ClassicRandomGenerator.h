//
// Created by JoachimWagner on 09.04.2025.
//

#pragma once
#include <random>
#include <climits>
#include "../../IntGenerator.h"

namespace atlas::generator {

    class ClassicRandomGenerator: public IntGenerator {
    public:
        ClassicRandomGenerator() {
            srand(1);
        }

        auto next() -> int override {
            return rand();
        }
    };

} // atlas
