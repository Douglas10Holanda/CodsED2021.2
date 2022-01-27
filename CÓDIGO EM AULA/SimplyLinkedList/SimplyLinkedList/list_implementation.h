#pragma once


template <typename T> 
T & List<T>::front()
{
    return head->next->val;
}


template <typename T> 
typename List<T>::Iterator List<T>::begin()
{
    return Iterator(head->next);
}

template <typename T> 
typename List<T>::Iterator List<T>::before_begin()
{
    return Iterator(head);
}

template <typename T> 
typename List<T>::Iterator List<T>::end()
{
    return Iterator(past_last);
}

template <typename T> 
void List<T>::pop_front(){
    if(count > 0){

        Node * ptr = head->next;
        head->next = head->next->next;
        count--;
        delete ptr;
    }
}

template <typename T> 
void List<T>::insert_front(T val)
{
    Node * ptr = new Node(val, head->next);
    head->next = ptr;
    count++;   
}


template <typename T> 
void List<T>::insert_after(Iterator it, T val)
{
    it.insert_after(val);
}


template <typename T> 
void List<T>::erase_after(Iterator it)
{
    it.erase_after();
}

template <typename T> 
void List<T>::remove(T x)
{
    Node * ptr = head;
    while(ptr->next != past_last ){
       if( ptr->next->val == x ){
           auto tmp = ptr->next;
           ptr->next = ptr->next->next;
           delete tmp;
       }else{
           ptr = ptr->next;
       }     
    }
}

template <typename T> 
void List<T>::remove2(T x)
{
    for(auto it = before_begin(); it != end(); )
    {
        if( it.next().value() == x)
        {
            it.erase_after();
        }
        else
        {
            it = it.next();
        }
    }
}


template <typename T> 
void List<T>::insertSorted(T x)
{
    Node * ptr = head;
    while(ptr->next != past_last ){
       if( ptr->next->val <= x ){
           ptr = ptr->next;
       }
       else
       {
           auto tmp = new Node(x, ptr->next);
           ptr->next = tmp;
           return ;
       }     
    }
}



// template <typename T> 
// void list<T>::merge( List<T> l)
// {
//     auto it = before_begin();
//     auto it2 = l.begin();

//     while( it.next() != end() && it2 != l.end() ){
        
//         if( it.next().value() <= it2.value() ){
//             it = it.next();
//         }
//         else
//         {
//             insert_after(it, it2.value());
//             it2 = it2.next();
//             it  = it.next();
//         }
//     }

//     while( it2 != l.end() ){
//         insert_after(it, it2.value());
//         it2 = it2.next();
//         it  = it.next();
//     }

// }