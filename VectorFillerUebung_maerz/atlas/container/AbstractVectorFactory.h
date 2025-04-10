//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once

#pragma once
#include "VectorFactory.h"
namespace atlas::container {


    template<class T>
    class AbstractVectorFactory: public VectorFactory<T>{
        using VECTOR = std::shared_ptr<std::vector<T> >;

        VECTOR data_;
        size_t size_;

    protected:
        AbstractVectorFactory() = default;

        auto getData()  -> VECTOR {
            return data_;
        }

        auto getSize() -> size_t const {
            return size_;
        }

        virtual auto fill_array() -> void = 0;
    public:

        ~AbstractVectorFactory() override = default;

        auto createAndFillVector(size_t size) noexcept-> VECTOR override final {
            data_ = std::make_shared<std::vector<T>>(size);
            size_ = size;
            fill_array();
            return data_;
        }
    };

} // collections
