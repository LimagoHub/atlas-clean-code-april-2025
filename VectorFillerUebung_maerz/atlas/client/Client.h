//
// Created by JoachimWagner on 29.01.2025.
//

#pragma once

namespace atlas::client {

    class Client {
    public:
        virtual ~Client() = default;
        virtual void doSomethingWithLargeVector() = 0;
    };

} // client
