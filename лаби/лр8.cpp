#include <iostream>
#include <algorithm>

using namespace std;

// Функція для сортування бульбашкою
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функція для виконання бінарного пошуку та виведення результатів
void binarySearch(int firstSequence[], int n, int secondSequence[], int m) {
    cout << "Результат бінарного пошуку:\n";
    for (int i = 0; i < m; ++i) {
        // Використання бінарного пошуку
        int* index = lower_bound(firstSequence, firstSequence + n, secondSequence[i]);

        // Перевірка, чи знайдено елемент та виведення результату
        if (index != firstSequence + n && *index == secondSequence[i]) {
            cout << "Елемент " << secondSequence[i] << " є на позиції " << (index - firstSequence) + 1 << " у відсортованій послідовності.\n";
        }
        else {
            cout << "Елемент " << secondSequence[i] << " не знайдений у відсортованій послідовності.\n";
        }
    }
}

int main() {
    int N, M;

    // Нескінченний цикл для меню
    while (true) {
        cout << "Завдання:\n";
        cout << "1. Ввести розмірності масивів\n";
        cout << "2. Ввести елементи першої послідовності та відсортувати\n";
        cout << "3. Ввести елементи другої послідовності та виконати бінарний пошук\n";
        cout << "0. Вийти\n";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            // Введення розмірностей масивів
            cout << "Введіть N (1 < N < 256): ";
            cin >> N;
            cout << "Введіть M (1 < M < 256): ";
            cin >> M;
            break;
        case 2: {
            // Введення та сортування першої послідовності
            int firstSequence[N];
            cout << "Введіть " << N << " елементів першої послідовності:\n";
            for (int i = 0; i < N; ++i) {
                cin >> firstSequence[i];
            }
            // Сортування бульбашкою
            bubbleSort(firstSequence, N);
            // Виведення відсортованої послідовності
            cout << "Відсортована послідовність:\n";
            for (int i = 0; i < N; ++i) {
                cout << firstSequence[i] << " ";
            }
            cout << "\n";
            break;
        }
        case 3: {
            // Введення елементів та виконання бінарного пошуку
            int firstSequence[N];
            cout << "Введіть " << N << " відсортованих елементів першої послідовності:\n";
            for (int i = 0; i < N; ++i) {
                cin >> firstSequence[i];
            }
            int secondSequence[M];
            cout << "Введіть " << M << " елементів другої послідовності:\n";
            for (int i = 0; i < M; ++i) {
                cin >> secondSequence[i];
            }
            // Виклик функції бінарного пошуку
            binarySearch(firstSequence, N, secondSequence, M);
            break;
        }
        case 0:
            // Вихід з програми
            return 0;
        default:
            cout << "Невірний вибір. Будь ласка, виберіть інше число.\n";
        }
    }
}

