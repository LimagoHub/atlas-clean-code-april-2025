//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once

#include "../../GeneratorBuilder.h"
#include "MersenneTwisterNumberGenerator.h"

namespace atlas::generator {
    class MersenneTwisterNumberGeneratorFactory : public GeneratorBuilder<int> {
    public:


        ~MersenneTwisterNumberGeneratorFactory() override = default;
        [[nodiscard]] auto create() const -> std::unique_ptr<Generator<int>> override
        {
            return std::make_unique<MersenneTwisterNumberGenerator>();
        }
    };
}
