//
// Created by JoachimWagner on 28.01.2025.
//

#pragma once

#include <iostream>

#include "time.h"
#include <cstdlib>
#include "AbstractNimGamePlayer.h"
namespace atlas::game::nimgame::player {

    class OmaPlayer: public AbstractNimGamePlayer{

    public:
        explicit OmaPlayer(const std::string &name) : AbstractNimGamePlayer(name) {
            std::srand(time(nullptr));
        }




        [[nodiscard]]
        auto doTurn(const int &stones) const -> int override {
            const int result = std::rand() % 6;
            std::cout << "Oma nimmt " << result << " Steine." << std::endl;

            return result;
        }
    };

} // game
