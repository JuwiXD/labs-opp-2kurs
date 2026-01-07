#pragma once
#include <string>
#include "Date.h"

class Payment {
private:
    std::string fullName;
    double salary;
    Date* hireDate;
    double bonusPercent;
    int workedDays;
    int workingDays;

public:
    Payment(const std::string& name, double sal, const Date& hire,
        double bonus, int wDays, int totalWDays);
    Payment(const Payment& other);
    ~Payment();

    void setFullName(const std::string& name);
    void setSalary(double sal);
    void setHireDate(const Date& hire);
    void setBonusPercent(double bonus);
    void setWorkedDays(int wDays);
    void setWorkingDays(int totalWDays);

    std::string getFullName();
    double getSalary();
    Date getHireDate();
    double getBonusPercent();
    int getWorkedDays();
    int getWorkingDays();

    double calculateAccruedAmount();
    double calculateWithheldAmount();
    double calculateNetSalary();
    int calculateExperience(Date& currentDate);

    double calculatePensionTax();
    double calculateIncomeTax();

    Payment& operator=(const Payment& other);
    bool operator==(Payment& other);
    bool operator!=(Payment& other);

    std::string toString(Date& currentDate);
    friend std::ostream& operator<<(std::ostream& os, Payment& payment);
    friend std::istream& operator>>(std::istream& is, Payment& payment);
};