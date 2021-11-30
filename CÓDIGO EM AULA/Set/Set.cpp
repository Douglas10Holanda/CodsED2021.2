#include "Set.hpp"


Set::Set(int capacity)   {
    element = new int[capacity];
    actual_size = 0;
    max_size = capacity; 
}

Set::~Set(){
    free(element);
}

int Set::size() const {
    return actual_size;
}

int Set::capacity(){
    return max_size;
}

bool Set::has_element(int x) const{
    for(int i = 0; i < size() ; i++){
        if( element[i] == x ) 
            return true;
    }
    return false;
}
    
void Set::add(int x){
    if(!has_element(x)){
        if( size() < capacity() )
        element[actual_size++] = x;
    }
}

void Set::remove(int x){
    
    int last = 0;
    for(int i = 0; i  < size() ; i++){
        if( element[i] != x){
            element[last] = element[i];
            last++;
        }
    }
    
    actual_size = last;
}


Set Set::operator&(Set & right){
	int new_size = max(capacity(), right.capacity() );
	Set ans(new_size);
	for(int i = 0; i < size(); i++){
		if( right.has_element( element[i] ) ){
			ans.add(element[i]);
		}
	}
	
	return ans;

}


ostream& operator<<(ostream &output, const Set& s)
{
  output << "{";
  
  if( s.size() > 0){
		output  << s.element[0];
  
		for(int i = 1; i < s.size(); i++){
		output << ", " << s.element[i];
		}
	}
  
  output << "}";
  
  return output;
}