//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once
#include <random>
#include <climits>
#include "../../IntGenerator.h"

namespace atlas::generator {
    class MersenneTwisterNumberGenerator : public IntGenerator{
    public:
        ~MersenneTwisterNumberGenerator() override = default;
        explicit MersenneTwisterNumberGenerator()
                : rng_{ device_() }

        {
            // NOOP
        }

        [[nodiscard]] auto next() noexcept -> int override { return distribution_(rng_); }

    private:
        std::random_device device_;
        mutable std::mt19937 rng_;
        std::uniform_int_distribution<std::int32_t> distribution_{INT_MIN, INT_MAX};
    };

}