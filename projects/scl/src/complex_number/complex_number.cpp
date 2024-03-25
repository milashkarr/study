#include "complex_number.hpp"

using namespace MAst;

Complex::Complex() {
    this->x = 0.0;
    this->y = 0.0;
}

Complex::Complex(double x, double y) {
    this->x = x;
    this->y = y;
}

Complex Complex :: operator+ (const Complex& source) {
    Complex newComplex(x + source.x, y + source.y);
    return newComplex;
}
Complex Complex :: operator- (const Complex& source) {
    Complex newComplex(x - source.x, y - source.y);
    return newComplex;
}
Complex Complex :: operator* (const Complex& source) {
    Complex newComplex(x * source.x - y * source.y, x * source.y + y * source.x); // (a+bi)(c+di) = a*c-b*d + (a*d+b*c)i
    return newComplex;
}

Complex Complex :: operator/ (const Complex& source) {
    Complex newComplex((x * source.x + y * source.y) / (source.x * source.x + source.y * source.y), (y * source.x - x * source.y) / (source.x * source.x + source.y * source.y)); // (a+bi) : (c+di) = ((a*c+b*d) /(c**2 + d**2)) + ((b*c - a*d)/(c**2 + d**2))i
    return newComplex;
}

double Complex::getModule() {
    return sqrt(x * x + y * y);
}

double Complex::getArgument() {
    return atan2(y, x);
}

void Complex::print() {
    std::cout << x << "+i" << y << std::endl;
}

void _tmain() {
    Complex a(7.0, 6.0), b(2.0, 4.0), c;
    c = a * b;
    c.print();
}
