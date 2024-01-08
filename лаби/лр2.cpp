#include <iostream>
#include <vector>
#include <string>
#include <sstream> 

using namespace std;

// Структура для представлення члена сім'ї
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

// Структура для представлення родини
struct Family {
    Member husband;
    Member wife;
    vector<Member> children;
};

int main() {
    vector<Family> families;
    std::vector<int> numbers;
    int num;

    std::cout << "Введіть цілі числа (для завершення введення введіть 0):" << std::endl;

    while (true) {
        std::cin >> num;

        if (num == 0) {
            break;
        }

        numbers.push_back(num);
    }

    std::cout << " Список введених чисел:" << std::endl;
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cin.ignore();  // Очищення буфера введення перед зчитуванням наступного рядка
    std::string inputString;
    std::vector<char> charList;

    std::cout << "\n\nВведіть рядок:" << std::endl;
    std::getline(std::cin, inputString);

    for (char c : inputString) {
        charList.push_back(c);
    }

    std::cout << "Список символів:" << std::endl;
    for (char c : charList) {
        std::cout << c << " ";
    }

    // Перетворення рядка в список атомів
    std::cout << "\n\nВведіть рядок атомів, розділених пробілами:" << std::endl;
    std::getline(std::cin, inputString);

    std::vector<std::string> atomList;
    std::istringstream iss(inputString);
    std::string atom;

    while (iss >> atom) {
        atomList.push_back(atom);
    }

    std::cout << "Список атомів:" << std::endl;
    for (const std::string& a : atomList) {
        std::cout << a << " ";
    }

    Family family;

    int choice;
    do {
        cout << "\n Виберіть що вивести: " << endl;
        cout << "1. Ввести інформацію про сім'ю: " << endl;
        cout << "2. Знайти всі родини із трьома дітьми: " << endl;
        cout << "3. Знайти імена і прізвища всіх жінок, що мають принаймні трьох дітей; " << endl;
        cout << "4. Знайти прізвища людей, чий дохід менше ніж 1000: " << endl;
        cout << "5. Вивести всі працюючі дружини: " << endl;
        cout << "6. Вивести імена та прізвища всіх людей з бази даних: " << endl;
        cout << "7. Вийти з програми: " << endl;
        cout << "Виберіть пункт який вивести: ";
        cin >> choice;

        // Сім'я 1
        Family family1;
        family1.husband.first_name = "Іван";
        family1.husband.last_name = "Петров";
        family1.husband.birth_year = 1980;
        family1.husband.birth_month = 5;
        family1.husband.birth_day = 15;
        family1.husband.is_working = true;
        family1.husband.salary = 2000.0;

        family1.wife.first_name = "Марія";
        family1.wife.last_name = "Петрова";
        family1.wife.birth_year = 1985;
        family1.wife.birth_month = 8;
        family1.wife.birth_day = 20;
        family1.wife.is_working = true;
        family1.wife.salary = 900.0;

        Member child1;
        child1.first_name = "Олексій";
        child1.last_name = "Петров";
        child1.birth_year = 2010;
        child1.birth_month = 3;
        child1.birth_day = 10;
        child1.is_working = false;

        Member child2;
        child2.first_name = "Анна";
        child2.last_name = "Петрова";
        child2.birth_year = 2015;
        child2.birth_month = 11;
        child2.birth_day = 25;
        child2.is_working = false;

        families.push_back(family1);

        // Сім'я 2
        Family family2;
        family2.husband.first_name = "Петро";
        family2.husband.last_name = "Ходак";
        family2.husband.birth_year = 1975;
        family2.husband.birth_month = 10;
        family2.husband.birth_day = 5;
        family2.husband.is_working = true;
        family2.husband.salary = 10000.0;

        family2.wife.first_name = "Іванка";
        family2.wife.last_name = "Ходак";
        family2.wife.birth_year = 1975;
        family2.wife.birth_month = 7;
        family2.wife.birth_day = 10;
        family2.wife.is_working = false;

        Member child3;
        child3.first_name = "Роман";
        child3.last_name = "Ходак";
        child3.birth_year = 2004;
        child3.birth_month = 4;
        child3.birth_day = 6;
        child3.is_working = false;

        Member child4;
        child4.first_name = "Анна";
        child4.last_name = "Ходак";
        child4.birth_year = 2005;
        child4.birth_month = 11;
        child4.birth_day = 25;
        child4.is_working = false;

        families.push_back(family2);

        // Додати сім'ю до вектору
        families.push_back(family);

        // Введення даних про родини з клавіатури
        switch (choice) {
        case 1:

            int num_families;
            cout << "Введіть кількість родин: ";
            cin >> num_families;

            for (int i = 0; i < num_families; i++) {
                Family family;
                cout << "Родина " << i + 1 << ":" << endl;

                // Введення даних про чоловіка
                cout << "Введіть ім'я чоловіка: ";
                cin >> family.husband.first_name;
                cout << "Введіть прізвище чоловіка: ";
                cin >> family.husband.last_name;
                cout << "Введіть рік народження чоловіка: ";
                cin >> family.husband.birth_year;
                cout << "Введіть місяць народження чоловіка: ";
                cin >> family.husband.birth_month;
                cout << "Введіть день народження чоловіка: ";
                cin >> family.husband.birth_day;
                cout << "Чоловік працює? (1 - так, 0 - ні): ";
                cin >> family.husband.is_working;
                if (family.husband.is_working) {
                    cout << "Введіть зарплату чоловіка: ";
                    cin >> family.husband.salary;
                }
                // Введення даних про дружину
                cout << "Введіть ім'я дружини: ";
                cin >> family.wife.first_name;
                cout << "Введіть прізвище дружини: ";
                cin >> family.wife.last_name;
                cout << "Введіть рік народження дружини: ";
                cin >> family.wife.birth_year;
                cout << "Введіть місяць народження дружини: ";
                cin >> family.wife.birth_month;
                cout << "Введіть день народження дружини: ";
                cin >> family.wife.birth_day;
                cout << "Дружина працює? (1 - так, 0 - ні): ";
                cin >> family.wife.is_working;
                if (family.wife.is_working) {
                    cout << "Введіть зарплату дружини: ";
                    cin >> family.wife.salary;
                }

                // Введення даних про дітей
                int num_children;
                cout << "Введіть кількість дітей в родині: ";
                cin >> num_children;

                for (int j = 0; j < num_children; j++) {
                    Member child;
                    cout << "Дитина " << j + 1 << ":" << endl;
                    cout << "Введіть ім'я дитини: ";
                    cin >> child.first_name;
                    cout << "Введіть прізвище дитини: ";
                    cin >> child.last_name;
                    cout << "Введіть рік народження дитини: ";
                    cin >> child.birth_year;
                    cout << "Введіть місяць народження дитини: ";
                    cin >> child.birth_month;
                    cout << "Введіть день народження дитини: ";
                    cin >> child.birth_day;
                    cout << "Дитина працює? (1 - так, 0 - ні): ";
                    cin >> child.is_working;
                    if (child.is_working) {
                        cout << "Введіть зарплату дитини: ";
                        cin >> child.salary;
                    }
                    family.children.push_back(child);
                }

                families.push_back(family);
            }
            break;
            // Запити
        case 2:
            // А) Знайти всі родини із трьома дітьми
            for (const Family& family : families) {
                if (family.children.size() == 3) {
                    cout << "Родина з трьома дітьми: " << family.husband.first_name << " " << family.wife.first_name << endl;
                }
            }
            break;
        case 3:
            // Б) Знайти імена і прізвища всіх жінок, що мають принаймні трьох дітей
            for (const Family& family : families) {
                if (family.wife.is_working && family.children.size() >= 3) {
                    cout << "Дружина з принаймні трьома дітьми: " << family.wife.first_name << " " << family.wife.last_name << endl;
                }
            }
            break;
        case 4:
            // В) Знайти прізвища людей, чий дохід менше ніж 1000
            for (const Family& family : families) {
                if (family.husband.is_working && family.husband.salary < 1000) {
                    cout << "Чоловік з доходом менше ніж 1000: " << family.husband.last_name << endl;
                }
                if (family.wife.is_working && family.wife.salary < 1000) {
                    cout << "Дружина з доходом менше ніж 1000: " << family.wife.last_name << endl;
                }
                for (const Member& child : family.children) {
                    if (child.is_working && child.salary < 1000) {
                        cout << "Дитина з доходом менше ніж 1000: " << child.last_name << endl;
                    }
                }
            }
            break;
        case 5:
            // Виведення всіх працюючих дружин
            cout << "Всі працюючі дружини:" << endl;
            for (const Family& family : families) {
                if (family.wife.is_working) {
                    cout << family.wife.first_name << " " << family.wife.last_name << endl;
                }
            }
            break;
        case 6:
            // Виведення імен і прізвищ всіх людей з бази даних
            cout << "Імена та прізвища всіх людей з бази даних:" << endl;
            for (const Family& family : families) {
                cout << "Чоловік: " << family.husband.first_name << " " << family.husband.last_name << endl;
                cout << "Дружина: " << family.wife.first_name << " " << family.wife.last_name << endl;
                for (const Member& child : family.children) {
                    cout << "Дитина: " << child.first_name << " " << child.last_name << endl;
                }
            }
            break;
        case 7:
            cout << "Програма завершила роботу." << endl;
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}
