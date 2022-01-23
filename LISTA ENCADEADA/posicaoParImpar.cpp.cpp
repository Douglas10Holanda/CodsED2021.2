#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ListNode {
    public: int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head) {
    int cont = 1;
    ListNode *auxi = nullptr;
    ListNode *auxiptr;

  // impar
    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr -> next) {
        if (cont == 1) {
            auxi = new ListNode(ptr -> val);
            auxiptr = auxi;
        } else if (cont % 2 != 0) {
            auxiptr -> next = new ListNode(ptr -> val, nullptr);
            auxiptr = auxiptr -> next;
        }
        cont++;
    }

    cont = 1;

    // Par
    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr -> next) {
        if (cont % 2 == 0) {
            auxiptr -> next = new ListNode(ptr -> val, nullptr);
            auxiptr = auxiptr -> next;
        }
        cont++;
    }
    return auxi;
}

int main() {
    int num;
    ListNode *head = nullptr;

    cin >> num;

    for (int i = 0; i < num; i++) {
        ListNode *ptr;
        int n;

        cin >> n;

        if (i == 0) {
            head = new ListNode(n);
            ptr = head;
        } else {
            ptr -> next = new ListNode(n, nullptr);
            ptr = ptr -> next;
        }
    }

    head = oddEvenList(head);

    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr -> next) {
        cout << ptr -> val << endl;
    }

    return 0;
}
