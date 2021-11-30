#include <iostream>

using namespace std;

int main()
{
    char c1 = 'a';
    char c2 = 'b';
    int soma = c1 + c2;

    cout <<"A primeira letra escolhida foi: " << c1 << endl;
    cout <<"O valor de " << c1 << " e " << (int)c1 << endl; // transformei o caractere em inteiro
    cout <<"A segunda letra escolhida foi: " << c2 << endl;
    cout <<"O valor de " << c2 << " e " << (int)c2 << endl;
    cout << "O resultado da soma e: " << soma << endl;

    return 0;
}
