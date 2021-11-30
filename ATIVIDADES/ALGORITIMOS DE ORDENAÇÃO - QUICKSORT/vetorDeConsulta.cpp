#include <iostream>
#include <vector>
using namespace std;

void mostrar(vector<int> &vet) {

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

void contandoConsultas(vector<string> &busca, vector<string> &consulta, vector<int> &retorna){
    for(int i = 0; i < busca.size(); i++){
        for(int j = 0; j < consulta.size(); j++){
            if(busca[i] == consulta[j]){
                retorna[i]++;
            }
        }
    }
}

int main(){
    int num_consultas = 0;
    int num_buscas = 0;

    cin >> num_consultas;
    vector<string> vetConsulta(num_consultas);
    for(int i = 0; i < num_consultas; i++){
        cin >> vetConsulta[i];
    }

    cin >> num_buscas;
    vector<string> vetBusca(num_buscas);
    for(int i = 0; i < num_buscas; i++){
         cin >> vetBusca[i];
    }
    vector<int> retorna(num_buscas);

    contandoConsultas(vetBusca, vetConsulta, retorna);
    mostrar(retorna);
}
