#pragma once

#include <iostream>
#include <functional>


using namespace std;

namespace ed{

template <typename T> 
class List{
    private:
        class Node;
        Node * head; // no sentinela
        Node * past_last; // no sentinela
        int count; // numero de itens na lista
    public:        
        class Iterator;
        List() : count(0) { 
            head = new Node();
            past_last = new Node();
            head->next = past_last;
        }

        ~List(){      
        }

        int size() { return count; }
        
        Iterator begin();
        Iterator before_begin();
        Iterator end();

        void pop_front();
        void insert_front(T val);
        T & front();

        void insert_after(Iterator it, T val); 
        void erase_after(Iterator it);
        
        void remove(T val);
        void remove2(T val);
        
        // assume que a lista está ordenada
	    void insertSorted(T val);

        
        //void selection_sort();
     	
};

#include "node_implementation.h"
#include "list_implementation.h"
#include "iterator_implementation.h"


}

