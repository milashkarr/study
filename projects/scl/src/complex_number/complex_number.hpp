#pragma once

#include "math.h"
#include <iostream>

namespace MAst {
    class Complex {
    private:
        double x;
        double y;

    public:
        Complex();
        Complex(double x, double y);

        Complex operator+ (const Complex&);
        Complex operator- (const Complex&);
        Complex operator* (const Complex&);
        Complex operator/ (const Complex&);

        bool operator==(const Complex& other) {
            return x == other.x && y == other.y;
        }

        void print();

        double getModule();
        double getArgument();
    };
}
