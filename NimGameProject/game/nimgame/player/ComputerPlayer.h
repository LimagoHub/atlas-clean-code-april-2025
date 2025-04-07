//
// Created by JoachimWagner on 11.03.2025.
//

#pragma once

#include <iostream>
#include "AbstractNimGamePlayer.h"
namespace atlas::game::nimgame::player {
    class ComputerPlayer :public AbstractNimGamePlayer{
        static inline int turns[] = {3,1,1,2};
    public:
        explicit ComputerPlayer(const std::string &name) : AbstractNimGamePlayer(name) {}

        auto doTurn(const int &stones) const -> int override {

            const int turn = turns[stones % 4];
            std::cout << "Computer nimmt " << turn << " Steine." << std::endl;
            return turn;
        }
    };
}
