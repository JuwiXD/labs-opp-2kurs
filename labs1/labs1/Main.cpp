#include <iostream>
#include "Time.h"

int main() {
    setlocale(LC_ALL, "");

    int choice;
    int hours, minutes, seconds;
    Time currentTime;
    Time anotherTime;

    std::cout << "Введите начальное время (часы минуты секунды): ";
    std::cin >> hours >> minutes >> seconds;
    currentTime = Time(hours, minutes, seconds);

    while (true) {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. Вывести время\n";
        std::cout << "2. Установить новое время\n";
        std::cout << "3. Разница с другим временем в секундах\n";
        std::cout << "4. Добавить секунды\n";
        std::cout << "5. Вычесть секунды\n";
        std::cout << "6. Перевести в секунды\n";
        std::cout << "7. Перевести в минуты\n";
        std::cout << "8. Сравнить с другим временем\n";
        std::cout << "9. Ввести время строкой (ЧЧ:ММ:СС)\n";
        std::cout << "10. Выйти из программы\n";
        std::cout << "Выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Текущее время: ";
            std::cout << currentTime.toStr();
            break;

        case 2:
            std::cout << "Введите новое время (часы минуты секунды): ";
            std::cin >> hours >> minutes >> seconds;
            currentTime.setHour(hours);
            currentTime.setMinute(minutes);
            currentTime.setSecond(seconds);
            std::cout << "Время установлено: ";
            break;

        case 3:
            std::cout << "Введите второе время для сравнения (часы минуты секунды): ";
            std::cin >> hours >> minutes >> seconds;
            anotherTime = Time(hours, minutes, seconds);
            std::cout << "Разница между ";
            std::cout << currentTime.toStr();
            std::cout << " и ";
            std::cout << anotherTime.toStr();
            std::cout << ": " << currentTime.DiffBetwSeconds(anotherTime) << " секунд\n";
            break;

        case 4:
            std::cout << "Введите количество секунд для добавления: ";
            std::cin >> seconds;
            anotherTime = currentTime.addSeconds(seconds);
            std::cout << "Результат: ";
            std::cout << anotherTime.toStr();
            break;

        case 5:
            std::cout << "Введите количество секунд для вычитания: ";
            std::cin >> seconds;
            anotherTime = currentTime.subtractSeconds(seconds);
            std::cout << "Результат: ";
            std::cout << anotherTime.toStr();
            break;

        case 6:
            std::cout << "Время в секундах: " << currentTime.toSeconds() << " сек\n";
            break;

        case 7:
            std::cout << "Время в минутах: " << currentTime.toMinute() << " мин\n";
            break;

        case 8:
            std::cout << "Введите время для сравнения (часы минуты секунды): ";
            std::cin >> hours >> minutes >> seconds;
            anotherTime = Time(hours, minutes, seconds);
            if (currentTime.compare(anotherTime))
                std::cout << "Первое больше или равно второму\n";
            else
                std::cout << "Второе больше первого\n";

            break;
        case 9:
        {
            std::string timeStr;
            std::cout << "Введите время (формат ЧЧ:ММ:СС): ";
            std::cin.ignore();
            std::getline(std::cin, timeStr);
            currentTime = Time(timeStr);
            std::cout << "Время установлено: ";
            currentTime.toStr();
        }
        break;

        case 10:
            std::cout << "Выход из программы...\n";
            return 0;
        default:
            std::cout << "Неверная операция!\n";
            break;
        }
    }
}