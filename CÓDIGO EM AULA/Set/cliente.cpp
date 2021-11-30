#include <stdio.h>
#include <cstdlib>
#include <iostream>

#include "Set.hpp"

using namespace std;

int main(){

	Set s1(10);
	s1.add(3); s1.add(5); s1.add(7);
	Set s2(10);
	s2.add(7); s2.add(8); s2.add(3);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << (s1 & s2)  << endl;
		
}
