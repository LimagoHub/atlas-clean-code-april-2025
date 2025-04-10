//
// Created by JoachimWagner on 09.04.2025.
//

#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include "../client/impl/ClientImpl.h"
#include "../container/impl/sequential/VectorFactorySequentialImpl.h"
#include "../container/impl/parallel/VectorFactoryParallelImpl.h"
#include "../generator/impl/random/MersenneTwisterNumberGeneratorFactory.h"
#include "../container/impl/decorator/VectorFactoryBenchmarkDekorator.h"
#include "../time/impl/StopwatchImpl.h"

namespace atlas::bootstrap {

    using VECTOR_FACTORY = std::unique_ptr<atlas::container::VectorFactory<int>>;
    using GENERATOR_BUILDER = std::unique_ptr<generator::GeneratorBuilder<int>>;
    using CLIENT = std::unique_ptr<atlas::client::Client>;

    class Bootstrap {

    public:

        auto startApplication() -> void {
            const size_t availableProcessors = std::thread::hardware_concurrency();

            for(size_t threadCount = 1; threadCount <= availableProcessors + 1; ++threadCount){
                std::cout << "Messung mit " << threadCount << " Threads" << std::endl;
                run(threadCount);
            }

        }

    private:

        static auto run(const size_t threadCount) -> void {
            std::cout << "Starte Appplication\n";
            auto generatorBuilder = createGeneratorBuilder();
            auto factory = createVectorFactory(std::move(generatorBuilder), threadCount);
            auto client = createClient(std::move(factory));
            client->doSomethingWithLargeVector();
        }

        static GENERATOR_BUILDER createGeneratorBuilder() {
            return std::make_unique<atlas::generator::MersenneTwisterNumberGeneratorFactory>();
        }

        static VECTOR_FACTORY createVectorFactory(GENERATOR_BUILDER generatorBuilder, const size_t threadCount) {
            VECTOR_FACTORY result;
            switch (threadCount) {
                case 1: result = std::make_unique<atlas::container::VectorFactorySequentialImpl<int>>(std::move(generatorBuilder->create()));
                        break;
                default:
                    result = std::make_unique<atlas::container::VectorFactoryParallelImpl<int>>(std::move(generatorBuilder), threadCount);
                        break;
            }

            auto stopwatch = std::make_unique<atlas::time::StopwatchImpl>();
            result = std::make_unique<atlas::container::VectorFactoryBenchmarkDekorator<int>>(std::move(result), std::move(stopwatch));
            return result;
        }

        static CLIENT createClient(VECTOR_FACTORY factory) {
            return std::make_unique<atlas::client::ClientImpl>(std::move(factory));
        }
    };

} // atlas
