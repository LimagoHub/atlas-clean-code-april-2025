//
// Created by JoachimWagner on 10.03.2025.
//

#pragma once
#include "../game/Game.h"
namespace client {

    using Game = atlas::game::Game;

    class GameClient {
    public:
        explicit GameClient(Game &game) : game(game) {}

        auto go()->void {
            game.play();
        }

    private:
        Game &game;

    };

} // client
