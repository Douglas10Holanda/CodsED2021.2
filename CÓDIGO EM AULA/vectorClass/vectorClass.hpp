#ifndef VECTORCLASS_HPP
#define VECTORCLASS_HPP

template <typename T> class vectorClass;


template <typename T>
class Iterator{
    public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual T currentItem() = 0;
};

template <typename T>
class ConcreteIterator : public Iterator<T>
{
    private:

        vectorClass <T> * v;
        int currentElement;
    
    public: 

    ConcreteIterator(vectorClass <T> * vector){
        v = vector;
        currentElement = 0;
    }

    void first()
    {
        currentElement = 0;
    }

    void next()
    {
        currentElement++;
    }

    bool isDone(){
        return currentElement >= v->size();
    }

    T currentItem(){
        return v->get(currentElement);
    }

};



using namespace std;
template <typename T> class vectorClass
{
 
    // arr is the integer pointer
    // which stores the address of our vector
    T* arr;
 
    // capacity is the total storage
    // capacity of the vector
    int capacity;
 
    // current is the number of elements
    // currently present in the vector
    int current;
 
public:
    // Default constructor to initialise
    // an initial capacity of 1 element and
    // allocating storage using dynamic allocation
    vectorClass()
    {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    Iterator<T> * CreateIterator(){

        return new ConcreteIterator(this);
    }

 
    // Function to add an element at the last
    void push(T data)
    {
 
        // if the number of elements is equal to the
        // capacity, that means we don't have space to
        // accommodate more elements. We need to double the
        // capacity
        if (current == capacity) {
            T* temp = new T[2 * capacity];
 
            // copying old array elements to new array
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
 
            // deleting previous array
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
 
        // Inserting data
        arr[current] = data;
        current++;
    }
 
    // function to add element at any index
    void push(T data, int index)
    {
 
        // if index is equal to capacity then this
        // function is same as push defined above
        if (index == capacity)
            push(data);
        else
            arr[index] = data;
    }
 
    // function to extract element at any index
    T get(int index)
    {
 
        // if index is within the range
        if (index < current)
            return arr[index];
        else   
            throw std::invalid_argument( "index out of bounds" );
    }
 
    // function to delete last element
    void pop() { current--; }
 
    // function to get size of the vector
    int size() { return current; }
 
    // function to get capacity of the vector
    int getcapacity() { return capacity; }
 
    // function to print array elements
    void print()
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


#endif