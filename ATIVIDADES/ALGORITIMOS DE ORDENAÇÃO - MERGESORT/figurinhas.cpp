#include <iostream>
#include <vector>

using namespace std;

void ordenaVetor(vector<int> &vetor, int inicio, int meio, int fim){
  int x = inicio;
  int y = meio + 1;
  int z = 0;

  vector<int> vet;
  vet.resize(fim - inicio + 1);

  while (x <= meio && y <= fim){
    if (vetor[x] < vetor[y]){
        vet[z] = vetor[x], z++, x++;
    } else {
        vet[z] = vetor[y], z++, y++;
    }
  }

  while (x <= meio) {
    vet[z] = vetor[x], z++,x++;
  }
  while (y <= fim) {
    vet[z] = vetor[y], z++, y++;
  }
  for (int x = inicio; x <= fim; x++) {
    vetor[x] = vet[x - inicio];
  }
}

void dividindo(vector<int> &vetor, int inicio, int fim){
  if (fim > inicio){
    int meio = (inicio + fim) / 2;
    dividindo(vetor, inicio, meio);
    dividindo(vetor, meio + 1, fim);
    ordenaVetor(vetor, inicio, meio, fim);
  }
}

bool igualdade(vector<int> b, vector<int> g){
  for (int i = 0; i < b.size() - 1; i++){
    if (b[i] != g[i]){
      return false;
    }
  }

  return true;
}

int main(){
  int tamanho;

  cin >> tamanho;

  vector<int> b(tamanho), g(tamanho);

  for (int i = 0; i < tamanho; i++){
    cin >> b[i];
  }

  for (int i = 0; i < tamanho; i++){
    cin >> g[i];
  }

  dividindo(b, 0, tamanho - 1);
  dividindo(g, 0, tamanho - 1);

  int result = igualdade(b, g) ? 1 : 0;
  cout << result << endl;
}
