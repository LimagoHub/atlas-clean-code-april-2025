//
// Created by JoachimWagner on 13.03.2025.
//

#pragma once

#include <iostream>
#include "../../VectorFactory.h"
#include "../sequential/VectorFactorySequentialImpl.h"
#include "../parallel/VectorFactoryParallelImpl.h"
//#include "../parallel/VectorFactoryAutoImpl.h"
#include "../decorator/VectorFactoryBenchmarkDecorator.h"
#include "../decorator/VectorFactoryLoggerDecorator.h"
#include "../decorator/VectorFactorySecureDecorator.h"
#include "../../../generator/GeneratorBuilder.h"
#include "../../../time/impl/StopwatchImpl.h"
#include "../parallel/VectorFactoryAutoImpl.h"

namespace atlas::container {

    template<class T>
    class VectorFactoryBuilder {
        using VECTOR_FACTORY = std::unique_ptr<atlas::container::VectorFactory<T>>;
        using VECTOR_FACTORY_SEQUENCIAL = atlas::container::VectorFactorySequentialImpl<T>;
        using VECTOR_FACTORY_PARALLEL = atlas::container::VectorFactoryParallelImpl<T>;

        using VECTOR_FACTORY_AUTO = atlas::container::VectorFactoryAutoImpl<T>;

        using VECTOR_FACTORY_BENCHMARK = atlas::container::VectorFactoryBenchmarkDecorator<T>;
        using VECTOR_FACTORY_LOGGER = atlas::container::VectorFactoryLoggerDecorator<T>;
        using VECTOR_FACTORY_SECURE = atlas::container::VectorFactorySecureDecorator<T>;

        using STOPWATCH = std::unique_ptr<atlas::time::Stopwatch>;
        using GENERATOR_BUILDER = std::unique_ptr<atlas::generator::GeneratorBuilder<T>>;

    public:

        static VECTOR_FACTORY createWithGeneratorBuilder(GENERATOR_BUILDER generatorBuilder) {
            VECTOR_FACTORY result;
            result = createStrategie(std::move(generatorBuilder), std::move(result));
            result = decorateFactory(std::move(result));
            return result;
        }
        static VECTOR_FACTORY createStrategie(GENERATOR_BUILDER generatorBuilder, VECTOR_FACTORY result) {

            switch(_threadCount) {
                case 0: result = std::make_unique<VECTOR_FACTORY_AUTO >(std::move(generatorBuilder)); break;
                case 1:  result = std::make_unique<VECTOR_FACTORY_SEQUENCIAL>(std::move(generatorBuilder->create())); break;
                default: result = std::make_unique<VECTOR_FACTORY_PARALLEL >(std::move(generatorBuilder), _threadCount); break;
            }
            return result;
        }
        static VECTOR_FACTORY decorateFactory(VECTOR_FACTORY result) {
            if(_secure) result = std::make_unique<VECTOR_FACTORY_SECURE >(std::move(result));

            if(_logger) result = std::make_unique<VECTOR_FACTORY_LOGGER >(std::move(result));

            if(_stopwatch) result = std::make_unique<VECTOR_FACTORY_BENCHMARK>(std::move(result), std::move(_stopwatch));
            return result;
        }



        static size_t getThreadCount() {
            return _threadCount;
        }

        static void setThreadCount(size_t threadCount) {
            _threadCount = threadCount;
        }



        static void setStopwatch(STOPWATCH stopwatch) {
            _stopwatch = std::move(stopwatch);
        }

        static bool isLogger() {
            return _logger;
        }

        static void setLogger(bool logger) {
            _logger = logger;
        }

        static bool isSecure() {
            return _secure;
        }

        static void setSecure(bool secure) {
            _secure = secure;
        }

    private:
        inline static size_t _threadCount{1};
        inline static bool _logger{false};
        inline static bool _secure{false};
        inline static STOPWATCH _stopwatch;
    };

}
