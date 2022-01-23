#ifndef Raioshpp
#define Raioshpp

#include <iostream>
#include <vector>

using namespace std;

class Raios {
    private: int largura;
    int altura;
    vector<int> x, y;

    public: Raios(int n, int m) {
        this -> largura = n;
        this -> altura = m;
    }

    void add(int x, int y) {
        this -> x.push_back(x);
        this -> y.push_back(y);
    }

    int mesmo_lugar() {
        for (int k = 0; k < x.size(); k++) {
            for (int q = k + 1; q < x.size(); q++) {
                if (x[k] == x[q] && y[k] == y[q]) {
                    return 1;
                }
            }
        }

        return 0;
    }
};

#endif
