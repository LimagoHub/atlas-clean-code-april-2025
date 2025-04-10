//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once
#include <memory>
#include "../../AbstractVectorFactory.h"
#include "../../../generator/Generator.h"

namespace atlas::container {

    template<class T>
    class VectorFactorySequentialImpl : public AbstractVectorFactory<T>{
        using VECTOR = std::shared_ptr<std::vector<T> >;
        using MyGenerator =  std::unique_ptr<generator::Generator<T>>;
        MyGenerator generator_;


    public:

        explicit VectorFactorySequentialImpl(MyGenerator generator) : generator_(std::move(generator)) {}

        ~VectorFactorySequentialImpl()  override = default;



    protected:
        auto fill_array() -> void override {
            auto field = this->getData();
            for (size_t i = 0; i < this->getSize(); ++i) {
                field->at(i) = generator_->next();
            }
        }

    };

}
