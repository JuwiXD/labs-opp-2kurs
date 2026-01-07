#pragma once
#include <iostream>
#include <string>

class Pair {
protected:
    int* a;
    int* b;
public:
    Pair();
    Pair(int _a, int _b);
    Pair(const Pair& other);
    virtual ~Pair();
    Pair& operator=(const Pair& other);

    void setA(int _a);
    void setB(int _b);
    int* getA();
    int* getB();


    virtual Pair* add(const Pair* other) = 0;
    virtual Pair* sub(const Pair* other) = 0;

    bool equ(const Pair* other);
    virtual std::string to_string();

    friend std::ostream& operator<<(std::ostream& os, Pair& pair);
    friend std::istream& operator>>(std::istream& is, Pair& pair);
};
