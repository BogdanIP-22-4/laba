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
        std::cout << "\n Виберіть, що вивести: " << std::endl;
        std::cout << "1. Ввести кількість для стека" << std::endl;
        std::cout << "2. Послідовність дужок" << std::endl;
        std::cout << "3. Парні та непарні стеки" << std::endl;
        std::cout << "0. Вихід" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int n, num;

            std::cout << "Введіть кількість чисел для стеку: ";
            std::cin >> n;

            std::cout << "Введіть числа для стеку:\n";
            for (int i = 0; i < n; ++i) {
                std::cin >> num;
                myStack.push(num);
            }

            std::cout << "Стек: ";
            printStack(myStack);
            break;
        }

        case 3: {
            // Завдання 2
            std::stack<int> evenNumbers, oddNumbers;
            separateEvenOdd(myStack, evenNumbers, oddNumbers);

            std::cout << "Стек парних чисел: ";
            printStack(evenNumbers);

            std::cout << "Стек непарних чисел: ";
            printStack(oddNumbers);
            break;
        }

        case 2: {
            // Завдання 3
            std::string sequence;
            std::cout << "Введіть послідовність дужок: ";
            std::cin >> sequence;

            if (isCorrectSequence(sequence)) {
                std::cout << "Послідовність правильна.\n";
            }
            else {
                std::cout << "Послідовність неправильна.\n";
            }
            break;
        }

        case 0:
            std::cout << "До побачення!\n";
            break;

        default:
            std::cout << "Неправильний вибір. Спробуйте ще раз.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
