#pragma once
#include <iostream>
#include <string>

template <typename T>
class DList;

template <typename T>
class Iterator {
private:
    typename DList<T>::Node* current;

public:
    Iterator(typename DList<T>::Node* node = nullptr);

    Iterator(const Iterator& other);

    Iterator& operator=(const Iterator& other);

    T& operator*();
    T* operator->();
    T get();
    void set(const T& value);

    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);

    bool operator==(const Iterator& other);
    bool operator!=(const Iterator& other);

    bool isValid();
    typename DList<T>::Node* getNode();

    std::string toString();

    friend std::ostream& operator<<(std::ostream& os, const Iterator<T>& it);
    friend std::istream& operator>>(std::istream& is, Iterator<T>& it);
};

template <typename T>
Iterator<T>::Iterator(typename DList<T>::Node* node) : current(node) {}

template <typename T>
Iterator<T>::Iterator(const Iterator& other) : current(other.current) {}

template <typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator& other)
{
    if (this != &other) {
        current = other.current;
    }
    return *this;
}

template <typename T>
T& Iterator<T>::operator*()
{
    return current->data;
}

template <typename T>
T* Iterator<T>::operator->()
{
    return &(current->data);
}

template <typename T>
T Iterator<T>::get()
{
    return current->data;
}

template <typename T>
void Iterator<T>::set(const T& value)
{
    if (current) current->data = value;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
    if (current) current = current->next; return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator temp = *this; ++(*this); return temp;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--()
{
    if (current) current = current->prev; return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int)
{
    Iterator temp = *this; --(*this); return temp;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator& other)
{
    return current == other.current;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator& other)
{
    return current != other.current;
}

template <typename T>
bool Iterator<T>::isValid()
{
    return current != nullptr;
}

template <typename T>
typename DList<T>::Node* Iterator<T>::getNode() { return current; }

template <typename T>
std::string Iterator<T>::toString() {
    if (!current) return "Итератор: недействителен";
    return "Итератор: [" + std::to_string(current->data) + "]";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Iterator<T>& it)
{
    if (it.current) os << it.current->data;
    else os << "недействителен";
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Iterator<T>& it)
{
    if (it.current) is >> it.current->data;
    return is;
}