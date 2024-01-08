#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <unordered_set> // ��� ������������ unordered_set
using namespace std;

// ���������� ��������� ��� ����� ������
struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const string& value) : data(value), left(nullptr), right(nullptr) {}
};

// ��������� ����� �� ������
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

// ��������� ������ �� ����� � ������ ������
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

// ����� ����� � ��������� � �������� ����� ������
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

    return nullptr; // �������� ��������
}

// ����������� ������������� �������� � �������� ����� ������
int findMax(TreeNode* root) {
    while (root->right != nullptr) {
        root = root->right;
    }
    return stoi(root->data); // ������������ ����� �� ���� �����
}

// ϳ�������� ������� ������, �� ������ �����, ��������� � ����� �����
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

// ��������� ������, �� ������ �����, ��������� � ����� �����
TreeNode* removeNodesStartingWith(TreeNode* root, char targetLetter) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data[0] == targetLetter) {
        // ��������� ������� �������
        TreeNode* temp = root;
        root = nullptr;
        delete temp;
    }
    else {
        // ���������� ��������� � ����� � ������� ���������
        root->left = removeNodesStartingWith(root->left, targetLetter);
        root->right = removeNodesStartingWith(root->right, targetLetter);
    }

    return root;
}

// ��������� ���'��, ��������� ��� �� ��������� ������
void cleanup(TreeNode* root) {
    if (root != nullptr) {
        cleanup(root->left);
        cleanup(root->right);
        cout << root->data << " ";
        delete root;
    }
}

// ��������� �������� � ������
void removeDuplicates(TreeNode* root, unordered_set<char>& seenChars) {
    if (root == nullptr) {
        return;
    }

    // ���������� ��������� ������� ��� ����� � ������� ��������
    removeDuplicates(root->left, seenChars);
    removeDuplicates(root->right, seenChars);

    // ��������� �����, ���� ���� ��� ���� ������
    if (seenChars.find(root->data[0]) != seenChars.end()) {
        TreeNode* temp = root;
        root = nullptr;
        delete temp;
    }
    else {
        seenChars.insert(root->data[0]);
    }
}

// ����������� ����� �� ��������� �������� ������
void postfixTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // ���������� ��������� ������� ��� ����� � ������� ��������
    postfixTraversal(root->left);
    postfixTraversal(root->right);

    // �������� ������� ��� �����
    cout << root->data << " ";
}

int main() {
    int choice;

    do {
        cout << "\n������� �� �������." << endl;
        cout << "1. ֳ��������� ������ ������ ������" << endl;
        cout << "2. ��������� ������ ������ ������" << endl;
        cout << "3. �������� ������ ������ ������ � ���������� �����" << endl;
        cout << "4. �����" << endl;

        // Get user choice
        cout << "��� ����: ";
        cin >> choice;
        cin.ignore();  // ��� �������� ������� ������� ������ ����� � ������

        switch (choice) {
        case 1: {
            // ��� ��� ������������� �������� ������ ������
            TreeNode* root = nullptr;

            // �������� ����� � ���������
            cout << "������ ��� ����� ��� �������� ������ (�������� 0 ��������� ��������):" << endl;
            int inputValue;
            do {
                cin >> inputValue;
                if (inputValue != 0) {
                    root = insert(root, to_string(inputValue));  // Convert integer to string for TreeNode
                }
            } while (inputValue != 0);

            // ��������� ������ �� �����
            cout << "������� ������ ������:" << endl;
            printTree(root);

            // ����� ����� � ������� ������
            int searchValue;
            cout << "\n������ ����� ��� ������ � �����: ";
            cin >> searchValue;
            TreeNode* foundNode = search(root, to_string(searchValue));  // Convert integer to string for search
            if (foundNode != nullptr) {
                cout << "\n����� � ��������� " << searchValue << " �������� � �����." << endl;
            }
            else {
                cout << "\n����� � ��������� " << searchValue << " �� �������� � �����." << endl;
            }

            // ����������� ������������� �������� � �����
            int maxElement = findMax(root);
            cout << "\n������������ ������� � �����: " << maxElement << endl;

            break;
        }
        case 2: {
            // ��� ��� ����������� �������� ������ ������
            TreeNode* root = nullptr;

            // �������� ����� � ���������
            string inputString;
            cout << "������ ����� � �������: ";
            getline(cin, inputString);

            // ��������� ���� �� ������
            for (char ch : inputString) {
                // �������� ������
                if (ch != ' ') {
                    root = insert(root, string(1, ch));  // Convert char to string for TreeNode
                }
            }

            // ��������� ������ �� �����
            cout << "������� ������ ������:" << endl;
            printTree(root);

            // ����������� �� ��������� ��������
            unordered_set<char> seenChars;
            removeDuplicates(root, seenChars);

            // ��������� �������� ������, �� ����������, ��� ������������ �����
            cout << "\n�������� ������ ���� ��������� �������� (����������� �����):" << endl;
            postfixTraversal(root);

            break;
        }
        case 3: {
            // ��� ��� ���������� �������� ������ ������ � ���������� �����
            ifstream file("����.txt");  // ������ "your_text_file.txt" �� ���� �� ������ ���������� �����

            if (!file.is_open()) {
                cerr << "��������� ������� ����." << endl;
                return 1;
            }

            TreeNode* root = nullptr;
            string word;

            // ��������� ��� �� ������
            while (file >> word) {
                root = insert(root, word);
            }

            // ��������� ������ �� �����
            cout << "������� ������ ������:" << endl;
            printTree(root);

            // �������� ����� ��� ���������� �� ��������� ������
            char targetLetter;
            cout << "\n������ ����� ��� ���������� �� ��������� ������: ";
            cin >> targetLetter;

            // ���������� �� ��������� ������� ������ ����� ����������
            int countBeforeRemoval = countNodesStartingWith(root, targetLetter);
            cout << "\nʳ������ ������, �� ������ �����, ��������� � ����� '" << targetLetter << "': " << countBeforeRemoval << endl;

            // ��������� ������
            root = removeNodesStartingWith(root, targetLetter);

            // ��������� ������ ���� ��������� �� �����
            cout << "\n������� ������ ������ ���� ��������� ������:" << endl;
            printTree(root);

            // ��������� ���'�� �� ��������� ��� ������ ��� ���� ��������
            cout << "\n����� � ����� ��� �������� ���'�� (����������� �����):" << endl;
            cleanup(root);

            break;
        }
        case 4: {
            // ����� � ��������
            cout << "����������!" << endl;
            break;
        }
        default: {
            // ������� ����
            cout << "������������ ����. ��������� �� ���." << endl;
            break;
        }
        }

    } while (choice != 4);

    return 0;
}
