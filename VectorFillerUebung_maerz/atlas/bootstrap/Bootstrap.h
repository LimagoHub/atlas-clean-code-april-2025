//
// Created by JoachimWagner on 12.03.2025.
//

#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include "../client/impl/ClientImpl.h"
#include "../container/impl/sequential/VectorFactorySequentialImpl.h"
#include "../container/impl/decorator/VectorFactoryBenchmarkDecorator.h"
#include "../container/impl/builder//VectorFactoryBuilder.h"
#include "../generator/impl/random/MersenneTwisterNumberGeneratorFactory.h"
#include "../time/impl/StopwatchImpl.h"


namespace atlas::bootstrap {
    class Bootstrap {

        using VECTOR_FACTORY = std::unique_ptr<atlas::container::VectorFactory<int>>;

        using VECTOR_FACTORY_BUILDER = atlas::container::VectorFactoryBuilder<int>;
        using GENERATOR_BUILDER = std::unique_ptr<generator::GeneratorBuilder<int>>;
        using STOPWATCH = std::unique_ptr<time::Stopwatch>;
        using CLIENT = std::unique_ptr<atlas::client::Client>;

    public:
        virtual ~Bootstrap() = default;

        auto startApplication()-> void {
            const size_t availableProcessors = std::thread::hardware_concurrency();

            for(size_t threadCount = 0; threadCount <= availableProcessors + 1; ++threadCount){
                std::cout << "Messung mit " << threadCount << " Threads" << std::endl;
                run(threadCount);
            }

        }

    private:

        static auto run(const int threadCount) -> void {
            auto generator = createGenerator();
            auto vectorFactory = createVectorFactory(std::move(generator), threadCount);
            auto client = createClient(std::move(vectorFactory));
            client->doSomethingWithLargeVector();
        }

        static GENERATOR_BUILDER createGenerator() {
            GENERATOR_BUILDER generatorBuilder = std::make_unique<atlas::generator::MersenneTwisterNumberGeneratorFactory>();
            return generatorBuilder;
        }

        static VECTOR_FACTORY createVectorFactory(GENERATOR_BUILDER generatorBuilder, const int threadCount) {
            VECTOR_FACTORY_BUILDER::setThreadCount(threadCount);
            VECTOR_FACTORY_BUILDER::setLogger(true);
            VECTOR_FACTORY_BUILDER::setSecure(true);
            VECTOR_FACTORY_BUILDER::setStopwatch(std::make_unique<time::StopwatchImpl>());
            return VECTOR_FACTORY_BUILDER::createWithGeneratorBuilder(std::move(generatorBuilder));

        }


        static CLIENT createClient(VECTOR_FACTORY factory) {
            CLIENT client = std::make_unique<atlas::client::VectorClientImpl>(std::move(factory));
            return client;
        }
    };
}
