#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
};

ListNode* reverse_rec(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* newHead = reverse_rec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

ListNode* reverse_itr(ListNode* head) {
    ListNode* prev = nullptr;
    while (head != nullptr) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

void print(const ListNode* head) {
    while (head != nullptr) {
        std::cout << head->value << ' ';
        head = head->next;
    }
    std::cout << '\n';
}

void erase(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    ListNode* head = new ListNode{1, new ListNode{2, new ListNode{3, nullptr}}};
    head = reverse_rec(head);
    print(head);
    head = reverse_itr(head);
    print(head);
    erase(head);
}
