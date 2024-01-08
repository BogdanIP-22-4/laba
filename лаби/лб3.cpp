#include <iostream>
#include <stack>
#include <string>

void printStack(const std::stack<int>& stk) {
    std::stack<int> temp = stk;
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

void separateEvenOdd(std::stack<int>& original, std::stack<int>& evenStack, std::stack<int>& oddStack) {
    while (!original.empty()) {
        int num = original.top();
        original.pop();

        if (num % 2 == 0) {
            evenStack.push(num);
        }
        else {
            oddStack.push(num);
        }
    }
}

bool isCorrectSequence(const std::string& sequence) {
    std::stack<char> brackets;

    for (char bracket : sequence) {
        if (bracket == '(' || bracket == '[') {
            brackets.push(bracket);
        }
        else if (bracket == ')' || bracket == ']') {
            if (brackets.empty()) {
                return false; // Unmatched bracket, the sequence is incorrect
            }

            char openBracket = brackets.top();
            brackets.pop();

            if ((bracket == ')' && openBracket != '(') || (bracket == ']' && openBracket != '[')) {
                return false; // Unmatched brackets, the sequence is incorrect
            }
        }
    }

    return brackets.empty(); // The sequence is correct if the stack is empty
}

int main() {
    int choice;
    std::stack<int> myStack;  // Move the declaration outside the do-while loop

    do {
        std::cout << "\n �������, �� �������: " << std::endl;
        std::cout << "1. ������ ������� ��� �����" << std::endl;
        std::cout << "2. ����������� �����" << std::endl;
        std::cout << "3. ���� �� ������ �����" << std::endl;
        std::cout << "0. �����" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int n, num;

            std::cout << "������ ������� ����� ��� �����: ";
            std::cin >> n;

            std::cout << "������ ����� ��� �����:\n";
            for (int i = 0; i < n; ++i) {
                std::cin >> num;
                myStack.push(num);
            }

            std::cout << "����: ";
            printStack(myStack);
            break;
        }

        case 3: {
            // �������� 2
            std::stack<int> evenNumbers, oddNumbers;
            separateEvenOdd(myStack, evenNumbers, oddNumbers);

            std::cout << "���� ������ �����: ";
            printStack(evenNumbers);

            std::cout << "���� �������� �����: ";
            printStack(oddNumbers);
            break;
        }

        case 2: {
            // �������� 3
            std::string sequence;
            std::cout << "������ ����������� �����: ";
            std::cin >> sequence;

            if (isCorrectSequence(sequence)) {
                std::cout << "����������� ���������.\n";
            }
            else {
                std::cout << "����������� �����������.\n";
            }
            break;
        }

        case 0:
            std::cout << "�� ���������!\n";
            break;

        default:
            std::cout << "������������ ����. ��������� �� ���.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
