//
// Created by JoachimWagner on 12.03.2025.
//

#pragma once

#include <chrono>

namespace atlas::time {

    class Stopwatch {
    public:
        virtual ~Stopwatch() = default;
        virtual auto start() noexcept -> void = 0;
        virtual auto  stop()  noexcept -> void= 0;
        [[nodiscard]]
        virtual auto getDurationToMilliseconds() const noexcept -> std::chrono::milliseconds = 0;
    };
}
