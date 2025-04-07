//
// Created by JoachimWagner on 11.03.2025.
//

#pragma once

#include <iostream>
#include "AbstractNimGamePlayer.h"

namespace atlas::game::nimgame::player {

    class HumanPlayer: public AbstractNimGamePlayer{

    public:
        explicit HumanPlayer(const std::string &name) : AbstractNimGamePlayer(name) {}

        auto doTurn(const int &stones) const -> int override {
           
            int turn;
            std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
            std::cin >> turn;
            return turn;
        }
    };

} // atlas::game::nimgame::player
