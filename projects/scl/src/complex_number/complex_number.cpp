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

Complex Complex :: operator + (const Complex& source) {
    return Complex(x + source.x, y + source.y);
}
Complex Complex :: operator - (const Complex& source) {
    return Complex(x - source.x, y - source.y);
}
Complex Complex::operator * (const Complex& source) {
    return Complex(x * source.x - y * source.y, x * source.y + y * source.x);
}

Complex Complex::operator / (const Complex& source) {
    return Complex(
		(x * source.x + y * source.y) / (source.x * source.x + source.y * source.y), 
		(y * source.x - x * source.y) / (source.x * source.x + source.y * source.y)
	); 
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
