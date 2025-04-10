//
// Created by JoachimWagner on 09.04.2025.
//

#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include "../client/impl/ClientImpl.h"
#include "../container/impl/sequential/VectorFactorySequentialImpl.h"
#include "../generator/impl/random/MersenneTwisterNumberGenerator.h"
#include "../container/impl/decorator/VectorFactoryBenchmarkDekorator.h"
#include "../time/impl/StopwatchImpl.h"

namespace atlas::bootstrap {

    using VECTOR_FACTORY = std::unique_ptr<atlas::container::VectorFactory<int>>;
    using GENERATOR = std::unique_ptr<generator::Generator<int>>;
    using CLIENT = std::unique_ptr<atlas::client::Client>;

    class Bootstrap {

    public:

        auto startApplication() -> void {
            std::cout << "Starte Appplication\n";
            auto generator = createGenerator();
            auto factory = createVectorFactory(std::move(generator));
            auto client = createClient(std::move(factory));
            client->doSomethingWithLargeVector();
        }

    private:

        static GENERATOR createGenerator() {
            return std::make_unique<atlas::generator::MersenneTwisterNumberGenerator>();
        }

        static VECTOR_FACTORY createVectorFactory(GENERATOR generator) {
            VECTOR_FACTORY result = std::make_unique<atlas::container::VectorFactorySequentialImpl<int>>(std::move(generator));
            auto stopwatch = std::make_unique<atlas::time::StopwatchImpl>();
            result = std::make_unique<atlas::container::VectorFactoryBenchmarkDekorator<int>>(std::move(result), std::move(stopwatch));
            return result;
        }

        static CLIENT createClient(VECTOR_FACTORY factory) {
            return std::make_unique<atlas::client::ClientImpl>(std::move(factory));
        }
    };

} // atlas
