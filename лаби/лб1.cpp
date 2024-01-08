#include <iostream>
#include <cstdlib>
#include <ctime>

const int N = 100;

// Функція для знаходження суми елементів з непарними індексами перед першим від'ємним елементом
int sumOddBeforeNegative(int arr[], int n) {
    int sum = 0;
    bool foundNegative = false;

    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) { // Перевіряємо, чи індекс є непарним
            if (arr[i] < 0) { // Якщо знайдено від'ємний елемент, припиняємо пошук
                foundNegative = true;
                break;
            }
            sum += arr[i]; // Додаємо елемент до суми
        }
    }

    if (!foundNegative) {
        std::cout << "Від'ємний елемент не знайдено." << std::endl;
    }

    return sum;
}

// Функція для виведення масиву на екран
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[N];
    int n, minRange, maxRange;

    std::cout << "Введіть мінімальний масив: ";
    std::cin >> minRange;

    std::cout << "Введіть максимальний масив: ";
    std::cin >> maxRange;

    std::cout << "Введіть кількість елементів (N): ";
    std::cin >> n;

    if (n > N) {
        std::cout << "Кількість елементів (N) не може перевищувати " << N << std::endl;
        return 1;
    }

    // Заповнення масиву випадковими числами
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (maxRange - minRange + 1) + minRange;
    }

    std::cout << "Заповнена частина масиву: ";
    displayArray(arr, n);

    int sum = sumOddBeforeNegative(arr, n);
    std::cout << "Сума елементів з непарними індексами перед першим від'ємним елементом: " << sum << std::endl;

    // Додавання максимального елемента на початок масиву
    int maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    if (n + 1 > N) {
        std::cout << "Додавання неможливе. Перевищено максимальну кількість елементів у масиві." << std::endl;
    }
    else {
        for (int i = n; i >= 0; i--) {
            arr[i + 1] = arr[i];
        }
        arr[0] = maxElement;
        n++;

        std::cout << "Масив після додавання максимального елемента: ";
        displayArray(arr, n);
    }

    return 0;
}
