#include "Set.h"

int main() {
    setlocale(LC_ALL, "");
    using std::cin;
    using std::cout;

    Set mySet;
    Set otherSet;
    bool otherSetInitialized = false;
    int choice;
    int value;
    int count;
    // МУдл стр лаптев 26 номер 52
    cout << "Введите первое множество:\n";
    mySet >> cin;
    while (true) {
        cout << "\n--- Меню ---\n";
        cout << "1. Добавить элементы в первое множество\n";
        cout << "2. Удалить элемент из первого множества\n";
        cout << "3. Проверить наличие элемента в первом множестве\n";
        cout << "4. Вывести первое множество\n";
        cout << "5. Проверить, пустое ли первое множество\n";
        cout << "6. Ввести второе множество\n";
        cout << "7. Проверить, пустое ли второе множество\n";
        cout << "8. Объединение множеств\n";
        cout << "9. Пересечение множеств\n";
        cout << "10. Разность (первое - второе)\n";
        cout << "11. Симметрическая разность\n";
        cout << "12. Проверить, является ли первое подмножеством второго\n";
        cout << "13. Проверить, является ли второе подмножеством первого\n";
        cout << "14. Проверить равенство множеств\n";
        cout << "15. Проверить строгое подмножество (первое < второе)\n";
        cout << "16. Проверить строгое надмножество (первое > второе)\n";
        cout << "17. Вывести второе множество\n";
        cout << "18. Выход из программы\n";

        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите количество элементов для добавления: ";
            cin >> count;
            cout << "Введите элементы: ";
            for (int i = 0; i < count; i++) {
                cin >> value;
                mySet.add(value);
                cout << "Элемент " << value << " добавлен.\n";
            }
            break;

        case 2:
            cout << "Введите элемент для удаления: ";
            cin >> value;
            if (mySet.isContain(value)) {
                mySet.remove(value);
                cout << "Элемент " << value << " удалён.\n";
            }
            else {
                cout << "Элемент " << value << " не найден.\n";
            }
            break;

        case 3:
            cout << "Введите элемент для проверки: ";
            cin >> value;
            if (mySet.isContain(value)) {
                cout << "Элемент " << value << " присутствует в первом множестве.\n";
            }
            else {
                cout << "Элемент " << value << " отсутствует в первом множестве.\n";
            }
            break;

        case 4:
            cout << "Первое множество: ";
            mySet << cout;
            cout << std::endl;
            break;

        case 5:
            if (mySet.isEmpty()) {
                cout << "Первое множество пустое.\n";
            }
            else {
                cout << "Первое множество не пустое.\n";
            }
            break;

        case 6:
            otherSet >> cin;
            otherSetInitialized = true;
            cout << "Второе множество введено.\n";
            break;

        case 7:
            if (otherSet.isEmpty()) {
                cout << "Второе множество пустое.\n";
            }
            else {
                cout << "Второе множество не пустое.\n";
            }
            break;

        case 8:
            if (!otherSetInitialized) {
                cout << "Сначала введите второе множество (пункт 6).\n";
                break;
            }
            {
                Set result = mySet + otherSet;
                cout << "Объединение: ";
                result << cout;
                cout << std::endl;
            }
            break;

        case 9:
            if (!otherSetInitialized) {
                cout << "Сначала введите второе множество (пункт 6).\n";
                break;
            }
            {
                Set result = mySet * otherSet;
                cout << "Пересечение: ";
                result << cout;
                cout << std::endl;
            }
            break;

        case 10:
            if (!otherSetInitialized) {
                cout << "Сначала введите второе множество (пункт 6).\n";
                break;
            }
            {
                Set result = mySet - otherSet;
                cout << "Разность (первое - второе): ";
                result << cout;
                cout << std::endl;
            }
            break;

        case 11:
            if (!otherSetInitialized) {
                cout << "Сначала введите второе множество (пункт 6).\n";
                break;
            }
            {
                Set result = mySet.symmetricDifference(otherSet);
                cout << "Симметрическая разность: ";
                result << cout;
                cout << std::endl;
            }
            break;

        case 12:
            if (!otherSetInitialized) {
                cout << "Сначала введите второе множество (пункт 6).\n";
                break;
            }
            if (mySet <= otherSet) {
                cout << "Первое множество является подмножеством второго.\n";
            }
            else {
                cout << "Первое множество не является подмножеством второго.\n";
            }
            break;

        case 13:
            if (!otherSetInitialized) {
                cout << "Сначала введите второе множество (пункт 6).\n";
                break;
            }
            if (otherSet <= mySet) {
                cout << "Второе множество является подмножеством первого.\n";
            }
            else {
                cout << "Второе множество не является подмножеством первого.\n";
            }
            break;

        case 14:
            if (!otherSetInitialized) {
                cout << "Сначала введите второе множество (пункт 6).\n";
                break;
            }
            if (mySet == otherSet) {
                cout << "Множества равны.\n";
            }
            else {
                cout << "Множества не равны.\n";
            }
            break;

        case 15:
            if (!otherSetInitialized) {
                cout << "Сначала введите второе множество (пункт 6).\n";
                break;
            }
            if (mySet < otherSet) {
                cout << "Первое множество является строгим подмножеством второго.\n";
            }
            else {
                cout << "Первое множество не является строгим подмножеством второго.\n";
            }
            break;

        case 16:
            if (!otherSetInitialized) {
                cout << "Сначала введите второе множество (пункт 6).\n";
                break;
            }
            if (mySet > otherSet) {
                cout << "Первое множество является строгим надмножеством второго.\n";
            }
            else {
                cout << "Первое множество не является строгим надмножеством второго.\n";
            }
            break;

        case 17:
            if (!otherSetInitialized) {
                cout << "Сначала введите второе множество (пункт 6).\n";
                break;
            }
            cout << "Второе множество: ";
            otherSet << cout;
            cout << std::endl;
            break;

        case 18:
            cout << "Выход из программы.\n";
            return 0;

        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
    }

    return 0;
}