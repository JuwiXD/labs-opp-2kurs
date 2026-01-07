#pragma once
#include <string>
#include <iostream>

class Date {
    unsigned int* year;
    unsigned int* month;
    unsigned int* day;

    void normalizeDate();
    int daysInMonth(unsigned int _month, unsigned int _year);
    int toDays();  

public:
    Date(unsigned int _year, unsigned int _month, unsigned int _day);
    Date(const std::string& strDate);
    Date(const Date& other);
    ~Date();
    void setYear(unsigned int _year);
    void setMonth(unsigned int _month);
    void setDay(unsigned int _day);
    unsigned int* getYear();
    unsigned int* getMonth();
    unsigned int* getDay();

    bool isLeapYear();

    Date operator+(int days);
    Date operator-(int days);
   

    Date& operator=(const Date& other);
    Date& operator+=(int days);
    Date& operator-=(int days);

    bool operator==(Date& other);
    bool operator!=(Date& other);
    bool operator<(Date& other);
    bool operator<=(Date& other);
    bool operator>(Date& other);
    bool operator>=(Date& other);

    std::string toString();
    friend std::ostream& operator<<(std::ostream& os, Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);
};