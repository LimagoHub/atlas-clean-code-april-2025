#include <iostream>
#include "game/nimgame/NimGame.h"
#include "client/GameClient.h"
#include "io/ConsoleWriter.h"
#include "game/nimgame/player/HumanPlayer.h"
#include "game/nimgame/player/ComputerPlayer.h"
#include "game/nimgame/player/OmaPlayer.h"
using namespace atlas;
int main() {

    atlas::io::ConsoleWriter writer;
    atlas::game::nimgame::player::HumanPlayer human{"Fritz"};
    atlas::game::nimgame::player::ComputerPlayer computer{"Computer"};
    atlas::game::nimgame::player::OmaPlayer oma{"Gisela"};
    game::nimgame::NimGame game{writer};
    game.addPlayer(&human);
    game.addPlayer(&oma);
    game.addPlayer(&computer);
    client::GameClient client{game};
    client.go();

    return 0;
}

