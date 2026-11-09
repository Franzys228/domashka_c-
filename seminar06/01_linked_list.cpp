#include <iostream>

struct ListNode {
    int value;
    mutable ListNode* next;
};

void print(const ListNode* head) {
    while (head != nullptr) {
        std::cout << head->value << ' ';
        head = head->next;
    }
    std::cout << '\n';
}

ListNode* insert_after(const ListNode* current, int value) {
    ListNode* node = new ListNode{value, nullptr};
    if (current != nullptr) {
        node->next = current->next;
        current->next = node;
    }
    return node;
}

ListNode* remove_after(const ListNode* current) {
    if (current == nullptr || current->next == nullptr) {
        return nullptr;
    }
    ListNode* removed = current->next;
    current->next = removed->next;
    ListNode* next = current->next;
    delete removed;
    return next;
}

void erase(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    ListNode* head = insert_after(nullptr, 1);
    ListNode* second = insert_after(head, 3);
    insert_after(head, 2);
    print(head);
    remove_after(head);
    print(head);
    erase(head);
    static_cast<void>(second);
}
