//
// Created by JoachimWagner on 09.04.2025.
//

#pragma once
#include <memory>
#include <iostream>
#include "../Client.h"
#include "../../container/VectorFactory.h"
namespace atlas::client {

    class ClientImpl: public Client{
        using VECTOR = std::unique_ptr<atlas::container::VectorFactory<int> >;

    public:

        explicit ClientImpl(VECTOR factory) : factory_(std::move(factory)) {}

        auto doSomethingWithLargeVector() -> void override {
            auto vector = factory_->createAndFillVector(100);
            for (int i = 0; i < 3; ++i) {
                std::cout << vector->at(i) << "\n";
            }
        }

    private:
        VECTOR factory_;
    };

} // atlas
