#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <unordered_set> // Для використання unordered_set
using namespace std;

// Визначення структури для вузла дерева
struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const string& value) : data(value), left(nullptr), right(nullptr) {}
};

// Додавання вузла до дерева
TreeNode* insert(TreeNode* root, const string& value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Виведення дерева на екран у вигляді дерева
void printTree(TreeNode* root, int space = 0) {
    const int INDENTATION = 5;

    if (root == nullptr) {
        return;
    }

    space += INDENTATION;

    printTree(root->right, space);

    cout << endl;
    for (int i = INDENTATION; i < space; i++) {
        cout << " ";
    }
    cout << root->data << "\n";

    printTree(root->left, space);
}

// Пошук вузла зі значенням у бінарному дереві пошуку
TreeNode* search(TreeNode* root, const string& value) {
    if (root == nullptr || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    }
    else if (value > root->data) {
        return search(root->right, value);
    }

    return nullptr; // Значення знайдено
}

// Знаходження максимального елемента у бінарному дереві пошуку
int findMax(TreeNode* root) {
    while (root->right != nullptr) {
        root = root->right;
    }
    return stoi(root->data); // Перетворення рядка на ціле число
}

// Підрахунок кількості вершин, які містять слова, починаючи з певної букви
int countNodesStartingWith(TreeNode* root, char targetLetter) {
    if (root == nullptr) {
        return 0;
    }

    int count = 0;
    if (root->data[0] == targetLetter) {
        count = 1;
    }

    count += countNodesStartingWith(root->left, targetLetter);
    count += countNodesStartingWith(root->right, targetLetter);

    return count;
}

// Видалення вершин, які містять слова, починаючи з певної букви
TreeNode* removeNodesStartingWith(TreeNode* root, char targetLetter) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data[0] == targetLetter) {
        // Видалення поточної вершини
        TreeNode* temp = root;
        root = nullptr;
        delete temp;
    }
    else {
        // Рекурсивне видалення в лівому і правому піддеревах
        root->left = removeNodesStartingWith(root->left, targetLetter);
        root->right = removeNodesStartingWith(root->right, targetLetter);
    }

    return root;
}

// Звільнення пам'яті, виведення слів та звільнення дерева
void cleanup(TreeNode* root) {
    if (root != nullptr) {
        cleanup(root->left);
        cleanup(root->right);
        cout << root->data << " ";
        delete root;
    }
}

// Видалення дублікатів з дерева
void removeDuplicates(TreeNode* root, unordered_set<char>& seenChars) {
    if (root == nullptr) {
        return;
    }

    // Рекурсивно викликаємо функцію для лівого і правого піддерева
    removeDuplicates(root->left, seenChars);
    removeDuplicates(root->right, seenChars);

    // Видаляємо букву, якщо вона вже була додана
    if (seenChars.find(root->data[0]) != seenChars.end()) {
        TreeNode* temp = root;
        root = nullptr;
        delete temp;
    }
    else {
        seenChars.insert(root->data[0]);
    }
}

// Постфіксний обхід та виведення елементів дерева
void postfixTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Рекурсивно викликаємо функцію для лівого і правого піддерева
    postfixTraversal(root->left);
    postfixTraversal(root->right);

    // Виводимо елемент при обході
    cout << root->data << " ";
}

int main() {
    int choice;

    do {
        cout << "\nВиберіть що вивести." << endl;
        cout << "1. Цілочислове бінарне дерево пошуку" << endl;
        cout << "2. Символьне бінарне дерево пошуку" << endl;
        cout << "3. Строкове бінарне дерево пошуку з текстового файлу" << endl;
        cout << "4. Вийти" << endl;

        // Get user choice
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();  // Щоб видалити залишки символів нового рядка з буфера

        switch (choice) {
        case 1: {
            // Код для цілочислового бінарного дерева пошуку
            TreeNode* root = nullptr;

            // Введення чисел з клавіатури
            cout << "Введіть цілі числа для побудови дерева (введення 0 завершить введення):" << endl;
            int inputValue;
            do {
                cin >> inputValue;
                if (inputValue != 0) {
                    root = insert(root, to_string(inputValue));  // Convert integer to string for TreeNode
                }
            } while (inputValue != 0);

            // Виведення дерева на екран
            cout << "Двійкове дерево пошуку:" << endl;
            printTree(root);

            // Пошук вузла з заданим числом
            int searchValue;
            cout << "\nВведіть число для пошуку в дереві: ";
            cin >> searchValue;
            TreeNode* foundNode = search(root, to_string(searchValue));  // Convert integer to string for search
            if (foundNode != nullptr) {
                cout << "\nВузол зі значенням " << searchValue << " знайдено в дереві." << endl;
            }
            else {
                cout << "\nВузол зі значенням " << searchValue << " не знайдено в дереві." << endl;
            }

            // Знаходження максимального елемента в дереві
            int maxElement = findMax(root);
            cout << "\nМаксимальний елемент в дереві: " << maxElement << endl;

            break;
        }
        case 2: {
            // Код для символьного бінарного дерева пошуку
            TreeNode* root = nullptr;

            // Введення рядка з клавіатури
            string inputString;
            cout << "Введіть рядок з буквами: ";
            getline(cin, inputString);

            // Додавання букв до дерева
            for (char ch : inputString) {
                // Ігноруємо пробіли
                if (ch != ' ') {
                    root = insert(root, string(1, ch));  // Convert char to string for TreeNode
                }
            }

            // Виведення дерева на екран
            cout << "Двійкове дерево пошуку:" << endl;
            printTree(root);

            // Знаходження та видалення дублікатів
            unordered_set<char> seenChars;
            removeDuplicates(root, seenChars);

            // Виведення елементів дерева, що залишилися, при постфіксному обході
            cout << "\nЕлементи дерева після видалення дублікатів (постфіксний обхід):" << endl;
            postfixTraversal(root);

            break;
        }
        case 3: {
            // Код для строкового бінарного дерева пошуку з текстового файлу
            ifstream file("лаба.txt");  // Замініть "your_text_file.txt" на шлях до вашого текстового файлу

            if (!file.is_open()) {
                cerr << "Неможливо відкрити файл." << endl;
                return 1;
            }

            TreeNode* root = nullptr;
            string word;

            // Додавання слів до дерева
            while (file >> word) {
                root = insert(root, word);
            }

            // Виведення дерева на екран
            cout << "Двійкове дерево пошуку:" << endl;
            printTree(root);

            // Введення букви для визначення та видалення вершин
            char targetLetter;
            cout << "\nВведіть букву для визначення та видалення вершин: ";
            cin >> targetLetter;

            // Визначення та виведення кількості вершин перед видаленням
            int countBeforeRemoval = countNodesStartingWith(root, targetLetter);
            cout << "\nКількість вершин, що містять слова, починаючи з букви '" << targetLetter << "': " << countBeforeRemoval << endl;

            // Видалення вершин
            root = removeNodesStartingWith(root, targetLetter);

            // Виведення дерева після видалення на екран
            cout << "\nДвійкове дерево пошуку після видалення вершин:" << endl;
            printTree(root);

            // Звільнення пам'яті та виведення слів дерева при його звільненні
            cout << "\nСлова в дереві при звільненні пам'яті (постфіксний обхід):" << endl;
            cleanup(root);

            break;
        }
        case 4: {
            // Вихід з програми
            cout << "Заверешено!" << endl;
            break;
        }
        default: {
            // Невірний вибір
            cout << "Неправильний вибір. Спробуйте ще раз." << endl;
            break;
        }
        }

    } while (choice != 4);

    return 0;
}
