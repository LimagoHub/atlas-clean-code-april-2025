//
// Created by JoachimWagner on 11.03.2025.
//

#pragma once

#include <string>

namespace atlas::io {



    class Writer {
    public:
        virtual ~Writer() = default;
        virtual auto write(std::string message) const -> void = 0;
    };
}
