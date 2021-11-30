#include <iostream>

using namespace std;

// CRIAÇÃO DE VETORES COM 6 POSIÇÕES
int A[6], B[6], C[6];

int main(void) {
    // Variavéis = JOGADORES
    int ialice = 0;
    int ibob = 0;
    int idouglas = 0;

    cout << "Bem-vindo ao jogo, vamos ver quem ira pontuar mais..." << endl;
    cout << "JOGADORES PARTICIPANTES:\nAlice\nBob\nDouglas" << endl;

    // percorrendo o vetor, e lendo valores do teclado do usuario e os armazenando nas posições do vetor
    for (int i = 0; i < 6; i++) {
        cout << "\nDigite um numero para a trinca de Alice..." << endl;
        cin >> A[i];
    }
    for (int i = 0; i < 6; i++) {
        cout << "\nDigite um numero para a trinca de Bob..." << endl;
        cin >> B[i];
    }
    for (int i = 0; i < 6; i++) {
        cout << "\nDigite um numero para a trinca de Douglas..." << endl;
        cin >> C[i];

    // Condições de pontuação
        if (A[i] < B[i] && C[i] < B[i]) {
            cout << "\nBob recebeu um ponto..." << endl;
            ibob += 1;
        } else if (A[i] > B[i] && A[i] > C[i]) {
            cout << "\nAlice recebeu um ponto..." << endl;
            ialice += 1;
        }else if (C[i] > A[i] && C[i] > B[i]){
            cout << "\nDouglas recebeu um ponto..." << endl;
            idouglas += 1;
        }else {
            cout << "\nNumeros iguais, ninguem pontuou nessa rodada!" << endl;
        }
    }

    cout << "\nAlice = " << ialice << " " << " Bob = " << ibob << " " << " Douglas = " << idouglas << "\n";
    return 0;
}
