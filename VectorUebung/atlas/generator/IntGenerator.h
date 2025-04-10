//
// Created by JoachimWagner on 09.04.2025.
//

#pragma once
#include "Generator.h"
namespace atlas::generator {
    class IntGenerator : public Generator<int>{
    public:
        ~IntGenerator() override = default;
    };
}

