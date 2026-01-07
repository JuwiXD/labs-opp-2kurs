#include "Complex.h"
#include <cmath>

Complex::Complex(){}

Complex::Complex(int real, int imag) : Pair(real, imag) {}

Complex::Complex(const Complex& other) : Pair(other) {}


Pair* Complex::add(const Pair* other) {
    const Complex* otherComplex = dynamic_cast<const Complex*>(other);
    if (!otherComplex) {
        throw std::invalid_argument("Ошибка");
    }
    return new Complex(*a + *otherComplex->a, *b + *otherComplex->b);
}

Pair* Complex::sub(const Pair* other) {
    const Complex* otherComplex = dynamic_cast<const Complex*>(other);
    if (!otherComplex) {
        throw std::invalid_argument("Ошибка");
    }
    return new Complex(*a - *otherComplex->a, *b - *otherComplex->b);
}

Complex* Complex::mul(const Complex* other) {
    int real = (*a * *other->a) - (*b * *other->b);
    int imag = (*a * *other->b) + (*b * *other->a);
    return new Complex(real, imag);
}

Complex* Complex::div(const Complex* other) {
    int denominator = (*other->a * *other->a) + (*other->b * *other->b);
    if (denominator == 0) {
        throw std::runtime_error("Деление на ноль");
    }

    int real = ((*a * *other->a) + (*b * *other->b)) / denominator;
    int imag = ((*b * *other->a) - (*a * *other->b)) / denominator;

    return new Complex(real, imag);
}

Complex Complex::conj() {
    return Complex(*a, -(*b));
}

std::string Complex::to_string() {
    if (*b >= 0) {
        return "(" + std::to_string(*a) + " + " + std::to_string(*b) + "i)";
    }
    else {
        return "(" + std::to_string(*a) + " - " + std::to_string(std::abs(*b)) + "i)";
    }
}