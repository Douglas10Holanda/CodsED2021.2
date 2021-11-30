#include <iostream>

using namespace std;

int bubblesort(int vet[], int tamanho2){
  int contador = 0;
  bool troca = true;

  while (troca != false){
    troca = false;
    contador++;
    for (int i = 0; i < tamanho2 - 1; i++){
      if (vet[i] > vet[i + 1]){
        swap(vet[i], vet[i + 1]);
        troca = true;
      }
    }
  }
  return contador;
}

int main(){
  int tamanho;
  int valores;

  // vai ler o tamanho do vetor
  cin >> tamanho;

  // cria vetor e o percorre lendo valores do teclado
  int vetor[tamanho];
  for (int i = 0; i < tamanho; i++){
    cin >> vetor[i];
    }
  // imprime o numero de interações na tela
  cout << bubblesort(vetor, tamanho) << endl;
}
