#include <stdio.h>
#include <cstdlib>
#include <iostream>

#include "vectorClass.hpp"

using namespace std;

int main(){

    vectorClass <int> v;

    v.push(5);
    v.push(7);
    v.push(9);

    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.getcapacity() << endl;
    
    v.push(10);
    v.push(11);

    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.getcapacity() << endl;
    
    
    cout << "vector : "; 
    
    Iterator<int> * itr = v.CreateIterator();

    for(itr->first(); !itr->isDone(); itr->next()){
        cout << itr->currentItem() << " , ";
    }

    cout << endl;
    

}