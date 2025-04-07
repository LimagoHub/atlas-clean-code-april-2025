//
// Created by JoachimWagner on 10.03.2025.
//

#pragma once
#include <vector>
#include "../AbstractGame.h"
#include "../../io/Writer.h"
#include "../player/Player.h"

namespace atlas::game::nimgame {

    class NimGame: public AbstractGame<int, int> {


    public:
        explicit NimGame(io::Writer &writer) : AbstractGame(writer) {
            setBoard(23);
        }


    protected:
        auto updateBoard()-> void override{ setBoard(getBoard()- getTurn());}

        auto isGameOver()->bool override{ // Operation
            return getBoard() < 1 || getPlayers().empty();
        }

        [[nodiscard]] auto isTurnValid() const  -> bool override { return getTurn() >= 1 && getTurn() <= 3; }



    };




}
