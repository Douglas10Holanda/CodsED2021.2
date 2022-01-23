#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int x, valor;
    vector<int> inteiros, imprimir;
    stack<int> val;

    cin >> x;

    imprimir.resize(x);

    for (int i = 0; i < x; i++) {
        cin >> valor;

        inteiros.push_back(valor);
    }

    for (int i = 0; i < x; i++) {
        if (i == 0) {
            val.push(i);
        } else {
            if (inteiros[i] > inteiros[val.top()]) {
                while (!val.empty()) {
                    if (inteiros[i] > inteiros[val.top()]) {
                        imprimir[val.top()] = i;
                        val.pop();
                    } else {
                        break;
                    }
                }
                val.push(i);
            } else {
                val.push(i);
            }
        }
    }

    while (!val.empty()) {
        imprimir[val.top()] = -1;
        val.pop();
    }

    for (int i = 0; i < x; i++) {
        if (i == x - 1) {
            cout << imprimir[i] << endl;
            break;
        }
        cout << imprimir[i] << " ";
    }
}
