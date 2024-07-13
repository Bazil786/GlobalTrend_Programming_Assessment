#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next_node = nullptr;
   while (current != nullptr) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    return prev;
}
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    std::cout << "Original list: ";
    printList(head);
    ListNode* reversed_head = reverseLinkedList(head);
    std::cout << "Reversed list: ";
    printList(reversed_head);
    while (reversed_head != nullptr) {
        ListNode* temp = reversed_head;
        reversed_head = reversed_head->next;
delete temp;
    }
    return 0;
}
