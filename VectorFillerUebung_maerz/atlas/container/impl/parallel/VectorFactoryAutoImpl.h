//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once
#include <memory>
#include "../../AbstractVectorFactory.h"
#include "../../../generator/Generator.h"
#include "../../../generator/GeneratorBuilder.h"
#include <algorithm>
#include <execution>
namespace atlas::container {

    template<class T>
    class VectorFactoryAutoImpl : public AbstractVectorFactory<T>{
        using VECTOR = std::unique_ptr<std::vector<T> >;
        using MyGeneratorBuilder =  std::unique_ptr<generator::GeneratorBuilder<T>>;
        MyGeneratorBuilder generator_builder_;


    public:

        explicit VectorFactoryAutoImpl(MyGeneratorBuilder generatorBuilder) : generator_builder_(std::move(generatorBuilder)) {}

        ~VectorFactoryAutoImpl()  override = default;



    protected:
        auto fill_array() -> void override {
            auto generator_ = generator_builder_->create();
            auto field = this->getData();
            std::for_each( std::execution::par_unseq, this->getData()->begin(), this->getData()->end(),[&generator_](T &value){
                value = generator_->next();
            });


        }

    };

}
