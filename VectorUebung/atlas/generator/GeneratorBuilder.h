//
// Created by JoachimWagner on 11.04.2024.
//

#pragma once
#include <memory>
#include "Generator.h"
namespace atlas::generator {

        template<class T>
        class GeneratorBuilder {
        public:
            virtual ~GeneratorBuilder() = default;
            [[nodiscard]] virtual auto create() const->std::unique_ptr<Generator<T>> = 0;
        };


}
