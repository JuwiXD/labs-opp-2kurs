#include "Rational.h"
#include <math.h>

int Rational::gcd(int x, int y){
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
		throw std::invalid_argument("«наменатель не может быть нулем");
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


Rational::Rational(int _a, int _b) : Pair(_a, _b) { normalize(); }


Rational::Rational(const Rational& other) : Pair(other) { normalize(); }

Rational& Rational::operator=(const Rational& other) {
	Pair::operator=(other);
	normalize();
	return *this;
}

Rational Rational::operator+(const Rational& other) {
	Rational result(
		(*a) * (*other.b) + (*b) * (*other.a),
		(*b) * (*other.b)
	);
	result.normalize();
	return result;
}

Rational Rational::operator/(const Rational& other) {
	Rational result(
		(*a) * (*other.b),
		(*b) * (*other.a)
	);
	result.normalize();
	return result;
}
Rational Rational::operator*(const Rational& other) {
	Rational result(
		(*a) * (*other.a),
		(*b) * (*other.b)
	);
	result.normalize();
	return result;
}


Rational Rational::operator-(const Rational& other) {
	Rational result(
		((*a) * (*other.b) - (*b) * (*other.a)),
		(*b) * (*other.b)
	);
	result.normalize();
	return result;
}
bool Rational::operator<(const Rational& other) {
	return (*a * *other.b)<(*other.a* *b);
}
bool Rational::operator>(const Rational& other) {
	return (*a * *other.b) > (*other.a * *b);
}
std::string Rational::to_string() {
	return std::to_string(*a) + "/" + std::to_string(*b);
}

std::ostream& operator<<(std::ostream& os, Rational& rational) {
	os << rational.to_string();
	return os;
}

std::istream& operator>>(std::istream& is, Rational& rational) {
	std::cout << "¬ведите числитель: ";
	is >> *rational.a;
	std::cout << "введите знаменатель: ";
	is >> *rational.b;
	rational.normalize();
	return is;
}