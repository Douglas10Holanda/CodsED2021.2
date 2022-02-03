#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void eleSet(queue<char> *x) {
    int value = 65;

    while (value <= 80) {
        x -> push(value);
        value++;
    }
}

// flamengo é o time 1 e o vasco é time 2 kkk
char copaDoBrasil(queue<char> row, vector<int> flamengo, vector<int> vasco) {
    int num = 0;

    while (row.size() != 1) {
        if (num == 17) {
            num == 0;
        }

        if (flamengo[num] < vasco[num]) {
            row.pop();
            char aux = row.front();
            row.pop();
            row.push(aux);
        } else {
        char aux = row.front();

        row.pop();
        row.pop();
        row.push(aux);
        }
        num++;
    }
    return row.front();
}

int main() {
    queue<char> q;
    vector<int> flamengo(16), vasco(16);
    eleSet(&q);

    for (int i = 0; i < 16; i++) {
        cin >> flamengo[i] >> vasco[i];
    }

    char aux = copaDoBrasil(q, flamengo, vasco);
    cout << aux << endl;
}
