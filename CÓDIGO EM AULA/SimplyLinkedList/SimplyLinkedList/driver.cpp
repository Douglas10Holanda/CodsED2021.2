#include <iostream>
#include <cassert>
#include "list.h"

using namespace std;
using ed::List;


int main(){

    List<int> l1;

    l1.insert_front(10);
    l1.insert_front(8);
    l1.insert_front(5);
    l1.insert_front(2);
    l1.insert_front(1);
    
    cout << l1.size() << endl;

    l1.insertSorted(7);

    for(auto it = l1.begin(); it != l1.end(); it = it.next() ){
        cout << it.value() << endl;
    }
    
   

 

}

