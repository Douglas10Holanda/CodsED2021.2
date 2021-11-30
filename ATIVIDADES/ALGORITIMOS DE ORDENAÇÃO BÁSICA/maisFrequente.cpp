#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tamanho;
	cin >> tamanho;

	int vetor[tamanho];

	for(int i = 0; i < tamanho; i++){
	    cin >> vetor[i];
	}

    int numero = vetor[0];
    int repeticoes = 0;
    int contador = 0;

    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(vetor[i] == vetor[j]){
                contador++;
            }
        }
        if(contador > repeticoes){
            numero = vetor[i];
            repeticoes = contador;
        }
        contador=0;
    }
    cout << numero << " " << repeticoes << endl;
}
