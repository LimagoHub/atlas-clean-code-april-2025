//
// Created by JoachimWagner on 12.03.2025.
//

#pragma once

#include <memory>
#include <vector>

namespace atlas::container {
    template<class T>
    class VectorFactory {
        using VECTOR_POINTER = std::shared_ptr<std::vector<T>>;

    public:
        virtual ~VectorFactory() = default;
        virtual VECTOR_POINTER createAndFillVector(const size_t size) noexcept = 0;

    };
}
