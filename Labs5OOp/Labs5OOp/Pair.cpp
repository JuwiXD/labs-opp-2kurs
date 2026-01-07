#include "Pair.h"

Pair::Pair() {
    a = new int(0);
    b = new int(0);
}

Pair::Pair(int _a, int _b) : a(new int(_a)), b(new int(_b)) {}

Pair::Pair(const Pair& other) {
    a = new int(*other.a);
    b = new int(*other.b);
}


Pair::~Pair() {
    delete a;
    delete b;
}

Pair& Pair::operator=(const Pair& other) {
    if (this != &other) {
        *a = *other.a;
        *b = *other.b;
    }
    return *this;
}

void Pair::setA(int _a) {
    *a = _a;
}

void Pair::setB(int _b) {
    *b = _b;
}

int* Pair::getA() {
    return a;
}

int* Pair::getB(){
    return b;
}

std::string Pair::to_string() {
    return "(" + std::to_string(*a) + "," + std::to_string(*b) + ")";
}

std::ostream& operator<<(std::ostream& os,Pair& pair) {
    os << pair.to_string();
    return os;
}

std::istream& operator>>(std::istream& is, Pair& pair) {
    std::cout << "¬ведите a: ";
    is >> *pair.a;
    std::cout << "¬ведите b: ";
    is >> *pair.b;
    return is;
}