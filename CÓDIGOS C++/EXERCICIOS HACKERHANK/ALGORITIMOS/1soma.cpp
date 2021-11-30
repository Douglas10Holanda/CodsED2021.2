#include <iostream>

using namespace std;

int somaDeDoisNumeros(int a, int b) {
    return a+b;

}

int main() {
  int num1, num2;
  int soma;

  cout << "Digite o primeiro numero..." << endl;
  cin >> num1;
  cout << "Digite o segundo numero..." << endl;
  cin >> num2;
  soma = somaDeDoisNumeros(num1,num2);

  cout << "O resultado da soma entre " << num1 << " e " << num2 << " e igual a: " << soma;

  return 0;
}
