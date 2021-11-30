#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tamanho;
	cin >> tamanho;

	int vetorVacinas[tamanho];
    int vetorPessoas[tamanho];
	for(int i = 0; i < tamanho; i++){
        cin >> vetorVacinas[i];
    }

    for(int i = 0; i < tamanho; i++){
        cin >> vetorPessoas[i];
    }

	int contador = 0;
	int trocas = 1;

	while(trocas){
	trocas = 0;
	contador++;

	    for(int i = 0; i < tamanho-1; i++){
		    if( vetorVacinas[i] > vetorVacinas[i+1]){
			    int armazena_temp = vetorVacinas[i];
			    vetorVacinas[i] = vetorVacinas[i+1];
			    vetorVacinas[i+1] = armazena_temp;
			    trocas = 1;
		    }
		}
	}

	contador = 0;
	trocas = 1;

    while(trocas){
		trocas = 0;
		contador++;
		for(int i = 0; i < tamanho-1; i++){
			if( vetorPessoas[i] > vetorPessoas[i+1]){
				int armazena_temp = vetorPessoas[i];
				vetorPessoas[i] = vetorPessoas[i+1];
				vetorPessoas[i+1] = armazena_temp;
				trocas = 1;
			}
		}
	}

  int pessoaSalvas = 0;

  for(int i=0; i < tamanho; i++){
    if(vetorVacinas[i] >= vetorPessoas[i]) pessoaSalvas++;
  }

  if(pessoaSalvas == tamanho) {
      cout << "Yes" << endl;
  } else {
      cout << "No" << endl;
  }
}
