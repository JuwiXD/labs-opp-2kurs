#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Iterator.h"

template <typename T>
class DList {
public:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& _data) : data(_data), next(nullptr), prev(nullptr) {}
    };

private:
    Node* head;
    Node* tail;
    int size;

public:

    DList() : head(nullptr), tail(nullptr), size(0) {}
    ~DList() { clear(); }

    void clear();
    bool isEmpty();
    int getSize();
    void show();

    void addToTail(const T& data);
    void addToHead(const T& data);
    void addAfterElem(Iterator<T> it, const T& data);
    void addBeforeElem(Iterator<T> it, const T& data);

    void deleteFromTail();
    void deleteFromHead();
    void deleteElem(Iterator<T> it);

    Iterator<T> begin();
    Iterator<T> end();
    Iterator<T> rbegin();

    void deleteRange(Iterator<T> first, Iterator<T> last);

    void replaceRange(Iterator<T> first, Iterator<T> last, const T& newValue);

    void replaceRangeWithList(Iterator<T> first, Iterator<T> last, const DList<T>& other);

    Iterator<T> find(const T& value);

    bool findRange(const T& value1, const T& value2, Iterator<T>& outFirst, Iterator<T>& outLast);

    bool contains(const T& value);

    Iterator<T> findSequence(const DList<T>& sequence);

    bool containsSequence(const DList<T>& sequence);

    void unionWith(const DList<T>& other);
    void intersectWith(const DList<T>& other);
};
template <typename T>
Iterator<T> DList<T>::begin()
{
    return Iterator<T>(head);
}

template <typename T>
Iterator<T> DList<T>::end()
{
    return Iterator<T>(nullptr);
}
template <typename T>
Iterator<T> DList<T>::rbegin()
{
    return Iterator<T>(tail);
}
template <typename T>
void DList<T>::clear() {
    while (head) {
        deleteFromHead();
    }
}
template <typename T>
int DList<T>::getSize()
{
    return size;
}

template <typename T>
bool DList<T>::isEmpty() {
    return head == nullptr;
}

template <typename T>
void DList<T>::show() {
    if (isEmpty()) {
        std::cout << "Список пуст" << std::endl;
        return;
    }
    Node* current = head;
    std::cout << "[ ";
    while (current) {
        std::cout << current->data;
        if (current->next) std::cout << " <-> ";
        current = current->next;
    }
    std::cout << " ]" << std::endl;
}


template <typename T>
void DList<T>::addToHead(const T& data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <typename T>
void DList<T>::addToTail(const T& data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template <typename T>
void DList<T>::addAfterElem(Iterator<T> it, const T& data) {
    if (!it.isValid()) return;
    Node* ptr = it.getNode();
    Node* newNode = new Node(data);
    newNode->prev = ptr;
    newNode->next = ptr->next;
    if (ptr->next) {
        ptr->next->prev = newNode;
    }
    else {
        tail = newNode;
    }
    ptr->next = newNode;
    size++;
}

template <typename T>
void DList<T>::addBeforeElem(Iterator<T> it, const T& data) {
    if (!it.isValid()) return;
    Node* ptr = it.getNode();
    if (ptr == head) {
        addToHead(data);
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = ptr;
    newNode->prev = ptr->prev;
    ptr->prev->next = newNode;
    ptr->prev = newNode;
    size++;
}


template <typename T>
void DList<T>::deleteFromHead() {
    if (isEmpty()) return;
    Node* tmp = head;
    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
    }
    delete tmp;
    size--;
}

template <typename T>
void DList<T>::deleteFromTail() {
    if (isEmpty()) return;
    Node* tmp = tail;
    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete tmp;
    size--;
}

template <typename T>
void DList<T>::deleteElem(Iterator<T> it) {
    if (!it.isValid()) return;
    Node* ptr = it.getNode();
    if (ptr == head) {
        deleteFromHead();
        return;
    }
    if (ptr == tail) {
        deleteFromTail();
        return;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete ptr;
    size--;
}


template <typename T>
void DList<T>::deleteRange(Iterator<T> first, Iterator<T> last) {
    while (first != last && first.isValid()) {
        Iterator<T> toDelete = first;
        ++first;
        deleteElem(toDelete);
    }
}

template <typename T>
void DList<T>::replaceRange(Iterator<T> first, Iterator<T> last, const T& newValue) {
    if (!first.isValid()) return;
    Node* insertAfter = first.getNode()->prev;
    deleteRange(first, last);
    if (insertAfter == nullptr) {
        addToHead(newValue);
    }
    else {
        addAfterElem(Iterator<T>(insertAfter), newValue);
    }
}

template <typename T>
void DList<T>::replaceRangeWithList(Iterator<T> first, Iterator<T> last, const DList<T>& other) {
    if (!first.isValid()) return;

    if (other.head == nullptr) {
        deleteRange(first, last);
        return;
    }

    Node* insertAfter = first.getNode()->prev;
    deleteRange(first, last);

    Node* current = other.head;

    if (insertAfter == nullptr) {
        addToHead(current->data);
        insertAfter = head;
        current = current->next;
    }

    while (current) {
        addAfterElem(Iterator<T>(insertAfter), current->data);
        insertAfter = insertAfter->next;
        current = current->next;
    }
}


template <typename T>
Iterator<T> DList<T>::find(const T& value) {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return Iterator<T>(current);
        }
        current = current->next;
    }
    return end();
}

template <typename T>
bool DList<T>::findRange(const T& value1, const T& value2,
    Iterator<T>& outFirst, Iterator<T>& outLast) {
    outFirst = find(value1);
    if (!outFirst.isValid()) {
        return false;
    }
    Iterator<T> current = outFirst;
    while (current != end() && *current != value2) {
        ++current;
    }

    if (current == end() || *current != value2) {
        return false;
    }

    outLast = current;
    ++outLast;
    return true;
}
template <typename T>
bool DList<T>::contains(const T& value) {
    return find(value) != end();
}

template <typename T>
Iterator<T> DList<T>::findSequence(const DList<T>& sequence) {
    if (sequence.head == nullptr || head == nullptr) {
        return end();
    }

    Node* current = head;

    while (current) {
        Node* mainPtr = current;
        Node* seqPtr = sequence.head;
        bool found = true;

        while (seqPtr && mainPtr) {
            if (mainPtr->data != seqPtr->data) {
                found = false;
                break;
            }
            mainPtr = mainPtr->next;
            seqPtr = seqPtr->next;
        }

        if (found && seqPtr == nullptr) {
            return Iterator<T>(current);
        }

        current = current->next;
    }

    return end();
}

template <typename T>
bool DList<T>::containsSequence(const DList<T>& sequence) {
    return findSequence(sequence) != end();
}



template <typename T>
void DList<T>::unionWith(const DList<T>& other) {
    DList<T> result;
    Node* current = head;
    while (current) {
        if (!result.contains(current->data)) {
            result.addToTail(current->data);
        }
        current = current->next;
    }
    current = other.head;
    while (current) {
        if (!result.contains(current->data)) {
            result.addToTail(current->data);
        }
        current = current->next;
    }
    clear();
    current = result.head;
    while (current) {
        addToTail(current->data);
        current = current->next;
    }
}

template <typename T>
void DList<T>::intersectWith(const DList<T>& other) {
    DList<T> result;
    Node* current = head;
    while (current) {
        Node* otherCurrent = other.head;
        bool found = false;
        while (otherCurrent) {
            if (current->data == otherCurrent->data) {
                found = true;
                break;
            }
            otherCurrent = otherCurrent->next;
        }
        if (found && !result.contains(current->data)) {
            result.addToTail(current->data);
        }
        current = current->next;
    }
    clear();
    Node* resCurrent = result.head;
    while (resCurrent) {
        addToTail(resCurrent->data);
        resCurrent = resCurrent->next;
    }
}