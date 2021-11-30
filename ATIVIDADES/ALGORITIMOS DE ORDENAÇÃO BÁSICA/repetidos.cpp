#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tamanho;

    cin >> tamanho;

	int vetor[tamanho];
	for(int i = 0; i < tamanho; i++)
	    cin >> vetor[i];

    int contador = 0;
    int trocas = 1;
    int aux = 1;
    int repetidos = 0;

	while(trocas){
		trocas = 0;
		contador++;
		for(int i = 0; i < tamanho-1; i++){
			if( vetor[i] > vetor[i+1]){
				int armazena_temp = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = armazena_temp;
				trocas = 1;
			}
		}
	}

  for(int i=0; i < tamanho; i++){
    // a começa com 1
    if(aux > 1) {
        repetidos++;
    }
    if(vetor[i] == vetor[i+1]){
        aux++;
    }else if(vetor[i] != vetor[i+1]){
        aux = 1;
    }

  }
	cout << repetidos << endl;
}
