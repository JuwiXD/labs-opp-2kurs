#include "Date.h"
#include <cmath>

Date::Date(unsigned int _year, unsigned int _month, unsigned int _day) {
    year = new unsigned int(_year);
    month = new unsigned int(_month);
    day = new unsigned int(_day);
    normalizeDate();
}

Date::Date(const std::string& strDate) {
    if (strDate.length() == 10 && strDate[4] == '.' && strDate[7] == '.') {
        year = new unsigned int(std::stoi(strDate.substr(0, 4)));
        month = new unsigned int(std::stoi(strDate.substr(5, 2)));
        day = new unsigned int(std::stoi(strDate.substr(8, 2)));
    }
    else {
        year = new unsigned int(2006);
        month = new unsigned int(3);
        day = new unsigned int(6);
    }
    normalizeDate();
}

Date::Date(const Date& other) {
    year = new unsigned int(*other.year);
    month = new unsigned int(*other.month);
    day = new unsigned int(*other.day);
}

Date::~Date() {
    delete year;
    delete month;
    delete day;
}

void Date::normalizeDate() {
    while (*month > 12) {
        *month -= 12;
        (*year)++;
    }
    while (*month < 1) {
        *month += 12;
        (*year)--;
    }

    while (*day > daysInMonth(*month, *year)) {
        unsigned int daysInCurrentMonth = daysInMonth(*month, *year);
        *day -= daysInCurrentMonth;
        (*month)++;
        if (*month > 12) {
            *month = 1;
            (*year)++;
        }
    }

    while (*day < 1) {
        (*month)--;
        if (*month < 1) {
            *month = 12;
            (*year)--;
        }
        *day += daysInMonth(*month, *year);
    }
}

bool Date::isLeapYear() {
    return (*year % 4 == 0 && *year % 100 != 0) || (*year % 400 == 0);
}

int Date::daysInMonth(unsigned int _month, unsigned int _year) {
    switch (_month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)) ? 29 : 28;
    default:
        return 30;
    }
}

int Date::toDays() {
    int totalDays = 0;

    for (unsigned int y = 1; y < *year; y++) {
        totalDays += ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ? 366 : 365;
    }

    for (unsigned int m = 1; m < *month; m++) {
        totalDays += daysInMonth(m, *year);
    }

    totalDays += *day;

    return totalDays;
}

void Date::setYear(unsigned int _year) {
    *year = _year;
    normalizeDate();
}

void Date::setMonth(unsigned int _month) {
    *month = _month;
    normalizeDate();
}

void Date::setDay(unsigned int _day) {
    *day = _day;
    normalizeDate();
}

unsigned int* Date::getYear() { return year; }
unsigned int* Date::getMonth() { return month; }
unsigned int* Date::getDay() { return day; }

Date Date::operator+(int days) {
    Date result(*this);
    *(result.day) += days;
    result.normalizeDate();
    return result;
}

Date Date::operator-(int days) {
    Date result(*this);
    *(result.day) -= days;
    result.normalizeDate();
    return result;
}



Date& Date::operator=(const Date& other) {
    if (this != &other) {
        *year = *other.year;
        *month = *other.month;
        *day = *other.day;
    }
    return *this;
}

Date& Date::operator+=(int days) {
    *day += days;
    normalizeDate();
    return *this;
}

Date& Date::operator-=(int days) {
    *day -= days;
    normalizeDate();
    return *this;
}

bool Date::operator==(Date& other) {
    return *year == *other.year && *month == *other.month && *day == *other.day;
}

bool Date::operator!=(Date& other) {
    return !(*this == other);
}

bool Date::operator<(Date& other) {
    if (*year != *other.year) return *year < *other.year;
    if (*month != *other.month) return *month < *other.month;
    return *day < *other.day;
}

bool Date::operator<=(Date& other) {
    return *this < other || *this == other;
}

bool Date::operator>(Date& other) {
    return !(*this <= other);
}

bool Date::operator>=(Date& other) {
    return !(*this < other);
}

std::string Date::toString() {
    return std::to_string(*year) + "." +
        (*month < 10 ? "0" : "") + std::to_string(*month) + "." +
        (*day < 10 ? "0" : "") + std::to_string(*day);
}

std::ostream& operator<<(std::ostream& os, Date& date) {
    os << date.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
    std::string input;
    is >> input;
    Date temp(input);
    date = temp;
    return is;
}