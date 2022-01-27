#pragma once

template <typename T>
class List<T>::Iterator
{
    private:
    Node *atual;
    
    public:
    Iterator() : atual(nullptr){}
    
    Iterator(Node * atual) : atual(atual){ }
    
    Iterator next(){ return Iterator( atual->next); }
    
    T & value() { return atual->val; }
    
    bool operator!=(const Iterator & other) const{
        return atual != other.atual;
    }
    
    void insert_after(T val)
    {
        Node * ptr = new Node(val, atual->next);
        atual->next = ptr;
    }

    void erase_after()
    {
        Node * ptr = atual->next;
        if(atual->next)
            atual->next = atual->next->next;
        
        delete ptr;
    }

};
        


