#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tamanho;
	cin >> tamanho;

	int vetor[tamanho];
    int posicao[tamanho];

	for(int i = 0; i < tamanho; i++){
        cin >> vetor[i];
        posicao[i] = i;
    }

	int contador = 0;
	int trocas = 1;

	while(trocas){
		trocas = 0;
		contador++;
		for(int i = 0; i < tamanho-1; i++){
		    if( vetor[i] > vetor[i+1]){

		        int armazena_temp = vetor[i];
                int guarda_temp = posicao[i];

            	vetor[i] = vetor[i+1];
                posicao[i] = posicao[i+1];

            	vetor[i+1] = armazena_temp;
                posicao[i+1] = guarda_temp;

				trocas = 1;
			}
		}
	}

	for(int i = 0; i < tamanho; i++){
	    cout << posicao[i];
        if(i < (tamanho-1)) cout << " ";
        if(i == (tamanho-1)) cout << endl;
  }
}
