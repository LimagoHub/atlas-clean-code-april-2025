cmake_minimum_required(VERSION 3.30)
project(VectorFillerUebung)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectorFillerUebung main.cpp
        atlas/time/Stopwatch.h
        atlas/generator/Generator.h
        atlas/container/VectorFactory.h
        atlas/bootstrap/Bootstrap.h

        atlas/container/impl/decorator/VectorFactoryBenchmarkDecorator.h
        atlas/container/impl/builder/VectorFactoryBuilder.h)
