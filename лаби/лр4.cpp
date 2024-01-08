#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

// —труктура дл€ представленн€ елемента дека
struct Node {
    int стаж;  // —таж прац≥вника ф≥рми
    int к≥льк≥сть–ечей;  //  ≥льк≥сть речей у багаж≥
    int оц≥нка«≤нформатики;  // ќц≥нка з ≥нформатики
    int в≥к;  // ¬≥к
    float варт≥сть;  // ¬арт≥сть
    // ≤нш≥ пол€, €кщо потр≥бно
};

//  лас дл€ роботи з деком
class MyDeque {
private:
    deque<Node> dequeList;

public:
    // ƒодаванн€ елемента в початок дека
    void pushFront(int стаж, int к≥льк≥сть–ечей, int оц≥нка«≤нформатики, int в≥к, float варт≥сть) {
        Node newNode;
        newNode.стаж = стаж;
        newNode.к≥льк≥сть–ечей = к≥льк≥сть–ечей;
        newNode.оц≥нка«≤нформатики = оц≥нка«≤нформатики;
        newNode.в≥к = в≥к;
        newNode.варт≥сть = варт≥сть;
        dequeList.push_front(newNode);
    }

    // ƒодаванн€ елемента в к≥нець дека
    void pushBack(int стаж, int к≥льк≥сть–ечей, int оц≥нка«≤нформатики, int в≥к, float варт≥сть) {
        Node newNode;
        newNode.стаж = стаж;
        newNode.к≥льк≥сть–ечей = к≥льк≥сть–ечей;
        newNode.оц≥нка«≤нформатики = оц≥нка«≤нформатики;
        newNode.в≥к = в≥к;
        newNode.варт≥сть = варт≥сть;
        dequeList.push_back(newNode);
    }

    // ¬идаленн€ елемента з початку дека
    void popFront() {
        if (!dequeList.empty()) {
            dequeList.pop_front();
        }
        else {
            cout << "ƒек порожн≥й. ¬идаленн€ неможливе." << endl;
        }
    }

    // ¬идаленн€ елемента з к≥нц€ дека
    void popBack() {
        if (!dequeList.empty()) {
            dequeList.pop_back();
        }
        else {
            cout << "ƒек порожн≥й. ¬идаленн€ неможливе." << endl;
        }
    }

    // ¬иведенн€ поточного стану дека
    void display() {
        cout << "ѕоточний стан дека: ";
        for (const auto& node : dequeList) {
            cout << "—таж: " << node.стаж
                << ",  ≥льк≥сть речей: " << node.к≥льк≥сть–ечей
                << ", ќц≥нка з ≥нформатики: " << node.оц≥нка«≤нформатики
                << ", ¬≥к: " << node.в≥к
                << ", ¬арт≥сть: " << node.варт≥сть
                << " | ";
        }
        cout << endl;
    }
};

// ‘ункц≥€ дл€ перев≥рки, чи р€док Ї пал≥ндромом
bool isPalindrome(const string& str) {
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end()); // ќбертаЇмо р€док

    return str == reversedStr;
}

int main() {
    MyDeque myDeque;
    int choice;
    string input; // ѕеренесено за меж≥ switch

    do {
        cout << "\nќбер≥ть операц≥ю:" << endl;
        cout << "1. ƒодати елемент в початок дека" << endl;
        cout << "2. ƒодати елемент в к≥нець дека" << endl;
        cout << "3. ¬идалити елемент з початку дека" << endl;
        cout << "4. ¬идалити елемент з к≥нц€ дека" << endl;
        cout << "5. ¬ивести поточний стан дека" << endl;
        cout << "6. ѕерев≥рити р€док на пал≥ндром" << endl;
        cout << "0. ¬ийти" << endl;

        cout << "¬аш виб≥р: ";
        cin >> choice;

        switch (choice) {
        case 1:
        case 2:
            int стаж, к≥льк≥сть–ечей, оц≥нка«≤нформатики, в≥к;
            float варт≥сть;
            cout << "¬вед≥ть значенн€ дл€ додаванн€ в дека:\n";
            cout << "—таж: "; cin >> стаж;
            cout << " ≥льк≥сть речей: "; cin >> к≥льк≥сть–ечей;
            cout << "ќц≥нка з ≥нформатики: "; cin >> оц≥нка«≤нформатики;
            cout << "¬≥к: "; cin >> в≥к;
            cout << "¬арт≥сть: "; cin >> варт≥сть;
            if (choice == 1) {
                myDeque.pushFront(стаж, к≥льк≥сть–ечей, оц≥нка«≤нформатики, в≥к, варт≥сть);
            }
            else {
                myDeque.pushBack(стаж, к≥льк≥сть–ечей, оц≥нка«≤нформатики, в≥к, варт≥сть);
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
            cout << "¬вед≥ть р€док дл€ перев≥рки на пал≥ндром: ";
            cin.ignore(); // ќчистка буфера перед getline
            getline(cin, input);
            if (isPalindrome(input)) {
                cout << "¬ведений р€док - пал≥ндром." << endl;
            }
            else {
                cout << "¬ведений р€док - не пал≥ндром." << endl;
            }
            break;

        case 0:
            cout << "¬их≥д." << endl;
            break;

        default:
            cout << "Ќев≥рний виб≥р. Ѕудь ласка, введ≥ть ще раз." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
