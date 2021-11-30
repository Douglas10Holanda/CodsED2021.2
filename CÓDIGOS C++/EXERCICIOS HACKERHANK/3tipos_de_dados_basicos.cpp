#include <iostream>

using namespace std;

int main()
{
    int a;  // inteiro de 32 bits
    long b; // inteiro de 64 bits
    char c; // caractere
    float d; // valor real de 32 bits
    double e; // valor real de 64 bits

    scanf("%d %ld %c %f %lf", &a,&b,&c,&d,&e); // leitura de valores
    printf("\n\n%d \n%ld \n%c \n%f \n%lf", a,b,c,d,e); // escrever valor na tela

// \n é pra dar espaço de uma linha

    return 0;
}
