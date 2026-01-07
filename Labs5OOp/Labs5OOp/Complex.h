#pragma once
#include "Pair.h"

class Complex : public Pair {
public:
    Complex();
    Complex(int real, int imag);
    Complex(const Complex& other);

    Pair* add(const Pair* other);
    Pair* sub(const Pair* other);
    Complex* mul(const Complex* other);
    Complex* div(const Complex* other);

    Complex conj();

    std::string to_string();
};