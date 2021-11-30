#include <iostream>
#include <vector>

using namespace std;

void Mostrar(vector<int> vet) {
    int aux = vet.size() - 1;

    for(int i = 0; i < vet.size(); i++){
        if(i != aux){
            cout << vet[i] << " ";
        }else{
            cout << vet[i];
        }
    }

    cout << endl;
}

int Pesquisa(vector<int> vet, int tamanho, int item){
  int begin = 0;
  int end = tamanho - 1;
  int contador = 0;

  while (begin <= end){
    int center = (begin + end) / 2;
    contador++;

    if (vet[center] == item)
      break;
    else{
      if (vet[center] > item)
        end = center - 1;
      else
        begin = center + 1;
    }
  }

  return contador;
}

void Pesquisar(vector<int> vet, vector<int> buscar){
  int tamanhoVetor = vet.size();
  int tamanhoBusca = buscar.size();

  vector<int> result(tamanhoBusca);

  for (int i = 0; i < tamanhoBusca; i++){
      result[i] = Pesquisa(vet, tamanhoVetor, buscar[i]);
  }

  Mostrar(result);
}

int main(){
  int x, y;

  cin >> x >> y;

  vector<int> vector(x), busca(y);

  for (int i = 0; i < x; i++)
    cin >> vector[i];

  for (int i = 0; i < y; i++)
    cin >> busca[i];

  Pesquisar(vector, busca);
}
