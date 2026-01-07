#include "Set.h"

Set::Set() : data(nullptr), size(0) {}

Set::Set(int arr[], int n) : size(0) {
    data = new int[n];
    for (int i = 0; i < n; i++) {
        if (!isContain(arr[i])) {
            data[size++] = arr[i];
        }
    }
}

Set::Set(const Set& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

Set::~Set() {
    delete[] data;
}

Set& Set::operator=(const Set& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

bool Set::operator==(const Set& other) {
    if (size != other.size)
        return false;
    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < other.size; j++) {
            if (data[i] == other.data[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}



bool Set::operator<(const Set& other) {
    if (size >= other.size) return false;

    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < other.size; j++) {
            if (data[i] == other.data[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

bool Set::operator<=(const Set& other) {
    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < other.size; j++) {
            if (data[i] == other.data[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

bool Set::operator>(const Set& other) {
    if (other.size >= size) return false;

    for (int i = 0; i < other.size; i++) {
        bool found = false;
        for (int j = 0; j < size; j++) {
            if (other.data[i] == data[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}
bool Set::operator>=(const Set& other) {
    for (int i = 0; i < other.size; i++) {
        bool found = false;
        for (int j = 0; j < size; j++) {
            if (other.data[i] == data[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

Set Set::operator+(const Set& other) {
    Set result = *this;

    for (int i = 0; i < other.size; i++) {
        if (!result.isContain(other.data[i])) {
            result.add(other.data[i]);
        }
    }

    return result;
}

Set Set::operator-(const Set& other) {
    int* temp = new int[size];
    int total = 0;

    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < other.size; j++) {
            if (data[i] == other.data[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp[total++] = data[i];
        }
    }

    Set result(temp, total);
    delete[] temp;
    return result;
}

Set Set::operator*(const Set& other) {
    int* temp = new int[size];
    int total = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < other.size; j++) {
            if (data[i] == other.data[j]) {
                temp[total++] = data[i];
                break;
            }
        }
    }

    Set result(temp, total);
    delete[] temp;
    return result;
}

std::ostream& Set::operator<<(std::ostream& os) {
    os << "{ ";
    for (int i = 0; i < size; i++) {
        os << data[i];
        if (i < size - 1) os << ", ";
    }
    os << " }";
    return os;
}

std::istream& Set::operator>>(std::istream& is) {
    int count;
    std::cout << "Введите количество элементов: ";
    is >> count;

    *this = Set();

    std::cout << "Введите элементы: ";
    for (int i = 0; i < count; i++) {
        int value;
        is >> value;
        add(value);
    }
    return is;
}
Set Set::symmetricDifference(Set& other) {
    Set diff1 = *this - other;
    Set diff2 = other - *this;
    return diff1 + diff2;
}

bool Set::isEmpty() {
    return size == 0;
}

bool Set::isContain(int value) {
    for (int i = 0; i < size; i++) {
        if (data[i] == value)
            return true;
    }
    return false;
}

void Set::add(int value) {
    if (isContain(value)) return;

    int* newData = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    newData[size] = value;
    delete[] data;
    data = newData;
    size++;
}

void Set::remove(int value) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            index = i;
            break;
        }
    }
    if (index == -1) return;

    int* newData = new int[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newData[j++] = data[i];
        }
    }
    delete[] data;
    data = newData;
    size--;
}