#include "Pair.h"
Pair::Pair() {
	a = new int(0);
	b = new int(0);
}
Pair::Pair(int _a, int _b) :a(new int(_a)), b(new int(_b)) {}
Pair::Pair(const Pair& other) {
	a = new int(*other.a);
	b = new int(*other.b);
}
Pair& Pair::operator=(const Pair& other) {
	if (this != &other) {
		*a = *other.a;
		*b = *other.b;
	}
	return *this;
}
Pair::~Pair() {
	delete a;
	delete b;
}


void Pair::setA(int _a){
	*a = _a;
}

void Pair::setB(int _b)
{
	*b = _b;
}

int* Pair::getA()
{
	return a;
}

int* Pair::getB()
{
	return b;
}

bool Pair::operator==(const Pair& other)
{
	return (*a==*other.a) && (*b == *other.b);
}

bool Pair::operator!=(const Pair& other)
{
	return !(*this==other);
}

Pair Pair::operator-(const Pair& other)
{
	return Pair(*a-*other.a,*b-*other.b);
}
Pair Pair::operator+(const Pair& other)
{
	return Pair(*a + *other.a, *b + *other.b);
}

std::string Pair::to_string()
{
	return "("+std::to_string(*a)+","+ std::to_string(*b)+")";
}

std::ostream& operator<<(std::ostream& os,Pair& pair)
{	
	os << pair.to_string();
	return os;
}

std::istream& operator>>(std::istream& is, Pair& pair)
{
	std::cout << "¬ведите а: ";
	is >> *pair.a;
	std::cout << "¬ведите b: ";
	is >> *pair.b;
	return is;
}


