#include <iostream>
#include "Payment.h"
#include <Windows.h>

Payment createPaymentFromInput() {
    std::string name;
    double salary;
    unsigned int hireYear, hireMonth, hireDay;
    double bonus;
    int workedDays, workingDays;

    std::cout << "Введите ФИО: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Введите оклад: ";
    std::cin >> salary;

    std::cout << "Введите дату приема (год месяц день): ";
    std::cin >> hireYear >> hireMonth >> hireDay;

    std::cout << "Введите процент надбавки: ";
    std::cin >> bonus;

    std::cout << "Введите отработанные дни: ";
    std::cin >> workedDays;

    std::cout << "Введите рабочие дни в месяце: ";
    std::cin >> workingDays;

    return Payment(name, salary, Date(hireYear, hireMonth, hireDay), bonus, workedDays, workingDays);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;

    std::cout << " Система расчета зарплат \n";

    unsigned int year, month, day;
    std::cout << "Введите текущую дату для расчетов (год месяц день): ";
    std::cin >> year >> month >> day;
    Date currentDate(year, month, day);

    std::cout << "\n Ввод данных начального сотрудника \n";
    Payment currentPayment = createPaymentFromInput();

    while (true) {
        std::cout << "\nТекущая дата: " << currentDate << std::endl;
        std::cout << "Текущий сотрудник: " << currentPayment.getFullName() << std::endl;
        std::cout << "Выберите действие:\n";
        std::cout << "1. Вывести полную информацию о зарплате\n";
        std::cout << "2. Ввести данные нового сотрудника\n";
        std::cout << "3. Изменить данные текущего сотрудника\n";
        std::cout << "4. Рассчитать начисленную сумму\n";
        std::cout << "5. Рассчитать удержанную сумму\n";
        std::cout << "6. Рассчитать сумму на руки\n";
        std::cout << "7. Рассчитать стаж сотрудника\n";
        std::cout << "8. Показать отдельные составляющие зарплаты\n";
        std::cout << "9. Изменить текущую дату\n";
        std::cout << "10. Выйти из программы\n";
        std::cout << "Выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "\nПолная информация о зарплате \n";
            std::cout << currentPayment.toString(currentDate) << std::endl;
            break;

        case 2:
            std::cout << "\n Ввод данных нового сотрудника \n";
            currentPayment = createPaymentFromInput();
            std::cout << "Данные сотрудника сохранены!\n";
            break;

        case 3:
            std::cout << "\n Изменение данных сотрудника \n";
            std::cout << "Текущие данные:\n";
            std::cout << currentPayment.toString(currentDate) << std::endl;
            std::cout << "\nВыберите что изменить:\n";
            std::cout << "1. ФИО\n";
            std::cout << "2. Оклад\n";
            std::cout << "3. Дата приема\n";
            std::cout << "4. Процент надбавки\n";
            std::cout << "5. Отработанные дни\n";
            std::cout << "6. Рабочие дни в месяце\n";
            std::cout << "7. Отмена\n";
            std::cout << "Выбор: ";
            std::cin >> choice;

            switch (choice) {
            case 1: {
                std::string name;
                std::cout << "Введите новое ФИО: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                currentPayment.setFullName(name);
                std::cout << "ФИО изменено!\n";
                break;
            }
            case 2: {
                double salary;
                std::cout << "Введите новый оклад: ";
                std::cin >> salary;
                currentPayment.setSalary(salary);
                std::cout << "Оклад изменен!\n";
                break;
            }
            case 3: {
                std::cout << "Введите новую дату приема (год месяц день): ";
                unsigned int year, month, day;
                std::cin >> year >> month >> day;
                currentPayment.setHireDate(Date(year, month, day));
                std::cout << "Дата приема изменена!\n";
                break;
            }
            case 4: {
                double bonus;
                std::cout << "Введите новый процент надбавки: ";
                std::cin >> bonus;
                currentPayment.setBonusPercent(bonus);
                std::cout << "Надбавка изменена!\n";
                break;
            }
            case 5: {
                int workedDays;
                std::cout << "Введите новые отработанные дни: ";
                std::cin >> workedDays;
                currentPayment.setWorkedDays(workedDays);
                std::cout << "Отработанные дни изменены!\n";
                break;
            }
            case 6: {
                int workingDays;
                std::cout << "Введите новые рабочие дни в месяце: ";
                std::cin >> workingDays;
                currentPayment.setWorkingDays(workingDays);
                std::cout << "Рабочие дни изменены!\n";
                break;
            }
            case 7:
                std::cout << "Изменение отменено.\n";
                break;
            default:
                std::cout << "Неверный выбор!\n";
                break;
            }
            break;

        case 4:
            std::cout << "\n Начисленная сумма \n";
            std::cout << "Начислено: " << currentPayment.calculateAccruedAmount() << " руб.\n";
            break;

        case 5:
            std::cout << "\n Удержанная сумма\n";
            std::cout << "Удержано: " << currentPayment.calculateWithheldAmount() << " руб.\n";
            std::cout << "В том числе:\n";
            std::cout << "  - Пенсионный фонд (1%): " << currentPayment.calculatePensionTax() << " руб.\n";
            std::cout << "  - Подоходный налог (13%): " << currentPayment.calculateIncomeTax() << " руб.\n";
            break;

        case 6:
            std::cout << "\n Сумма на руки \n";
            std::cout << "К выдаче: " << currentPayment.calculateNetSalary() << " руб.\n";
            break;

        case 7:
            std::cout << "\nСтаж сотрудника\n";
            std::cout << "ФИО: " << currentPayment.getFullName() << "\n";
            std::cout << "Дата приема: " << currentPayment.getHireDate().toString() << "\n";
            std::cout << "Стаж на " << currentDate << ": "
                << currentPayment.calculateExperience(currentDate) << " год/года/лет\n";
            break;

        case 8: {
            std::cout << "\n Составляющие зарплаты\n";
            std::cout << "Оклад: " << currentPayment.getSalary() << " руб.\n";
            std::cout << "Надбавка: " << currentPayment.getBonusPercent() << "%\n";

            int fullWorkMonths = currentPayment.getWorkedDays() / currentPayment.getWorkingDays();
            int remainingDays = currentPayment.getWorkedDays() % currentPayment.getWorkingDays();
            std::cout << "Отработано дней: " << currentPayment.getWorkedDays() << "  при  "
                << currentPayment.getWorkingDays()<<" рабочих днях в месяц\n";

            std::cout << "Начислено: " << currentPayment.calculateAccruedAmount() << " руб.\n";
            std::cout << "Удержано: " << currentPayment.calculateWithheldAmount() << " руб.\n";
            std::cout << "На руки: " << currentPayment.calculateNetSalary() << " руб.\n";
            break;
        }

        case 9: {
            std::cout << "\n Изменение текущей даты \n";
            std::cout << "Текущая дата: " << currentDate << std::endl;
            std::cout << "Введите новую текущую дату (год месяц день): ";
            std::cin >> year >> month >> day;
            currentDate = Date(year, month, day);
            std::cout << "Дата изменена на: " << currentDate << std::endl;
            break;
        }
        case 10:
            std::cout << "Выход из программы...\n";
            return 0;

        default:
            std::cout << "Неверная операция!\n";
            break;
        }
    }
}
//17 63 стр лаптев