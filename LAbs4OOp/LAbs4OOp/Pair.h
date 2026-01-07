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
	Pair& operator=(const Pair& other);
	~Pair();

	void setA(int _a);
	void setB(int _b);
	int* getA();
	int* getB();

	bool operator==(const Pair& other);
	bool operator!=(const Pair& other);
	Pair operator-(const Pair & other);
	Pair operator+(const Pair& other);

	std::string to_string();
	friend std::ostream& operator<<(std::ostream& os, Pair& pair);
	friend std::istream& operator>>(std::istream& is, Pair& pair);


};
