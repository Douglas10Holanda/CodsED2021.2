#include <iostream>

using namespace std;

/*
CALCULADORA
OPERA��ES PERMITADAS:
+  ----> Adi��o
-  ----> Subtra��o
*  ----> Multiplica��o
/  ----> Divis�o
*/

int main()
{
    int n1,n2,resultado;
    float div;
    char op; // opera��o

    cout << "Digite o primeiro numero..." << endl;
    cin >> n1;
    cout << "Digite o segundo numero..." << endl;
    cin >> n2;
    cout << "Digite a operacao..." << endl;
    cin >> op;

    switch(op){
    case '+':
        resultado = n1 + n2;
        cout << "O resultado da soma e: " << resultado << endl;
        break;
    case '-':
        resultado = n1 - n2;
        cout << "O resultado da subtracao e: " << resultado << endl;
        break;
    case '*':
        resultado = n1 * n2;
        cout << "O resultado da multiplica�ao e: " << resultado << endl;
        break;
    case '/':
        if(n2 != 0){
        div = (float)n1 / n2;
        cout << "O resultado da divisao e: " << div << endl;
        }else{
            cout << "Divisao por 0...";
        }
        break;
    default:
        cout << "ERRO -- Digite alguma operacao valida...";
        break;
    }

    return 0;
}
