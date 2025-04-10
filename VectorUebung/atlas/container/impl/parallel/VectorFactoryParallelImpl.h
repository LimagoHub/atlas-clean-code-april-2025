//
// Created by JoachimWagner on 10.04.2025.
//

#pragma once

#include <cmath>
#include <thread>
#include "../../AbstractVectorFactory.h"
#include "../../../generator/GeneratorBuilder.h"

namespace atlas::container {

    template<class T>
    class VectorFactoryParallelImpl: public AbstractVectorFactory<T> {
        using VECTOR = std::shared_ptr<std::vector<T> >;
        using MyGeneratorBuilder =  std::unique_ptr<generator::GeneratorBuilder<T>>;

        MyGeneratorBuilder generatorBuilder_;
        size_t thread_count_;
        std::size_t partitionSize_;
        std::vector<std::thread> threadHolder_;

    public:
        VectorFactoryParallelImpl(MyGeneratorBuilder generatorBuilder, size_t threadCount) : generatorBuilder_(std::move(generatorBuilder)), thread_count_(threadCount) {}

    protected:

        auto fill_array() -> void override {
            calculatePartitionSize();
            initializeThreadHolder();
            addWorkersToThreads();
            awaitThreadTermination();
        }
    private:
        void calculatePartitionSize() {
            partitionSize_ = static_cast<std::size_t>(std::floor(this->getSize() / thread_count_));
        }

        void initializeThreadHolder() {
            threadHolder_.reserve(thread_count_);
        }

        void addWorkersToThreads() {
            for (auto segment = 0U; segment < thread_count_; ++segment) {
                start_single_worker_for_segment( segment);
            }
        }

        void awaitThreadTermination() {
            for(auto & thread : threadHolder_) {
                thread.join();
            }
        }

        auto  start_single_worker_for_segment( const unsigned int segment) -> void {
            const size_t start = segment * partitionSize_;
            const size_t end = start + partitionSize_;
            threadHolder_.emplace_back(&VectorFactoryParallelImpl::fill_segment_worker, this, start,end);
        }

        auto fill_segment_worker(const std::size_t startIndex, const std::size_t endIndex)-> void {
            auto const generator = generatorBuilder_->create();
            auto field = this->getData();
            for (auto i = startIndex; i < endIndex; ++i) {
                field->at(i) = generator->next();
            }
        }
    };

} // atlas
