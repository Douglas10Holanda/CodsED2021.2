#pragma once


template <typename T>
class List<T>::Node{
    public:
    T val;
    Node * next;
    Node() : next(nullptr){}
    Node(T val, Node * ptr = nullptr) : val(val), next(ptr) {}
    
};


