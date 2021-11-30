#ifndef LISTASEQUENCIAL_HPP
#define LISTASEQUENCIAL_HPP

#include <stdexcept>


using namespace std;

template <typename T> 
class ListaSequencial
{

private: 
    T* arr;
    int capacity;
    int current;
 
public:
    
    class Iterator{

        private:
            const ListaSequencial <T> * pLista;
            int m_index = -1;

        public:
            Iterator(){
                pLista = nullptr;
                m_index = -1;
            }      

            Iterator(const ListaSequencial<T> * lista, int nIndex){
                pLista = lista;
                m_index = nIndex;
            }

            Iterator & operator++(){
                m_index++;
                return (*this);
            }

            Iterator operator++(int){ //posfix version
                Iterator it(pLista, m_index);
                m_index++;
                return it;    
            }

            T & operator*() const{
                return pLista->operator[](m_index);
            } 

            bool operator!=(const Iterator & other) const{
                return m_index != other.m_index;
            }


    };


    ListaSequencial()
    {
        arr = new T[1];
        current = 0;
        capacity = 1;
    
    }

 
    // // Function to add an element at the last
    void push(T data)
    {
 
        if (current == capacity) {
            T * temp = new T[2*capacity];

            for(int i = 0; i < current; i++)
                temp[i] = arr[i];

            
            delete [] arr;

            arr = temp;

            capacity *= 2;    
        }
 
        arr[current++] = data;
        
    }
 
    
 
    T & operator[](int index) const{
        if (index >= current){
            throw std::runtime_error("index out of range");
        }
        return arr[index];
    }
 
    void pop() { current--; }
 
    int size() const { return current; }
 
    int getcapacity() { return capacity; }
 
    Iterator begin() const
    {
        return ListaSequencial<T>::Iterator(this, 0);
    }

    Iterator end() const 
    {
        return ListaSequencial<T>::Iterator(this, current);
    }

    T & front()
    {
        if(current > 0)
            return arr[0];
        else 
          throw std::runtime_error("index out of range");  
    }

    T & back()
    {
        if( current > 0)
            return arr[current-1];
        else
            throw std::runtime_error("index out of range");
    }

    void remove(T val)
    {
        int k = 0;
        int n = v.size();
        for(int i = 0; i < v.size(); i++){
            if( arr[i] != val ){
                arr[k++] = arr[i];
            }
        }
        current = k;
    }


    // T * data()
    // {

    // }


};

template <typename T>
ostream& operator<<(ostream &output, const ListaSequencial<T>& v)
{
    int n = v.size();
    output << "[";
    if( n > 0){
        output << v[0];
        for(int i = 1; i < n; i++)
            output << " " << v[i];
    }
    output << "]";
    return output;
}

#endif