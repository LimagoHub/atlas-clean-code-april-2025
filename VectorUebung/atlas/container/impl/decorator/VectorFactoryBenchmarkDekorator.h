//
// Created by JoachimWagner on 09.04.2025.
//

#pragma once

#include <iostream>
#include "../../VectorFactory.h"
#include "../../../time/Stopwatch.h"
namespace atlas::container {

    template<class T>
    class VectorFactoryBenchmarkDekorator: public VectorFactory<T>{
        using VECTOR_POINTER = std::shared_ptr<std::vector<T>>;


    public:
        VectorFactoryBenchmarkDekorator(
                std::unique_ptr<VectorFactory<T>> vectorFactory,
                std::unique_ptr<atlas::time::Stopwatch> stopwatch) : _vectorFactory(
                std::move(vectorFactory)), _stopwatch(std::move(stopwatch)) {}

        auto createAndFillVector(const size_t size) noexcept -> VECTOR_POINTER override {
            _stopwatch->start();
            auto result =  _vectorFactory->createAndFillVector(size);
            _stopwatch->stop();
            std::cout << "Duration = " << _stopwatch->getDurationToMilliseconds().count() << std::endl;
            return result;
        }


    private:
        std::unique_ptr<VectorFactory<T>> _vectorFactory;
        std::unique_ptr<atlas::time::Stopwatch> _stopwatch;
    };

} // atlas
