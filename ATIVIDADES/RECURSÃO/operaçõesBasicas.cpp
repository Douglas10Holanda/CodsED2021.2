#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void show1(vector<int> & vet, vector<int>::iterator i) {
  if (i == vet.end())
    return;

  cout << *i++ << " ";
  show1(vet, i);
}

void show2(vector<int> & vet, vector<int>::iterator i) {
  if (i == vet.begin() - 1)
    return;

  cout << *i-- << " ";
  show2(vet, i);
}

int sumVet(vector<int> & vet) {
  if (vet.size() == 0) return 0;

  vector<int> tmp = vet;
  tmp.pop_back();

  return vet.back() + sumVet(tmp);
}

int multVet(vector<int> & vet) {
  if (vet.size() == 0) return 1;

  vector<int> tmp = vet;
  tmp.pop_back();

  return vet.back() * multVet(tmp);
}

int menor(vector<int> & vet, int size) {
  if (size == 1)
    return vet[0];

  return min(vet[size - 1], menor(vet, size - 1));
}

void invert(vector<int> & vet) {
  reverse(vet.begin(), vet.end());
}

int main() {
  string line;
  getline(cin, line);
  stringstream ss(line);
  vector<int> vet;

  int value;
  while(ss >> value)
    vet.push_back(value);

  cout << "vet : [ ";
  show1(vet, vet.begin());
  cout << "]" << endl;

  cout << "rvet: [ ";
  show2(vet, vet.end() - 1);
  cout << "]" << endl;

  cout << "sum : " << sumVet(vet) << endl;
  cout << "mult: " << multVet(vet) << endl;
  cout << "min : " << menor(vet, vet.size()) << endl;

  invert(vet);
  cout << "inv : [ ";
  show1(vet, vet.begin());
  cout << "]" << endl;

  return 0;
}
