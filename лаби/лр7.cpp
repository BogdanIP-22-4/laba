#include <iostream>

const int MAX_SIZE = 100;

int main() {
    int n;
    int choice;

    int lastNegative = 0;  // ���������� �� ����������� ������
    int rowIndex = -1;
    int colIndex = -1;

    do {
        // ����
        std::cout << "��������:\n";
        std::cout << "1. ������ ����� �����\n";
        std::cout << "2. ������ ������� ��'����� ������� �� ���� ����������\n";
        std::cout << "3. ����� � ��������\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            // �������� ������ ������
            std::cout << "������ ����� ������ (n): ";
            std::cin >> n;

            // �������� �� ������������ �����
            if (n > MAX_SIZE) {
                std::cout << "����� ������ �������� ����������� ���������� �����." << std::endl;
                return 1; // �������
            }

            // �������� �������� ������
            int A[MAX_SIZE][MAX_SIZE];
            std::cout << "������ �������� ������:" << std::endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    std::cout << "A[" << i << "][" << j << "]: ";
                    std::cin >> A[i][j];
                }
            }

            // ��������� ������
            std::cout << "�������� �����:" << std::endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    std::cout << A[i][j] << " ";
                }
                std::cout << std::endl;
            }
            break;

        case 2:
            // ������ ������� ��'����� ������� �� ���� ����������
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (A[i][j] < 0) {
                        lastNegative = A[i][j];
                        rowIndex = i;
                        colIndex = j;
                    }
                }
            }

            // ��������� ����������
            if (rowIndex != -1 && colIndex != -1) {
                std::cout << "������� ��'����� �������: " << lastNegative << std::endl;
                std::cout << "����������: ����� " << rowIndex << ", �������� " << colIndex << std::endl;
            }
            else {
                std::cout << "� ����� ���� ��'����� ��������." << std::endl;
            }
            break;

        case 3:
            std::cout << "�� ���������!\n";
            break;

        default:
            std::cout << "������������ ����. ���� �����, ������ ����� �� 1 �� 3.\n";
            break;
        }

    } while (choice != 3);

    return 0;
}
