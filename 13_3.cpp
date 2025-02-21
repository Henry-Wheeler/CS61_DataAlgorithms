#include <iostream>

using namespace std;

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int val) : data(val), next(nullptr) {}
};

void splitList(ListNode* source, ListNode** front, ListNode** back) {
    if (!source || !source->next) {
        *front = source;
        *back = nullptr;
        return;
    }

    ListNode* slow = source;
    ListNode* fast = source->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

ListNode* mergeLists(ListNode* a, ListNode* b) {
    if (!a) return b;
    if (!b) return a;

    ListNode* result = nullptr;

    if (a->data <= b->data) {
        result = a;
        result->next = mergeLists(a->next, b);
    } else {
        result = b;
        result->next = mergeLists(a, b->next);
    }

    return result;
}

void mergeSort(ListNode** headRef) {
    ListNode* head = *headRef;
    if (!head || !head->next) return;

    ListNode* front;
    ListNode* back;

    splitList(head, &front, &back);

    mergeSort(&front);
    mergeSort(&back);

    *headRef = mergeLists(front, back);
}

void insertNode(ListNode** head, int data) {
    ListNode* newNode = new ListNode(data);
    if (!*head) {
        *head = newNode;
        return;
    }

    ListNode* temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

