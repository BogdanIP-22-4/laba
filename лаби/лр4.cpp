#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

// ��������� ��� ������������� �������� ����
struct Node {
    int ����;  // ���� ���������� �����
    int ������������;  // ʳ������ ����� � �����
    int ������ǲ����������;  // ������ � �����������
    int ��;  // ³�
    float �������;  // �������
    // ���� ����, ���� �������
};

// ���� ��� ������ � �����
class MyDeque {
private:
    deque<Node> dequeList;

public:
    // ��������� �������� � ������� ����
    void pushFront(int ����, int ������������, int ������ǲ����������, int ��, float �������) {
        Node newNode;
        newNode.���� = ����;
        newNode.������������ = ������������;
        newNode.������ǲ���������� = ������ǲ����������;
        newNode.�� = ��;
        newNode.������� = �������;
        dequeList.push_front(newNode);
    }

    // ��������� �������� � ����� ����
    void pushBack(int ����, int ������������, int ������ǲ����������, int ��, float �������) {
        Node newNode;
        newNode.���� = ����;
        newNode.������������ = ������������;
        newNode.������ǲ���������� = ������ǲ����������;
        newNode.�� = ��;
        newNode.������� = �������;
        dequeList.push_back(newNode);
    }

    // ��������� �������� � ������� ����
    void popFront() {
        if (!dequeList.empty()) {
            dequeList.pop_front();
        }
        else {
            cout << "��� �������. ��������� ���������." << endl;
        }
    }

    // ��������� �������� � ���� ����
    void popBack() {
        if (!dequeList.empty()) {
            dequeList.pop_back();
        }
        else {
            cout << "��� �������. ��������� ���������." << endl;
        }
    }

    // ��������� ��������� ����� ����
    void display() {
        cout << "�������� ���� ����: ";
        for (const auto& node : dequeList) {
            cout << "����: " << node.����
                << ", ʳ������ �����: " << node.������������
                << ", ������ � �����������: " << node.������ǲ����������
                << ", ³�: " << node.��
                << ", �������: " << node.�������
                << " | ";
        }
        cout << endl;
    }
};

// ������� ��� ��������, �� ����� � ����������
bool isPalindrome(const string& str) {
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end()); // �������� �����

    return str == reversedStr;
}

int main() {
    MyDeque myDeque;
    int choice;
    string input; // ���������� �� ��� switch

    do {
        cout << "\n������ ��������:" << endl;
        cout << "1. ������ ������� � ������� ����" << endl;
        cout << "2. ������ ������� � ����� ����" << endl;
        cout << "3. �������� ������� � ������� ����" << endl;
        cout << "4. �������� ������� � ���� ����" << endl;
        cout << "5. ������� �������� ���� ����" << endl;
        cout << "6. ��������� ����� �� ��������" << endl;
        cout << "0. �����" << endl;

        cout << "��� ����: ";
        cin >> choice;

        switch (choice) {
        case 1:
        case 2:
            int ����, ������������, ������ǲ����������, ��;
            float �������;
            cout << "������ �������� ��� ��������� � ����:\n";
            cout << "����: "; cin >> ����;
            cout << "ʳ������ �����: "; cin >> ������������;
            cout << "������ � �����������: "; cin >> ������ǲ����������;
            cout << "³�: "; cin >> ��;
            cout << "�������: "; cin >> �������;
            if (choice == 1) {
                myDeque.pushFront(����, ������������, ������ǲ����������, ��, �������);
            }
            else {
                myDeque.pushBack(����, ������������, ������ǲ����������, ��, �������);
            }
            break;

        case 3:
            myDeque.popFront();
            break;

        case 4:
            myDeque.popBack();
            break;

        case 5:
            myDeque.display();
            break;

        case 6:
            cout << "������ ����� ��� �������� �� ��������: ";
            cin.ignore(); // ������� ������ ����� getline
            getline(cin, input);
            if (isPalindrome(input)) {
                cout << "�������� ����� - ��������." << endl;
            }
            else {
                cout << "�������� ����� - �� ��������." << endl;
            }
            break;

        case 0:
            cout << "�����." << endl;
            break;

        default:
            cout << "������� ����. ���� �����, ������ �� ���." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
