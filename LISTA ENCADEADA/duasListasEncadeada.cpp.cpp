#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ListNode {
    public: int valor;
    ListNode *proximo;

    ListNode() : valor(0), proximo(nullptr) {}
    ListNode(int x) : valor(x), proximo(nullptr) {}
    ListNode(int x, ListNode *next) : valor(x), proximo(next) {}
};

ListNode *insert_back(ListNode *head, int val) {
    if (head == nullptr) {
        return new ListNode(val);
    } else {
        head -> proximo = insert_back(head -> proximo, val);
    return head;
    }
}

ListNode *mergeTwoLists(ListNode *L1, ListNode *L2) {
    ListNode *auxi = nullptr;
    ListNode *auxiptr;

    if (L1 -> valor > L2 -> valor) {
        auxi = new ListNode(L2 -> valor);
        auxiptr = auxi;
        L2 = L2 -> proximo;
    } else {
        auxi = new ListNode(L1 -> valor);
        auxiptr = auxi;
        L1 = L1 -> proximo;
    }

    while (L1 != nullptr && L2 != nullptr) {
        if (L2 -> valor < L1 -> valor) {
            insert_back(auxi, L2 -> valor);
            L2 = L2 -> proximo;
        } else {
            insert_back(auxi, L1 -> valor);
            L1 = L1 -> proximo;
        }
    }

    while (L1 != nullptr) {
        insert_back(auxi, L1 -> valor);
        L1 = L1 -> proximo;
    }

    while (L2 != nullptr) {
        insert_back(auxi, L2 -> valor);
        L2 = L2 -> proximo;
    }

    return auxi;
}

ListNode *readList() {
    int n;

    cin >> n;

    ListNode *cabeca = nullptr;

    for (int i = 0; i < n; i++) {
        ListNode *ponteiro;
        int x;

        cin >> x;

        if (i == 0) {
            cabeca = new ListNode(x);
            ponteiro = cabeca;
        } else {
            ponteiro -> proximo = new ListNode(x, nullptr);
            ponteiro = ponteiro -> proximo;
        }
    }
    return cabeca;
}

int main() {
    ListNode *list1 = readList();
    ListNode *list2 = readList();
    ListNode *head = mergeTwoLists(list1, list2);

    for (auto *pont = head; pont != nullptr; pont = pont -> proximo) {
        cout << pont -> valor << endl;
    }

    return 0;
}
