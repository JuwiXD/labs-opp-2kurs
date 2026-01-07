#pragma once
#include <iostream>

class Set {
private:
    int* data;
    int size;

public:
    Set();
    Set(int arr[], int n);
    Set(const Set& other);
    ~Set();

    Set& operator=(const Set& other);

    bool operator==(const Set& other);
    bool operator<(const Set& other);
    bool operator<=(const Set& other);
    bool operator>(const Set& other);
    bool operator>=(const Set& other);

    std::ostream& operator<<(std::ostream& os);
    std::istream& operator>>(std::istream& is);

    Set operator+(const Set& other);
    Set operator-(const Set& other);
    Set operator*(const Set& other);



    Set symmetricDifference(Set& other);
    bool isEmpty();
    bool isContain(int value);
    void add(int value);
    void remove(int value);

    int getSize() { return size; }
};