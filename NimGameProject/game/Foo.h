//
// Created by JoachimWagner on 11.03.2025.
//

#pragma once


#include <ostream>

class Punkt {
private:
    int x{0};
    int y{0};

public:
    int getX() const {
        return x;
    }

    void setX(int x) {
        Punkt::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Punkt::y = y;
    }

    bool operator==(const Punkt &rhs) const {
        return x == rhs.x &&
               y == rhs.y;
    }

    bool operator!=(const Punkt &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Punkt &punkt) {
        os << "x: " << punkt.x << " y: " << punkt.y;
        return os;
    }
};
