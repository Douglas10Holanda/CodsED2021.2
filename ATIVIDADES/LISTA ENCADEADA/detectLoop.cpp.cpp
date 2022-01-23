#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ListNode {
    public:  int value;
    ListNode *next;

    ListNode() : value(0), next(nullptr) {}
    ListNode(int x) : value(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : value(x), next(next) {}
};

ListNode *readList() {
    int n, x;

    cin >> n >> x;

    ListNode *cabeca;
    ListNode *tmp = nullptr;

    ListNode *ptr;

    for (int i = 1; i <= n; i++) {
        int v;

        cin >> v;

        if (i == 1) {
            cabeca = new ListNode(v);
            ptr = cabeca;
        } else {
            ptr -> next = new ListNode(v, nullptr);
            ptr = ptr -> next;
        }

        if (i == x) {
            tmp = ptr;
        }
    }

    ptr -> next = tmp;

    return cabeca;
}
// Função preenchida
bool detectLoop(ListNode *head) {
    ListNode *coelho = head;
    ListNode *tartaruga = head;

    while (coelho != nullptr && coelho -> next) {
        coelho = coelho -> next -> next;
        tartaruga = tartaruga -> next;

        if (coelho -> value == tartaruga -> value) {
            return 1;
        }
    }

    return 0;
}

int main() {

  ListNode *head = readList();

  cout << detectLoop(head) << endl;

  return 0;
}
