#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>


#include "ListaSequencial.hpp"

using namespace std;

int main(){

   
    ListaSequencial <int> v;

    

    v.push(2);
    v.push(3);
    v.push(4);
    v.push(6);
    v.push(2);
    v.push(3);
    
    
    cout << v.front() << endl;
    cout << v.back() << endl;
        
    v.front() += 3;

    cout << v << endl;





}