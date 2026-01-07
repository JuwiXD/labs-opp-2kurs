#include "Payment.h"
#include <iostream>

Payment::Payment(const std::string& name, double sal, const Date& hire,
    double bonus, int wDays, int totalWDays)
    : fullName(name), salary(sal), bonusPercent(bonus),
    workedDays(wDays), workingDays(totalWDays) {
    hireDate = new Date(hire);
}

Payment::Payment(const Payment& other)
    : fullName(other.fullName), salary(other.salary),
    bonusPercent(other.bonusPercent), workedDays(other.workedDays),
    workingDays(other.workingDays) {
    hireDate = new Date(*other.hireDate);
}

Payment::~Payment() {
    delete hireDate;
}

void Payment::setFullName(const std::string& name) {
    fullName = name;
}

void Payment::setSalary(double sal) {
    salary = sal;
}

void Payment::setHireDate(const Date& hire) {
    *hireDate = hire;
}

void Payment::setBonusPercent(double bonus) {
    bonusPercent = bonus;
}

void Payment::setWorkedDays(int wDays) {
    workedDays = wDays;
}

void Payment::setWorkingDays(int totalWDays) {
    workingDays = totalWDays;
}

std::string Payment::getFullName() { return fullName; }
double Payment::getSalary() { return salary; }
Date Payment::getHireDate() { return *hireDate; }
double Payment::getBonusPercent() { return bonusPercent; }
int Payment::getWorkedDays() { return workedDays; }
int Payment::getWorkingDays() { return workingDays; }

double Payment::calculateAccruedAmount() {
    if (workingDays == 0) return 0.0;
    double baseAmount = (salary / workingDays) * workedDays;
    double bonusAmount = baseAmount * (bonusPercent / 100.0);
    return baseAmount + bonusAmount;
}

double Payment::calculatePensionTax() {
    return calculateAccruedAmount() * 0.01;
}

double Payment::calculateIncomeTax() {
    double baseForTax = calculateAccruedAmount() - calculatePensionTax();
    return baseForTax * 0.13;
}

double Payment::calculateWithheldAmount() {
    return calculatePensionTax() + calculateIncomeTax();
}

double Payment::calculateNetSalary() {
    return calculateAccruedAmount() - calculateWithheldAmount();
}

int Payment::calculateExperience(Date& currentDate) {
    int yearsDiff = currentDate.getYear() - hireDate->getYear();

    if (currentDate.getMonth() < hireDate->getMonth() ||
        (currentDate.getMonth() == hireDate->getMonth() &&
            currentDate.getDay() < hireDate->getDay())) {
        yearsDiff--;
    }

    return std::max(0, yearsDiff);
}

Payment& Payment::operator=(const Payment& other) {
    if (this != &other) {
        fullName = other.fullName;
        salary = other.salary;
        *hireDate = *other.hireDate;
        bonusPercent = other.bonusPercent;
        workedDays = other.workedDays;
        workingDays = other.workingDays;
    }
    return *this;
}

bool Payment::operator==(Payment& other) {
    return fullName == other.fullName &&
        salary == other.salary &&
        *hireDate == *other.hireDate;
}

bool Payment::operator!=(Payment& other) {
    return !(*this == other);
}

std::string Payment::toString(Date& currentDate) {
    double accrued = calculateAccruedAmount();
    double withheld = calculateWithheldAmount();
    double netSalary = calculateNetSalary();
    int experience = calculateExperience(currentDate);

    return "ФИО: " + fullName + "\n" +
        "Оклад: " + std::to_string(salary) + " руб.\n" +
        "Дата приема: " + hireDate->toString() + "\n" +
        "Стаж: " + std::to_string(experience) + " год/года/лет\n" +
        "Надбавка: " + std::to_string(bonusPercent) + "%\n" +
        "Отработано: " + std::to_string(workedDays) + " при " + std::to_string(workingDays) +" рабочих днях в месяц\n"+
        "Начислено: " + std::to_string(accrued) + " руб.\n" +
        "Удержано: " + std::to_string(withheld) + " руб.\n" +
        "На руки: " + std::to_string(netSalary) + " руб.";
}

std::ostream& operator<<(std::ostream& os, Payment& payment) {
    int fullWorkMonths = payment.workedDays / payment.workingDays;
    int remainingDays = payment.workedDays % payment.workingDays;

    os << "ФИО: " << payment.fullName << "\n"
        << "Оклад: " << payment.salary << " руб.\n"
        << "Дата приема: " << *payment.hireDate << "\n"
        << "Надбавка: " << payment.bonusPercent << "%\n"
        << "Отработано: " << payment.workedDays << " при " << payment.workingDays<<" рабочих днях в месяц\n"
        << "Начислено: " << payment.calculateAccruedAmount() << " руб.\n"
        << "Удержано: " << payment.calculateWithheldAmount() << " руб.\n"
        << "На руки: " << payment.calculateNetSalary() << " руб.";

    return os;
}

std::istream& operator>>(std::istream& is, Payment& payment) {
    std::string name;
    double salary;
    std::string hireDateStr;
    double bonus;
    int workedDays, workingDays;

    std::cout << "Введите ФИО: ";
    is.ignore();
    std::getline(is, name);

    std::cout << "Введите оклад: ";
    is >> salary;

    std::cout << "Введите дату приема (гггг.мм.дд): ";
    is >> hireDateStr;

    std::cout << "Введите процент надбавки: ";
    is >> bonus;

    std::cout << "Введите отработанные дни: ";
    is >> workedDays;

    std::cout << "Введите рабочие дни в месяце: ";
    is >> workingDays;

    payment = Payment(name, salary, Date(hireDateStr), bonus, workedDays, workingDays);
    return is;
}