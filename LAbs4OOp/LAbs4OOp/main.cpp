#include <iostream>
#include "Pair.h"
#include "Rational.h"
//лаптев стр 67 номер 70
int main() {
    setlocale(0, "");
    int choice;
    std::cout << "Введите первую пару чисел:\n";
    Pair* currentPair = new Pair();
    std::cin >> *currentPair;
    Rational* currentRational = new Rational(*currentPair->getA(), *currentPair->getB());

    while (true) {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. Ввести новую пару чисел\n";
        std::cout << "2. Вывести текущую пару\n";
        std::cout << "3. Вычесть другую пару\n";
        std::cout << "4. сложить другую пару\n";
        std::cout << "5. Сравнить пары на равенство\n";
        std::cout << "6. Ввести новую дробь\n";
        std::cout << "7. Вывести текущую дробь\n";
        std::cout << "8. Сложить две дроби\n";
        std::cout << "9. Разделить две дроби\n";
        std::cout << "10. Вычесть две дроби\n";
        std::cout << "11. Сравнить дроби на равенство\n";
        std::cout << "12. Сравнить дроби\n";
        std::cout << "13. Выйти\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "\nВведите новую пару:\n";
            std::cin >> *currentPair;
            delete currentRational;
            currentRational = new Rational(*currentPair->getA(), *currentPair->getB());
            std::cout << "Пара сохранена!\n";
            break;
        }

        case 2: {
            std::cout << "\nТекущая пара: " << *currentPair << std::endl;
            break;
        }
        case 3: {
            Pair* another = new Pair();
            std::cout << "\nВведите вторую пару для вычитания:\n";
            std::cin >> *another;
            Pair result = *currentPair - *another;
            std::cout << "Результат: " << result << std::endl;
            delete another;
            break;
        }
        case 4: {
            Pair* another = new Pair();
            std::cout << "\nВведите вторую пару для вычитания:\n";
            std::cin >> *another;
            Pair result = *currentPair + *another;
            std::cout << "Результат: " << result << std::endl;
            delete another;
            break;
        }

        case 5: {
            Pair* another = new Pair();
            std::cout << "\nВведите вторую пару для сравнения:\n";
            std::cin >> *another;
            std::cout << "Первая пара: " << *currentPair << "\n";
            std::cout << "Вторая пара: " << *another << "\n";
            if (*currentPair == *another)
                std::cout << "Пары равны!\n";
            else
                std::cout << "Пары не равны!\n";
            delete another;
            break;
        }

        case 6: {
            std::cout << "\nВведите новую дробь:\n";
            std::cin >> *currentRational;
            delete currentPair;
            currentPair = new Pair(*currentRational->getA(), *currentRational->getB());
            std::cout << "Дробь сохранена!\n";
            break;
        }

        case 7: {
            std::cout << "\nТекущая дробь: " << *currentRational << std::endl;
            break;
        }

        case 8: {
            Rational* another = new Rational();
            std::cout << "\nВведите вторую дробь для сложения:\n";
            std::cin >> *another;
            Rational result = *currentRational + *another;
            std::cout << "Результат: " << result << std::endl;
            delete another;
            break;
        }

        case 9: {
            Rational* another = new Rational();
            std::cout << "\nВведите вторую дробь для деления:\n";
            std::cin >> *another;
            Rational result = *currentRational / *another;
            std::cout << "Результат: " << result << std::endl;
            delete another;
            break;
        }

        case 10: {
            Rational* another = new Rational();
            std::cout << "\nВведите вторую дробь для вычитания:\n";
            std::cin >> *another;
            Rational result = *currentRational - *another;
            std::cout << "Результат: " << result << std::endl;
            delete another;
            break;
        }

        case 11: {
            Rational* another = new Rational();
            std::cout << "\nВведите вторую дробь для сравнения:\n";
            std::cin >> *another;
            std::cout << "Первая дробь: " << *currentRational << "\n";
            std::cout << "Вторая дробь: " << *another << "\n";
            if (*currentRational == *another)
                std::cout << "Дроби равны!\n";
            else
                std::cout << "Дроби не равны!\n";
            delete another;
            break;
        }
        case 12: {
            Rational* another = new Rational();
            std::cout << "\nВведите вторую дробь для сравнения:\n";
            std::cin >> *another;
            std::cout << "Первая дробь: " << *currentRational << "\n";
            std::cout << "Вторая дробь: " << *another << "\n";
            if (*currentRational < *another)
                std::cout << "ПЕрвая дробь меньше!\n";
            else
                std::cout << "Вторая дробь меньше\n";
            delete another;
            break;
        }

        case 13:
            std::cout << "Выход из программы...\n";
            delete currentPair;
            delete currentRational;
            return 0;

        default:
            std::cout << "Неверный выбор!\n";
            break;
        }
    }
}