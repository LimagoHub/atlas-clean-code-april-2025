//
// Created by JoachimWagner on 11.03.2025.
//

#pragma once

#include <string>
#include "../../player/AbstractPlayer.h"
namespace atlas::game::nimgame::player {

class AbstractNimGamePlayer: public atlas::game::player::AbstractPlayer<int, int>{

    public:
    explicit AbstractNimGamePlayer(const std::string &name) : AbstractPlayer(name) {}
};

}
