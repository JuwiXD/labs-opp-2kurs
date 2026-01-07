#include "Pair.h"
#include "Rational.h"
#include "Complex.h"
#include <iostream>

int main() {
    setlocale(0, "");

    Pair* rational = nullptr;
    Pair* complex = nullptr;

    int choice;

    while (true) {
        std::cout << "\nМеню действий:\n";
        std::cout << "1. Ввести дробь\n";
        std::cout << "2. Ввести комплексное число\n";
        std::cout << "3. Показать дробь\n";
        std::cout << "4. Показать комплексное число\n";
        std::cout << "5. Арифметические операции с дробью\n";
        std::cout << "6. Арифметические операции с комплексным числом\n";
        std::cout << "7. Сравнить дроби\n";
        std::cout << "8. Сравнить комплексные числа\n";
        std::cout << "9. Выйти\n";
        std::cout << "Выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            if (rational) {
                delete rational;
            }
            int num, den;
            std::cout << "Введите числитель: ";
            std::cin >> num;
            std::cout << "Введите знаменатель: ";
            std::cin >> den;
            try {
                rational = new Rational(num, den);
                std::cout << "Дробь создана: " << *rational << std::endl;
            }
            catch (std::exception& error) {
                std::cout << "Ошибка: " << error.what() << std::endl;
                rational = nullptr;
            }
            break;
        }
        case 2: {
            if (complex) {
                delete complex;
            }
            int real, imag;
            std::cout << "Введите действительную часть: ";
            std::cin >> real;
            std::cout << "Введите мнимую часть: ";
            std::cin >> imag;
            complex = new Complex(real, imag);
            std::cout << "Комплексное число создано: " << *complex << std::endl;
            break;
        }
        case 3:
            if (rational)
                std::cout << "Дробь: " << *rational << std::endl;
            else
                std::cout << "Дробь еще не введена!\n";
            break;
        case 4:
            if (complex)
                std::cout << "Комплексное число: " << *complex << std::endl;
            else
                std::cout << "Комплексное число еще не введено!\n";
            break;
        case 5: {
            if (!rational) {
                std::cout << "Сначала введите дробь!\n";
                break;
            }

            int num, den;
            std::cout << "Введите вторую дробь:\n";
            std::cout << "Введите числитель: ";
            std::cin >> num;
            std::cout << "Введите знаменатель: ";
            std::cin >> den;

            Pair* other = nullptr;
            try {
                other = new Rational(num, den);

                int op;
                std::cout << "Выберите операцию: 1 +  2 -  3 *  4 / : ";
                std::cin >> op;

                Pair* result = nullptr;
                try {
                    if (op == 1) result = rational->add(other);
                    else if (op == 2) result = rational->sub(other);
                    else if (op == 3) {
                        Rational* rat1 = dynamic_cast<Rational*>(rational);
                        Rational* rat2 = dynamic_cast<Rational*>(other);
                        if (rat1 && rat2) {
                            Rational* mulResult = rat1->mul(rat2);
                            result = mulResult;
                        }
                    }
                    else if (op == 4) {
                        Rational* rat1 = dynamic_cast<Rational*>(rational);
                        Rational* rat2 = dynamic_cast<Rational*>(other);
                        if (rat1 && rat2) {
                            Rational* divResult = rat1->div(rat2);
                            result = divResult;
                        }
                    }
                    else {
                        std::cout << "Неверная операция!\n";
                    }

                    if (result) {
                        std::cout << "Результат: " << *result << std::endl;
                        delete result;
                    }
                }
                catch (std::exception& error) {
                    std::cout << "Ошибка: " << error.what() << std::endl;
                }
            }
            catch (std::exception& error) {
                std::cout << "Ошибка создания дроби: " << error.what() << std::endl;
            }

            if (other) delete other;
            break;
        }
        case 6: {
            if (!complex) {
                std::cout << "Сначала введите комплексное число!\n";
                break;
            }

            int real, imag;
            std::cout << "Введите второе комплексное число:\n";
            std::cout << "Введите действительную часть: ";
            std::cin >> real;
            std::cout << "Введите мнимую часть: ";
            std::cin >> imag;
            Pair* other = new Complex(real, imag);

            int op;
            std::cout << "Выберите операцию: 1 +  2 -  3 *  4 / : ";
            std::cin >> op;

            Pair* result = nullptr;
            try {
                if (op == 1) result = complex->add(other);
                else if (op == 2) result = complex->sub(other);
                else if (op == 3) {
                    Complex* comp1 = dynamic_cast<Complex*>(complex);
                    Complex* comp2 = dynamic_cast<Complex*>(other);
                    if (comp1 && comp2) {
                        Complex* mulResult = comp1->mul(comp2);
                        result = mulResult;
                    }
                }
                else if (op == 4) {
                    Complex* comp1 = dynamic_cast<Complex*>(complex);
                    Complex* comp2 = dynamic_cast<Complex*>(other);
                    if (comp1 && comp2) {
                        Complex* divResult = comp1->div(comp2);
                        result = divResult;
                    }
                }
                else {
                    std::cout << "Неверная операция!\n";
                }

                if (result) {
                    std::cout << "Результат: " << *result << std::endl;
                    delete result;
                }
            }
            catch (std::exception& error) {
                std::cout << "Ошибка: " << error.what() << std::endl;
            }

            delete other;
            break;
        }
        case 7: {
            if (!rational) {
                std::cout << "Сначала введите дробь!\n";
                break;
            }

            int num, den;
            std::cout << "Введите вторую дробь для сравнения:\n";
            std::cout << "Введите числитель: ";
            std::cin >> num;
            std::cout << "Введите знаменатель: ";
            std::cin >> den;

            Pair* other = nullptr;
            try {
                other = new Rational(num, den);

                Rational* rat1 = dynamic_cast<Rational*>(rational);
                Rational* rat2 = dynamic_cast<Rational*>(other);

                if (rat1 && rat2) {
                    if (rational->equ(other)) {
                        std::cout << "Дроби равны\n";
                    }
                    else if (rat1->greater(rat2)) {
                        std::cout << "Первая дробь больше\n";
                    }
                    else if (rat1->less(rat2)) {
                        std::cout << "Первая дробь меньше\n";
                    }
                }
            }
            catch (std::exception& error) {
                std::cout << "Ошибка: " << error.what() << std::endl;
            }

            if (other) delete other;
            break;
        }
        case 8: {
            if (!complex) {
                std::cout << "Сначала введите комплексное число!\n";
                break;
            }

            int real, imag;
            std::cout << "Введите второе комплексное число для сравнения:\n";
            std::cout << "Введите действительную часть: ";
            std::cin >> real;
            std::cout << "Введите мнимую часть: ";
            std::cin >> imag;
            Pair* other = new Complex(real, imag);

            if (complex->equ(other)) {
                std::cout << "Комплексные числа равны\n";
            }
            else {
                std::cout << "Комплексные числа не равны\n";
            }

            delete other;
            break;
        }
        case 9:
            if (rational) delete rational;
            if (complex) delete complex;
            std::cout << "Выход из программы...\n";
            return 0;
        default:
            std::cout << "Неверный выбор!\n";
        }
    }
}//стр 125 23