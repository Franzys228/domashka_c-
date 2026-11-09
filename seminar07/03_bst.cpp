#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
};

bool contains(const Node* root, int value) {
    while (root != nullptr) {
        if (root->value == value) {
            return true;
        }
        root = value < root->value ? root->left : root->right;
    }
    return false;
}

bool insert(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node{value, nullptr, nullptr};
        return true;
    }
    if (root->value == value) {
        return false;
    }
    return insert(value < root->value ? root->left : root->right, value);
}

Node* takeMinimum(Node*& root) {
    if (root->left == nullptr) {
        Node* result = root;
        root = root->right;
        return result;
    }
    return takeMinimum(root->left);
}

bool remove(Node*& root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (value < root->value) {
        return remove(root->left, value);
    }
    if (value > root->value) {
        return remove(root->right, value);
    }

    Node* old = root;
    if (root->left == nullptr) {
        root = root->right;
    } else if (root->right == nullptr) {
        root = root->left;
    } else {
        Node* next = takeMinimum(root->right);
        next->left = root->left;
        next->right = root->right;
        root = next;
    }
    delete old;
    return true;
}

void print(const Node* root) {
    if (root == nullptr) {
        return;
    }
    print(root->left);
    std::cout << root->value << ' ';
    print(root->right);
}

void erase(Node* root) {
    if (root == nullptr) {
        return;
    }
    erase(root->left);
    erase(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    char operation;
    int value;
    while (std::cin >> operation >> value) {
        if (operation == 'i') {
            std::cout << (insert(root, value) ? "true" : "false") << '\n';
        } else if (operation == 'd') {
            std::cout << (remove(root, value) ? "true" : "false") << '\n';
        } else if (operation == 's') {
            std::cout << (contains(root, value) ? "true" : "false") << '\n';
        } else {
            erase(root);
            return 1;
        }
    }
    print(root);
    std::cout << '\n';
    erase(root);
}
