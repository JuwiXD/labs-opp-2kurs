#include "Rational.h"
#include <cmath>

int Rational::gcd(int x, int y) {
    x = std::abs(x);
    y = std::abs(y);
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

void Rational::normalize() {
    if (*b == 0) {
        throw std::invalid_argument("Знаменатель не может быть нулем");
    }

    if (*a == 0) {
        *b = 1;
        return;
    }

    int common = gcd(*a, *b);
    *a /= common;
    *b /= common;

    if (*b < 0) {
        *a = -*a;
        *b = -*b;
    }
}

Rational::Rational(){}

Rational::Rational(int _a, int _b) : Pair(_a, _b) {
    normalize();
}

Rational::Rational(const Rational& other) : Pair(other) {
    normalize();
}

Pair* Rational::add(const Pair* other) {
    const Rational* otherRational = dynamic_cast<const Rational*>(other);
    if (!otherRational) {
        throw std::invalid_argument("Ошибка");
    }

    int new_num = (*a * *otherRational->b) + (*b * *otherRational->a);
    int new_den = *b * *otherRational->b;

    return new Rational(new_num, new_den);
}

Pair* Rational::sub(const Pair* other) {
    const Rational* otherRational = dynamic_cast<const Rational*>(other);
    if (!otherRational) {
        throw std::invalid_argument("Ошибка");
    }

    int new_num = (*a * *otherRational->b) - (*b * *otherRational->a);
    int new_den = *b * *otherRational->b;

    return new Rational(new_num, new_den);
}

Rational* Rational::mul(const Rational* other) {
    int new_num = *a * *other->a;
    int new_den = *b * *other->b;

    return new Rational(new_num, new_den);
}

Rational* Rational::div(const Rational* other) {
    if (*other->a == 0) {
        throw std::runtime_error("Деление на ноль");
    }

    int new_num = *a * *other->b;
    int new_den = *b * *other->a;

    return new Rational(new_num, new_den);
}


bool Rational::greater(const Rational* other) {
    const Rational* otherRational = dynamic_cast<const Rational*>(other);
    if (!otherRational) return false;
    return (*a * *otherRational->b) > (*otherRational->a * *b);
}

bool Rational::less(const Rational* other) {
    const Rational* otherRational = dynamic_cast<const Rational*>(other);
    if (!otherRational) return false;
    return (*a * *otherRational->b) < (*otherRational->a * *b);
}

std::string Rational::to_string() {
    return std::to_string(*a) + "/" + std::to_string(*b);
}

bool Pair::equ(const Pair* other) {
    return (*a == *other->a) && (*b == *other->b);
}