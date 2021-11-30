#include <iostream>
#include <vector>

using namespace std;

void mostrar(vector<int> vet) {
  for (int in : vet) cout << in << " ";
  cout << "\n";
}

int main() {
  int tamanho = 0,
      retiraQtd = 0;

  vector<int> vet;

  cin >> tamanho;
  int temp = 0;
  for (int i = 0; i < tamanho; i++) {
    cin >> temp;
    vet.push_back(temp);
  }

  cin >> retiraQtd;
  int p = 0;

  int tamanhoNovo = tamanho;
  for (int i = 0; i < retiraQtd; i++) {
    cin >> p;

    for (int j = 0; j < (int) vet.size(); j++) {
      if (vet[j] == p) {
        vet.erase(vet.begin() + j);
        break;
      }
    }
  }

  mostrar(vet);

  return 0;
}
