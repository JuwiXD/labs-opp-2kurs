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

	Rational& operator=(const Rational& other);


	Rational operator+(const Rational& other);
	Rational operator/(const Rational& other);
	Rational operator*(const Rational& other);
	Rational operator-(const Rational& other);
	bool operator<(const Rational& other);
	bool operator>(const Rational& other);
	std::string to_string();
	friend std::ostream& operator<<(std::ostream& os, Rational& rational);
	friend std::istream& operator>>(std::istream& is, Rational& rational);
};
