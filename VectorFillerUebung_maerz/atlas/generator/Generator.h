//
// Created by JoachimWagner on 12.03.2025.
//

#pragma once

namespace atlas::generator {
    template<class T>
    class Generator {
    public:
        virtual ~Generator() = default;
        virtual auto next()-> T= 0;
    };
}
