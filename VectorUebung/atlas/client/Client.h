//
// Created by JoachimWagner on 09.04.2025.
//

#pragma once

namespace atlas::client {

    class Client {
    public:
        virtual auto doSomethingWithLargeVector() -> void = 0;
    };

} // atlas
