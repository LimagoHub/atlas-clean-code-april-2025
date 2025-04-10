cmake_minimum_required(VERSION 3.30)
project(VectorUebung)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectorUebung main.cpp
        atlas/time/Stopwatch.h
        atlas/generator/Generator.h
        atlas/container/VectorFactory.h
        atlas/client/Client.h
        atlas/client/impl/ClientImpl.h
        atlas/bootstrap/Bootstrap.h
        atlas/generator/impl/random/MersenneTwisterNumberGenerator.h
        atlas/generator/IntGenerator.h
        atlas/generator/impl/random/ClassicRandomGenerator.h
        atlas/container/impl/sequential/VectorFactorySequentialImpl.h
        atlas/container/impl/decorator/VectorFactoryBenchmarkDekorator.h
        atlas/container/AbstractVectorFactory.h)
