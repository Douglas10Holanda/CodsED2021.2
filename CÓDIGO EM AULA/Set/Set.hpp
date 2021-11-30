#ifndef SET_HPP
#define SET_HPP


#include <iostream>

using namespace std;

class Set {
	private:
		int * element;
		int actual_size;
		int max_size;
	public:
		Set(int max_size);
		~Set();
        int size() const ;
        int capacity();		
		bool has_element(int x) const;
		void add(int x);
		void remove(int x);
		friend ostream& operator<<(ostream &output, const Set& s);
		Set operator&(Set & right); // interseccao
};

#endif

