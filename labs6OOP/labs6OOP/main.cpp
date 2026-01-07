#include "DList.h"
#include <iostream>
using namespace std;

void showMenu() {
    cout << "\nМЕНЮ" << endl;
    cout << "1.   Показать список" << endl;
    cout << "2.  Добавить в начало" << endl;
    cout << "3.  Добавить в конец" << endl;
    cout << "4.   Удалить из начала" << endl;
    cout << "5.  Удалить из конца" << endl;
    cout << "6.  Найти элемент" << endl;
    cout << "7.  Удалить диапазон (группу)" << endl;
    cout << "8.  Заменить диапазон на элемент" << endl;
    cout << "9.  Заменить диапазон на список" << endl;
    cout << "10. Найти последовательность" << endl;
    cout << "11. Объединение списков" << endl;
    cout << "12. Пересечение списков" << endl;
    cout << "13.  Очистить список" << endl;
    cout << "14. Заполнить тестовыми данными" << endl;
    cout << "0.   Выход" << endl;
    cout << "Ваш выбор: ";
}

void inputList(DList<int>& list, const string& name) {
    cout << "Введите количество элементов для " << name << ": ";
    int n;
    cin >> n;
    cout << "Введите " << n << " элементов: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        list.addToTail(value);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    DList<int> list;
    int choice;


    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Текущий список: ";
            list.show();
            cout << "Размер: " << list.getSize() << endl;
            break;
        }

        case 2: {
            cout << "Введите значение: ";
            int value;
            cin >> value;
            list.addToHead(value);
            cout << "Элемент добавлен в начало" << endl;
            break;
        }

        case 3: {
            cout << "Введите значение: ";
            int value;
            cin >> value;
            list.addToTail(value);
            cout << "Элемент добавлен в конец" << endl;
            break;
        }

        case 4: {
            if (list.isEmpty()) {
                cout << "Список пуст!" << endl;
            }
            else {
                list.deleteFromHead();
                cout << "Элемент удалён из начала" << endl;
            }
            break;
        }

        case 5: {
            if (list.isEmpty()) {
                cout << "Список пуст!" << endl;
            }
            else {
                list.deleteFromTail();
                cout << "Элемент удалён из конца" << endl;
            }
            break;
        }

        case 6: {
            cout << "Введите искомое значение: ";
            int value;
            cin >> value;
            Iterator<int> it = list.find(value);
            if (it != list.end()) {
                cout << "Элемент " << value << " найден!" << endl;
            }
            else {
                cout << "Элемент " << value << " не найден" << endl;
            }
            break;
        }

        case 7: {
            cout << "Введите начальное значение диапазона: ";
            int val1;
            cin >> val1;
            cout << "Введите конечное значение диапазона: ";
            int val2;
            cin >> val2;

            Iterator<int> first, last;
            if (list.findRange(val1, val2, first, last)) {
                list.deleteRange(first, last);
                cout << "Диапазон [" << val1 << ", " << val2 << "] удалён" << endl;
                cout << "Результат: ";
                list.show();
            }
            else {
                cout << "Не удалось найти указанный диапазон" << endl;
            }
            break;
        }

        case 8: {
            cout << "Введите начальное значение диапазона: ";
            int val1;
            cin >> val1;
            cout << "Введите конечное значение диапазона: ";
            int val2;
            cin >> val2;
            cout << "Введите новое значение: ";
            int newVal;
            cin >> newVal;

            Iterator<int> first, last;
            if (list.findRange(val1, val2, first, last)) {
                list.replaceRange(first, last, newVal);
                cout << "Диапазон заменён на " << newVal << endl;
                cout << "Результат: ";
                list.show();
            }
            else {
                cout << "Не удалось найти указанный диапазон" << endl;
            }
            break;
        }

        case 9: {
            cout << "Введите начальное значение диапазона: ";
            int val1;
            cin >> val1;
            cout << "Введите конечное значение диапазона: ";
            int val2;
            cin >> val2;

            Iterator<int> first, last;
            if (list.findRange(val1, val2, first, last)) {
                cout << "\n Создание списка для замены" << endl;
                DList<int> replacement;
                inputList(replacement, "списка замены");

                list.replaceRangeWithList(first, last, replacement);
                cout << "Диапазон заменён на список" << endl;
                cout << "Результат: ";
                list.show();
            }
            else {
                cout << "Не удалось найти указанный диапазон" << endl;
            }
            break;
        }

        case 10: {
            cout << "\n Поиск последовательности" << endl;
            DList<int> sequence;
            inputList(sequence, "искомой последовательности");

            sequence.show();
            cout << "В списке: ";
            list.show();

            Iterator<int> found = list.findSequence(sequence);
            if (found != list.end()) {
                cout << "Последовательность найдена!  Начинается с элемента: " << *found << endl;
            }
            else {
                cout << "Последовательность не найдена" << endl;
            }
            break;
        }

        case 11: {
            cout << "\nОбъединение списков" << endl;
            DList<int> list2;
            inputList(list2, "второго списка");

            cout << "Список 1: ";
            list.show();
            cout << "Список 2: ";
            list2.show();

            list.unionWith(list2);

            cout << "Результат объединения: ";
            list.show();
            break;
        }

        case 12: {
            cout << "\nПересечение списков" << endl;
            DList<int> list2;
            inputList(list2, "второго списка");

            cout << "Список 1: ";
            list.show();
            cout << "Список 2: ";
            list2.show();

            list.intersectWith(list2);

            cout << "Результат пересечения: ";
            list.show();
            break;
        }

        case 13: {
            list.clear();
            cout << "Список очищен" << endl;
            break;
        }

        case 14: {
            list.clear();
            for (int i = 1; i <= 5; i++) {
                list.addToTail(i);
            }
            for (int i = 8; i!=0; i--) {
                list.addToHead(i);
            }
            cout << "Список заполнен: ";
            list.show();
            break;
        }

        case 0: {
            cout << "Программа завершена!" << endl;
            break;
        }

        default: {
            cout << "Неверный выбор!" << endl;
        }
        }

    } while (choice != 0);

    return 0;
}