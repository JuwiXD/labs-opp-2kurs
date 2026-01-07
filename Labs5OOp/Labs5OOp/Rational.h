#pragma once
#include "Pair.h"

class Rational : public Pair {
private:
    int gcd(int x, int y);
    void normalize();
public:
    
    Rational();
    Rational(int _a, int _b);
    Rational(const Rational& other);

    Pair* add(const Pair* other);
    Pair* sub(const Pair* other);
    Rational* mul(const Rational* other);
    Rational* div(const Rational* other);

    bool less(const Rational* other);
    bool greater(const Rational* other);
    std::string to_string();
};