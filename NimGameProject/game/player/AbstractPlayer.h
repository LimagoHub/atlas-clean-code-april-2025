//
// Created by JoachimWagner on 11.03.2025.
//

#pragma once

#include <string>
#include "Player.h"
namespace atlas::game::player {

    template<class BOARD, class TURN>
    class AbstractPlayer: public Player<BOARD, TURN>{

    public:
        explicit AbstractPlayer(const std::string &name) : name(name) {}

        const std::string getName() const override{
            return name;
        }

    private:
        std::string name;

    };

}
