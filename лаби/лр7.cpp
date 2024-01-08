#include <iostream>

const int MAX_SIZE = 100;

int main() {
    int n;
    int choice;

    int lastNegative = 0;  // Оголошення та ініціалізація змінних
    int rowIndex = -1;
    int colIndex = -1;

    do {
        // Меню
        std::cout << "Завдання:\n";
        std::cout << "1. Ввести новий масив\n";
        std::cout << "2. Знайти останній від'ємний елемент та його координати\n";
        std::cout << "3. Вийти з програми\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            // Введення розміру масиву
            std::cout << "Введіть розмір масиву (n): ";
            std::cin >> n;

            // Перевірка на максимальний розмір
            if (n > MAX_SIZE) {
                std::cout << "Розмір масиву перевищує максимально допустимий розмір." << std::endl;
                return 1; // Помилка
            }

            // Введення елементів масиву
            int A[MAX_SIZE][MAX_SIZE];
            std::cout << "Введіть елементи масиву:" << std::endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    std::cout << "A[" << i << "][" << j << "]: ";
                    std::cin >> A[i][j];
                }
            }

            // Виведення масиву
            std::cout << "Введений масив:" << std::endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    std::cout << A[i][j] << " ";
                }
                std::cout << std::endl;
            }
            break;

        case 2:
            // Знайти останній від'ємний елемент та його координати
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (A[i][j] < 0) {
                        lastNegative = A[i][j];
                        rowIndex = i;
                        colIndex = j;
                    }
                }
            }

            // Виведення результатів
            if (rowIndex != -1 && colIndex != -1) {
                std::cout << "Останній від'ємний елемент: " << lastNegative << std::endl;
                std::cout << "Координати: Рядок " << rowIndex << ", Стовпець " << colIndex << std::endl;
            }
            else {
                std::cout << "У масиві немає від'ємних елементів." << std::endl;
            }
            break;

        case 3:
            std::cout << "До побачення!\n";
            break;

        default:
            std::cout << "Неправильний вибір. Будь ласка, введіть число від 1 до 3.\n";
            break;
        }

    } while (choice != 3);

    return 0;
}
