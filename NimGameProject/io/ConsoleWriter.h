//
// Created by JoachimWagner on 11.03.2025.
//

#pragma once

#include <iostream>
#include "Writer.h"
namespace atlas::io {

    class ConsoleWriter :public Writer{
    public:
        auto write(std::string message) const -> void override {
            std::cout << message << std::endl;
        }


    };
}
