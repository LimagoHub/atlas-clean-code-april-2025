//
// Created by JoachimWagner on 11.03.2025.
//

#pragma once
#include "Game.h"
#include <vector>
#include "../io/Writer.h"
#include "player/Player.h"
namespace atlas::game {

    template<class BOARD, class TURN>
    class AbstractGame: public Game {
        using PLAYER = player::Player<BOARD,TURN> *;
        using PLAYERS = std::vector<PLAYER>;

    public:

        explicit AbstractGame(io::Writer &writer) : writer(writer) {}

        auto addPlayer(PLAYER player) -> void {
            players.push_back(player);
        }
        auto removePlayer(PLAYER player) -> void {
            // Not implemented yet
            // TODO implememt feature
        }

        auto play()->void override {
            while(! isGameOver())  playRound();

        }

    private:
        auto playRound()-> void { // Integration
          for(auto player: players) {
                setCurrentPlayer(player);
                playSingleTurn();
            }
        }
        auto playSingleTurn()->void{
            if(isGameOver()) return;
            executeTurn();
            terminateTurn();
        }

        auto executeTurn()->void {
            do {
                _turn = getCurrentPlayer()->doTurn(_board);
            } while(turnIsNotValid());
        }


        auto terminateTurn() -> void {
            updateBoard();
            printGameOverMessageIfGameIsOver();
        }

        auto turnIsNotValid()-> bool {
            if( isTurnValid()) return false;
            write("Ungueltiger Zug");
            return true;
        }


        auto printGameOverMessageIfGameIsOver() -> void {
            if(isGameOver()) {
                write(getCurrentPlayer()->getName() + " hat verloren.");
            }
        }


        PLAYERS players;
        PLAYER _currentPlayer;
        atlas::io::Writer &writer;
        BOARD _board;
        TURN _turn;

        void setCurrentPlayer(const PLAYER currentPlayer) {
            AbstractGame::_currentPlayer = currentPlayer;
        }




    protected:

        BOARD getBoard() const {
            return _board;
        }

        void setBoard(BOARD board) {
            _board = board;
        }

        TURN getTurn() const {
            return _turn;
        }

        void setTurn(TURN turn) {
            _turn = turn;
        }
        virtual auto updateBoard()-> void = 0;

        virtual auto isGameOver()->bool = 0;

        virtual auto isTurnValid() const -> bool = 0;

        const PLAYER getCurrentPlayer() const {
            return _currentPlayer;
        }

        const PLAYERS &getPlayers() const {
            return players;
        }

        auto write(std::string message)->void {
            writer.write(message);
        }

    };
}
