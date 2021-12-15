#include <iostream>
#include <vector>

using namespace std;

bool vetorOrdenado(vector<int> vetor){
  for (int i = 0; i < vetor.size() - 1; i++){
        if (vetor[i] > vetor[i + 1]){
            return false;
        }
    }

  return true;
}

int selecionar(vector<int> &vetor, int first, int last, int &contador){
  if (first < last){
    int index = first;
    for (int j = first + 1; j <= last; j++){
      if (vetor[j] < vetor[index])
        index = j;
    }

    if (first != index){
      swap(vetor[first], vetor[index]);
      contador++;
    }

    if (vetorOrdenado(vetor))
      return contador;
    selecionar(vetor, first + 1, last, contador);
  }
}

int main(){
  int tamanho, conta{0};

  cin >> tamanho;
  vector<int> vet(tamanho);

  for (int i = 0; i < tamanho; i++)
    cin >> vet[i];

  int valor = selecionar(vet, 0, tamanho - 1, conta);
  cout << valor << endl;
}
