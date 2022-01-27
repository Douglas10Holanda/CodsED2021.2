#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <functional>
#include <utility>

using namespace std;

template <typename T>
class Node {
    public:
    T val;
    Node *prev;
    Node *next;
    Node() : val( T()  ), next(nullptr), prev(nullptr) {}
    Node(T x) : val(x), next(nullptr), prev(nullptr) {}
    Node(T x, Node *prev, Node *next) : val(x), prev(prev), next(next) {} 
};



template<typename T>
Node<T> * readLinkedList(int n){
    Node<T> * prev = nullptr;
    Node<T> * current = nullptr;
    Node<T> * head;
    for(int i = 0; i < n; i++){
        T x;
        cin >> x;
        current = new Node<T>(x, prev, nullptr );
        if(i == 0)
            head = current;
        
        if(prev)
            prev->next = current;
        prev = current;
    }

    return head;
} 

template<typename T>
Node<T> * readLinkedList2(int n){

    if(n == 0)
    {
        return nullptr;
    }
    else
    {
        T x;
        cin >> x;
        auto ptr = readLinkedList2<T>(n-1);
        auto ptr2 = new Node<T>(x, nullptr, ptr);
        if(ptr)
            ptr->prev = ptr2;
        return ptr2;
    }    
    
} 


template <typename T>
ostream& operator<<(ostream &output, Node<T> * head)
{
    if( head==nullptr )
    {
        output << "nullptr";    
    }
    else
    {
        output << head->val << " <-> " << head->next;

        if(head->next){
            assert( head->next->prev == head );
        }
    }   
    return output;
}


template <typename T>
bool  searchNode(Node<T> * head, T x)
{
    if(head == nullptr)
        return false;
    else if(head->val == x)
        return true;
    else   
        return searchNode(head->next, x);
}

//remover a primeira ocorrencia
template <typename T>
Node<T> * remove_element(Node<T> * head, T x)
{
    if( head == nullptr)
        return nullptr;
    else
    { // lista nao vazia
        
        if(head->val == x)
        {
            auto ptr = remove_element(head->next, x);
            delete head;
            return ptr;
        }
        else
        {
            auto ptr = remove_element(head->next, x);
            head->next = ptr;
            if(ptr)
                ptr->prev = head;
            return head;
        }

    }


}



//remover a primeira ocorrencia de x
template <typename T>
Node<T> * remove_element2(Node<T> * head, T x)
{
    auto ptr = head;

    while( ptr && ptr->val != x ){
        ptr = ptr->next;
    }


    if(ptr){
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        
        if(ptr == head)
        {
            head = ptr->next;
        }
        delete ptr;
    }


    return head;

}

//Given a doubly linked list of n elements. 
//The task is to reverse the doubly linked list.
template <typename T>
Node<T> * reverseList(Node<T> * head){

    if(head->next == nullptr){
        auto tmp = head->prev;
        head->prev = head->next;
        head->next = tmp;
        return head;
    }else{
        auto tmp = head->prev;
        head->prev = head->next;
        head->next = tmp;
        return reverseList(head->prev);
    }


}



template <typename T>
Node<T> * insertSorted(Node<T> * head, T x)
{

    if(head == nullptr)
        return new Node(x);


    Node<T> * ptr = head;
    Node<T> * ant = nullptr;

    while( ptr && ptr->val <= x)
    {
        ant = ptr;
        ptr = ptr->next;
    }

   
    if(ant == nullptr)
    {
        auto ptr = new Node<T>(x, nullptr, head);
        head->prev = ptr;
        return ptr;
    }
    else
    {
        auto ptr = new Node<T>(x, ant, ant->next);
        ant->next = ptr;
        ptr->next->prev = ptr;
        return head;
    }


}


template <typename T>
Node<T> * insertSorted2(Node<T> * head, T x)
{

    if(head == nullptr)
        return new Node(x);
    else
    {
        if(head->val <= x)
        {
            auto ptr = insertSorted2(head->next, x);
            head->next = ptr;
            //head->next->prev = head;
            return head;
        }else{
            auto ptr = new Node(x, head->prev, head);
            head->prev->next = ptr;
            head->prev = ptr;
            return ptr;
        }

    }


    

}



// Given a doubly linked list, rotate the linked list counter-clockwise 
// by P nodes. Here P is a given positive integer and is smaller than 
// the count of nodes(N) in a linked list.
// rotateList(1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 -> nullptr, 2) = 
//  3 <-> 4 <-> 5 <-> 6 -> 1 <-> 2 -> nullptr

template <typename T>
Node<T> * rotateList(Node<T> * head, int p);


template <typename T>
Node<T> * selectionsort(Node<T> * head);


// Given an unsorted doubly linked list containing n nodes. 
// The problem is to remove duplicate nodes from the given list.
// INPUT: 8 4 4 6 4 8 4 10 12 12
// OUTPUT: 8 4 6 10 12
/*
8 4 4 6 4 8 4 10 12 12
8 4 4 6 4 4 10 12 12

*/

template <typename T>
Node<T> * removeDuplicates(Node<T> * head)
{
    if(head == nullptr)
        return nullptr;
    else
    {
        T x = head->val;
        auto ptr = remove_element(head->next, x);
        auto ptr2 = removeDuplicates(ptr);
        head->next = ptr2;
        if(ptr2)
            ptr2->prev = head;
        return head;
    }
}

template <typename T>
Node<T> * merge(Node<T> * first, Node<T> * second);


int main(){
    int n;
    cin >> n;

    Node<int> * head = readLinkedList2<int>(n);
    
    cout << head << endl;

    head = removeDuplicates(head);

    cout << head << endl;

    //head = remove_element(head, 3);

    //cout << head << endl;



    


}

