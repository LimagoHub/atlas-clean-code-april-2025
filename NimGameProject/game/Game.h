//
// Created by JoachimWagner on 10.03.2025.
//

#pragma once

namespace atlas::game {

    class Game {
    public:
        Game() = default;
        virtual ~Game() = default;

        virtual void play() = 0;
    };

} // game
