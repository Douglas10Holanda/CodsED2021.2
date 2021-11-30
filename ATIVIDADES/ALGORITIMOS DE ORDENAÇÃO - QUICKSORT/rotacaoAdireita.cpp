#include <iostream>
#include <vector>
using namespace std;

void rotacao(vector<int>& vet, int numRotacao){
    for (int i = 0; i < numRotacao; i++){
        int aux = vet[vet.size() - 1];
        int j = vet.size() - 1;
        while(j >= 0){
            if (j == 0){
            vet[0] = aux;
            break;
          }
          vet[j] = vet[j - 1];
          j--;
        }
    }
}

void mostrar(vector<int> &vet) {
    cout << "[ ";
    for(int valor : vet)
        cout << valor << " ";
    cout << "]\n";
}

int main(){
    int tamanho, numRotacao;
    cin >> tamanho >> numRotacao;
    vector<int> vet(tamanho);
    for(int i = 0; i < tamanho; i++)
        cin >> vet[i];

    rotacao(vet, numRotacao);
    mostrar(vet);
}
