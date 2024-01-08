#include <iostream>
#include <cstdlib>
#include <ctime>

const int N = 100;

// ������� ��� ����������� ���� �������� � ��������� ��������� ����� ������ ��'����� ���������
int sumOddBeforeNegative(int arr[], int n) {
    int sum = 0;
    bool foundNegative = false;

    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) { // ����������, �� ������ � ��������
            if (arr[i] < 0) { // ���� �������� ��'����� �������, ���������� �����
                foundNegative = true;
                break;
            }
            sum += arr[i]; // ������ ������� �� ����
        }
    }

    if (!foundNegative) {
        std::cout << "³�'����� ������� �� ��������." << std::endl;
    }

    return sum;
}

// ������� ��� ��������� ������ �� �����
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[N];
    int n, minRange, maxRange;

    std::cout << "������ ��������� �����: ";
    std::cin >> minRange;

    std::cout << "������ ������������ �����: ";
    std::cin >> maxRange;

    std::cout << "������ ������� �������� (N): ";
    std::cin >> n;

    if (n > N) {
        std::cout << "ʳ������ �������� (N) �� ���� ������������ " << N << std::endl;
        return 1;
    }

    // ���������� ������ ����������� �������
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (maxRange - minRange + 1) + minRange;
    }

    std::cout << "��������� ������� ������: ";
    displayArray(arr, n);

    int sum = sumOddBeforeNegative(arr, n);
    std::cout << "���� �������� � ��������� ��������� ����� ������ ��'����� ���������: " << sum << std::endl;

    // ��������� ������������� �������� �� ������� ������
    int maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    if (n + 1 > N) {
        std::cout << "��������� ���������. ���������� ����������� ������� �������� � �����." << std::endl;
    }
    else {
        for (int i = n; i >= 0; i--) {
            arr[i + 1] = arr[i];
        }
        arr[0] = maxElement;
        n++;

        std::cout << "����� ���� ��������� ������������� ��������: ";
        displayArray(arr, n);
    }

    return 0;
}
