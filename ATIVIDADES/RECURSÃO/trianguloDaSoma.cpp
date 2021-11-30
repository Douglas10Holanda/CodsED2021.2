#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void triangle(vector<int> & vet, int size) {
  if (size < 1) return;

  vector<int> temp;
  for (int i = 0; i < size - 1; i++)
    temp.push_back(vet[i] + vet[i + 1]);

  triangle(temp, size - 1);

  cout << "[ ";
  for (int i = 0; i < size; i++)
    cout << vet[i] << " ";

  cout << "]" << endl;
}

int main() {
  string linha;
  getline(cin, linha);
  stringstream ss(linha);
  vector<int> vet;

  int valor;
  while(ss >> valor)
    vet.push_back(valor);


  triangle(vet, vet.size());

  return 0;
}
