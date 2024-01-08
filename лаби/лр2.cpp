#include <iostream>
#include <vector>
#include <string>
#include <sstream> 

using namespace std;

// ��������� ��� ������������� ����� ��'�
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Member {
    string first_name;
    string last_name;
    int birth_year;
    int birth_month;
    int birth_day;
    bool is_working;
    string job_title;
    double salary;
};

// ��������� ��� ������������� ������
struct Family {
    Member husband;
    Member wife;
    vector<Member> children;
};

int main() {
    vector<Family> families;
    std::vector<int> numbers;
    int num;

    std::cout << "������ ��� ����� (��� ���������� �������� ������ 0):" << std::endl;

    while (true) {
        std::cin >> num;

        if (num == 0) {
            break;
        }

        numbers.push_back(num);
    }

    std::cout << " ������ �������� �����:" << std::endl;
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cin.ignore();  // �������� ������ �������� ����� ����������� ���������� �����
    std::string inputString;
    std::vector<char> charList;

    std::cout << "\n\n������ �����:" << std::endl;
    std::getline(std::cin, inputString);

    for (char c : inputString) {
        charList.push_back(c);
    }

    std::cout << "������ �������:" << std::endl;
    for (char c : charList) {
        std::cout << c << " ";
    }

    // ������������ ����� � ������ �����
    std::cout << "\n\n������ ����� �����, ��������� ��������:" << std::endl;
    std::getline(std::cin, inputString);

    std::vector<std::string> atomList;
    std::istringstream iss(inputString);
    std::string atom;

    while (iss >> atom) {
        atomList.push_back(atom);
    }

    std::cout << "������ �����:" << std::endl;
    for (const std::string& a : atomList) {
        std::cout << a << " ";
    }

    Family family;

    int choice;
    do {
        cout << "\n ������� �� �������: " << endl;
        cout << "1. ������ ���������� ��� ��'�: " << endl;
        cout << "2. ������ �� ������ �� ������ �����: " << endl;
        cout << "3. ������ ����� � ������� ��� ����, �� ����� �������� ����� ����; " << endl;
        cout << "4. ������ ������� �����, ��� ����� ����� �� 1000: " << endl;
        cout << "5. ������� �� �������� �������: " << endl;
        cout << "6. ������� ����� �� ������� ��� ����� � ���� �����: " << endl;
        cout << "7. ����� � ��������: " << endl;
        cout << "������� ����� ���� �������: ";
        cin >> choice;

        // ѳ�'� 1
        Family family1;
        family1.husband.first_name = "����";
        family1.husband.last_name = "������";
        family1.husband.birth_year = 1980;
        family1.husband.birth_month = 5;
        family1.husband.birth_day = 15;
        family1.husband.is_working = true;
        family1.husband.salary = 2000.0;

        family1.wife.first_name = "����";
        family1.wife.last_name = "�������";
        family1.wife.birth_year = 1985;
        family1.wife.birth_month = 8;
        family1.wife.birth_day = 20;
        family1.wife.is_working = true;
        family1.wife.salary = 900.0;

        Member child1;
        child1.first_name = "������";
        child1.last_name = "������";
        child1.birth_year = 2010;
        child1.birth_month = 3;
        child1.birth_day = 10;
        child1.is_working = false;

        Member child2;
        child2.first_name = "����";
        child2.last_name = "�������";
        child2.birth_year = 2015;
        child2.birth_month = 11;
        child2.birth_day = 25;
        child2.is_working = false;

        families.push_back(family1);

        // ѳ�'� 2
        Family family2;
        family2.husband.first_name = "�����";
        family2.husband.last_name = "�����";
        family2.husband.birth_year = 1975;
        family2.husband.birth_month = 10;
        family2.husband.birth_day = 5;
        family2.husband.is_working = true;
        family2.husband.salary = 10000.0;

        family2.wife.first_name = "������";
        family2.wife.last_name = "�����";
        family2.wife.birth_year = 1975;
        family2.wife.birth_month = 7;
        family2.wife.birth_day = 10;
        family2.wife.is_working = false;

        Member child3;
        child3.first_name = "�����";
        child3.last_name = "�����";
        child3.birth_year = 2004;
        child3.birth_month = 4;
        child3.birth_day = 6;
        child3.is_working = false;

        Member child4;
        child4.first_name = "����";
        child4.last_name = "�����";
        child4.birth_year = 2005;
        child4.birth_month = 11;
        child4.birth_day = 25;
        child4.is_working = false;

        families.push_back(family2);

        // ������ ��'� �� �������
        families.push_back(family);

        // �������� ����� ��� ������ � ���������
        switch (choice) {
        case 1:

            int num_families;
            cout << "������ ������� �����: ";
            cin >> num_families;

            for (int i = 0; i < num_families; i++) {
                Family family;
                cout << "������ " << i + 1 << ":" << endl;

                // �������� ����� ��� �������
                cout << "������ ��'� �������: ";
                cin >> family.husband.first_name;
                cout << "������ ������� �������: ";
                cin >> family.husband.last_name;
                cout << "������ �� ���������� �������: ";
                cin >> family.husband.birth_year;
                cout << "������ ����� ���������� �������: ";
                cin >> family.husband.birth_month;
                cout << "������ ���� ���������� �������: ";
                cin >> family.husband.birth_day;
                cout << "������ ������? (1 - ���, 0 - �): ";
                cin >> family.husband.is_working;
                if (family.husband.is_working) {
                    cout << "������ �������� �������: ";
                    cin >> family.husband.salary;
                }
                // �������� ����� ��� �������
                cout << "������ ��'� �������: ";
                cin >> family.wife.first_name;
                cout << "������ ������� �������: ";
                cin >> family.wife.last_name;
                cout << "������ �� ���������� �������: ";
                cin >> family.wife.birth_year;
                cout << "������ ����� ���������� �������: ";
                cin >> family.wife.birth_month;
                cout << "������ ���� ���������� �������: ";
                cin >> family.wife.birth_day;
                cout << "������� ������? (1 - ���, 0 - �): ";
                cin >> family.wife.is_working;
                if (family.wife.is_working) {
                    cout << "������ �������� �������: ";
                    cin >> family.wife.salary;
                }

                // �������� ����� ��� ����
                int num_children;
                cout << "������ ������� ���� � �����: ";
                cin >> num_children;

                for (int j = 0; j < num_children; j++) {
                    Member child;
                    cout << "������ " << j + 1 << ":" << endl;
                    cout << "������ ��'� ������: ";
                    cin >> child.first_name;
                    cout << "������ ������� ������: ";
                    cin >> child.last_name;
                    cout << "������ �� ���������� ������: ";
                    cin >> child.birth_year;
                    cout << "������ ����� ���������� ������: ";
                    cin >> child.birth_month;
                    cout << "������ ���� ���������� ������: ";
                    cin >> child.birth_day;
                    cout << "������ ������? (1 - ���, 0 - �): ";
                    cin >> child.is_working;
                    if (child.is_working) {
                        cout << "������ �������� ������: ";
                        cin >> child.salary;
                    }
                    family.children.push_back(child);
                }

                families.push_back(family);
            }
            break;
            // ������
        case 2:
            // �) ������ �� ������ �� ������ �����
            for (const Family& family : families) {
                if (family.children.size() == 3) {
                    cout << "������ � ������ �����: " << family.husband.first_name << " " << family.wife.first_name << endl;
                }
            }
            break;
        case 3:
            // �) ������ ����� � ������� ��� ����, �� ����� �������� ����� ����
            for (const Family& family : families) {
                if (family.wife.is_working && family.children.size() >= 3) {
                    cout << "������� � �������� ������ �����: " << family.wife.first_name << " " << family.wife.last_name << endl;
                }
            }
            break;
        case 4:
            // �) ������ ������� �����, ��� ����� ����� �� 1000
            for (const Family& family : families) {
                if (family.husband.is_working && family.husband.salary < 1000) {
                    cout << "������ � ������� ����� �� 1000: " << family.husband.last_name << endl;
                }
                if (family.wife.is_working && family.wife.salary < 1000) {
                    cout << "������� � ������� ����� �� 1000: " << family.wife.last_name << endl;
                }
                for (const Member& child : family.children) {
                    if (child.is_working && child.salary < 1000) {
                        cout << "������ � ������� ����� �� 1000: " << child.last_name << endl;
                    }
                }
            }
            break;
        case 5:
            // ��������� ��� ��������� ������
            cout << "�� �������� �������:" << endl;
            for (const Family& family : families) {
                if (family.wife.is_working) {
                    cout << family.wife.first_name << " " << family.wife.last_name << endl;
                }
            }
            break;
        case 6:
            // ��������� ���� � ������ ��� ����� � ���� �����
            cout << "����� �� ������� ��� ����� � ���� �����:" << endl;
            for (const Family& family : families) {
                cout << "������: " << family.husband.first_name << " " << family.husband.last_name << endl;
                cout << "�������: " << family.wife.first_name << " " << family.wife.last_name << endl;
                for (const Member& child : family.children) {
                    cout << "������: " << child.first_name << " " << child.last_name << endl;
                }
            }
            break;
        case 7:
            cout << "�������� ��������� ������." << endl;
            break;
        default:
            cout << "������� ����. ��������� �� ���." << endl;
        }
    } while (choice != 0);

    return 0;
}
