cmake_minimum_required(VERSION 3.30)
project(NimGameProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(NimGameProject main.cpp
        game/Game.h
        client/GameClient.h
        game/nimgame/NimGame.h
        game/nimgame/player/AbstractNimGamePlayer.h
        game/nimgame/player/HumanPlayer.h
        game/nimgame/player/ComputerPlayer.h
        io/Writer.h
        io/ConsoleWriter.h
        game/player/Player.h
        game/AbstractGame.h
        game/Foo.h
)
