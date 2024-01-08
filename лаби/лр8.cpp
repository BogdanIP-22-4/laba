#include <iostream>
#include <algorithm>

using namespace std;

// ������� ��� ���������� ����������
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ������� ��� ��������� �������� ������ �� ��������� ����������
void binarySearch(int firstSequence[], int n, int secondSequence[], int m) {
    cout << "��������� �������� ������:\n";
    for (int i = 0; i < m; ++i) {
        // ������������ �������� ������
        int* index = lower_bound(firstSequence, firstSequence + n, secondSequence[i]);

        // ��������, �� �������� ������� �� ��������� ����������
        if (index != firstSequence + n && *index == secondSequence[i]) {
            cout << "������� " << secondSequence[i] << " � �� ������� " << (index - firstSequence) + 1 << " � ����������� �����������.\n";
        }
        else {
            cout << "������� " << secondSequence[i] << " �� ��������� � ����������� �����������.\n";
        }
    }
}

int main() {
    int N, M;

    // ����������� ���� ��� ����
    while (true) {
        cout << "��������:\n";
        cout << "1. ������ ��������� ������\n";
        cout << "2. ������ �������� ����� ����������� �� �����������\n";
        cout << "3. ������ �������� ����� ����������� �� �������� ������� �����\n";
        cout << "0. �����\n";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            // �������� ����������� ������
            cout << "������ N (1 < N < 256): ";
            cin >> N;
            cout << "������ M (1 < M < 256): ";
            cin >> M;
            break;
        case 2: {
            // �������� �� ���������� ����� �����������
            int firstSequence[N];
            cout << "������ " << N << " �������� ����� �����������:\n";
            for (int i = 0; i < N; ++i) {
                cin >> firstSequence[i];
            }
            // ���������� ����������
            bubbleSort(firstSequence, N);
            // ��������� ����������� �����������
            cout << "³���������� �����������:\n";
            for (int i = 0; i < N; ++i) {
                cout << firstSequence[i] << " ";
            }
            cout << "\n";
            break;
        }
        case 3: {
            // �������� �������� �� ��������� �������� ������
            int firstSequence[N];
            cout << "������ " << N << " ������������ �������� ����� �����������:\n";
            for (int i = 0; i < N; ++i) {
                cin >> firstSequence[i];
            }
            int secondSequence[M];
            cout << "������ " << M << " �������� ����� �����������:\n";
            for (int i = 0; i < M; ++i) {
                cin >> secondSequence[i];
            }
            // ������ ������� �������� ������
            binarySearch(firstSequence, N, secondSequence, M);
            break;
        }
        case 0:
            // ����� � ��������
            return 0;
        default:
            cout << "������� ����. ���� �����, ������� ���� �����.\n";
        }
    }
}

