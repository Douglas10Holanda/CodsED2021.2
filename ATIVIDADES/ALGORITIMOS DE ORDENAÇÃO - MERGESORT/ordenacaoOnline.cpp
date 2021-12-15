#include <bits/stdc++.h>

using namespace std;

void ordenaVetor(vector<int> &vetor, int first, int last){
  if (first <= last) {
    int m = vetor[first];
    int n = first - 1;

    while (n >= 0 && vetor[n] >= m){
      vetor[n + 1] = vetor[n];
      n--;
    }

    assert(n < 0 || vetor[n] <= m);

    vetor[n + 1] = m;
    ordenaVetor(vetor, first + 1, last);
  }
}

int main(){
  int tamanho, t1, t2;

  cin >> tamanho;

  vector<int> vetor;

  for (int j = 0; j < tamanho; j++){
    cin >> t1 >> t2;

    if (t1 == 1) {
      vetor.push_back(t2);
    } else {
      ordenaVetor(vetor, 0, vetor.size() - 1);

      int k = vetor[t2];
      cout << k << endl;
    }
  }
}
