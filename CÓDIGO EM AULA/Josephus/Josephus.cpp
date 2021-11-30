#include <iostream>
#include "Josephus.hpp"


using namespace std;

Josephus::Josephus(int n, int e) : n(n), e(e) {
    
    elem = new int[n];
    for(int i = 0; i < n; i++)
        elem[i] = i+1;
}

int Josephus::survivor(){
    int pos = e-1;
    int actual_size = n;
    
    while( actual_size > 1){
        //cout << "espada com " << elem[pos];
        pos = (pos + 1) % actual_size;
        //cout << "matando " << elem[pos] << endl;
        for(int k = pos; k < actual_size-1; k++){
            elem[k] = elem[(k+1)%actual_size];
        }            
        if(pos == actual_size-1)
            pos = 0;
        actual_size--;

    }

    return elem[pos];

}