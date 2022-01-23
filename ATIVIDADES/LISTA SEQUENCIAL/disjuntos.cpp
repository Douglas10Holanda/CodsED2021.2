#ifndef Disjuntoshpp

#define Disjuntoshpp

#include <iostream>
#include <vector>

using namespace std;

class Disjuntos {
    private: vector<int> x, y, mesmos;

    public: Disjuntos(int n) {
        int aux = n - 1;

        for (int i = 0; i < n; i < i++) {
          x.push_back(i);
          y.push_back(aux);
          aux--;
        }
    }

    void une(int i, int j) {
        bool n1, n2 = false;

        for (int k = 0; k < mesmos.size(); k++) {
            if (mesmos[k] == i) {
                n1 = true;
            } else if (mesmos[k] == j) {
                n2 = true;
            }
        }

        if (n1 == false) {
            mesmos.push_back(i);
        }

        if (n2 == false) {
            mesmos.push_back(j);
        }
    }

  int mesmo(int x, int y) {
    int contador = 0;

    for (int k : mesmos) {
        if (k == x) {
            contador++;
        } else if (k == y) {
            contador++;
        }
    }

    if (contador >= 2) {
        return 1;
    }

    return 0;
  }
};

#endif
