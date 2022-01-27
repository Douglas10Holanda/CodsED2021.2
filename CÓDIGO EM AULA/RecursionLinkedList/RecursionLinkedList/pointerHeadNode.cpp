#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <functional>
#include <utility>

using namespace std;

template <typename T>
class ListNode {
    public:
    T val;
    ListNode *next;
    ListNode() : val( T()  ), next(nullptr) {}
    ListNode(T x) : val(x), next(nullptr) {}
    ListNode(T x, ListNode *next) : val(x), next(next) {} 
};

 

template <typename T>
ListNode<T>* readList(){
    int n;
    cin >> n;
    ListNode<T> * head;
    for(int i = 0; i < n; i++){
        ListNode<int> * ptr;
        T x;
        cin >> x;
        if( i == 0){
            head = new ListNode<int>(x);
            ptr = head;
        }else{
            ptr->next = new ListNode<int>(x, nullptr);
            ptr = ptr->next;
        }
    }

    return head;

}


template <typename T>
void print_list(ListNode <T> * head){

    for(auto ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cout << ptr->val << endl;
    }

}

template <typename T> 
int sizeList(ListNode <T> * head){

    if(head == nullptr)
        return 0;
    else
        return 1 + sizeList(head->next);


}




template <typename T> 
T last(ListNode<T> * head)
{

    if(head->next == nullptr)
        return head->val;
    else
        return last(head->next);

}

template <typename T> 
T kthElement(ListNode<T> * head, int k)
{
    if( k == 0 )
    {
        return head->val;
    }
    else
    {
        return kthElement(head->next, k-1);
    }


}

/*
[1,1,1,1,2,2,2,3,3,3,4,5]
[(1,4)->(2,3)->(3,2)->(4,1)->(5,1)]
*/
template <typename T> 
ListNode < pair<T, int> > * runLengthEnconding(ListNode <T> * head)
{

    if(head == nullptr)
    {
        return nullptr;
    }
    else
    {
        T x = head->val;

        auto ptr = head;

        int cnt = 0;


        while( ptr != nullptr && ptr->val == x ){
            cnt++;
            ptr = ptr->next;
        }


        return new ListNode< pair<T, int> >( make_pair(x, cnt) , runLengthEnconding(ptr) ); 


    }
}



template <typename T> 
ListNode <T> * reverseList(ListNode <T> * head);

//#include <functional>
template <typename A, typename B> 
ListNode <B> * mapList(ListNode<A> * head, function <B (A)> f)
{
    if(head==nullptr)
        return nullptr;
    else
        return new ListNode( f(head->val) , mapList(head->next, f) );


}

//#include <functional>
template <typename T>
ListNode <T> * filterList(ListNode<T> * head, function <bool (T)> f);

template <typename T>
T sumList(ListNode<T> * head)
{
    if(head == nullptr)
        return 0;
    else
        return head->val + sumList(head->next);
}




template <typename T>
ListNode <T> * take(ListNode<T> * head, int n)
{
    if(n==0)
        return nullptr;
    else if(head == nullptr)
        return nullptr;
    else
        return new ListNode( head->val, take(head->next, n-1)    );

}


template <typename T> using plist = ListNode<T>*;

//#include <utility>
template <typename T>
pair< plist<T> , plist<T> > splitAt(ListNode<T> * head, int n);


template <typename T>
T getNthFromLast(ListNode<T> *head, int n)
{
    ListNode<T> * slow, * fast;

    slow = head;
    fast = head;
    for(int i = 1; i <= n; i++)
        fast = fast->next;
    

    while( fast != nullptr ){
        slow = slow->next;
        fast = fast->next;
    }

    return slow->val;

}





template <typename T>
bool isOrdered(ListNode<T> * head)
{

    //tamanho 0
    if(head == nullptr)
        return true;

    //tamanho 1
    if(head->next == nullptr)
        return true;


    return  head->val < head->next->val &&
            isOrdered(head->next);


}

template <typename K, typename V>
ostream& operator<<(ostream &output, const pair<K, V>& right)
{
    output << "(" << right.first << "," << right.second << ")";
    return output;
}

int dobro(int x){
    return 2*x;
}


template <typename T>
ListNode<T> * insert_front(ListNode<T> * head, T val)
{
    return new ListNode(val, head);
}


template <typename T>
ListNode<T> * remove_front(ListNode<T> * head)
{
    ListNode<T> * ptr = head->next;
    delete head;
    return ptr;


}

int main(){
    
    ListNode<int> * head = nullptr;

    head = insert_front(head, 5);
    head = insert_front(head, 4);
    head = insert_front(head, 3);
    head = insert_front(head, 2);

    head = remove_front(head);

    print_list(head);
    
     

    //ListNode<int> * head2 = mapList<int,int>(head, dobro ); 
    
    //print_list(head2);


    //int n; cin >> n;

    //auto head2 = take(head, n);

    

    //auto head2 = runLengthEnconding(head);

    //cout << sumList(head) << endl;

    



    //cout << getNthFromLast(head, 1) << endl;

    //cout << isOrdered(head) << endl;

    
   
    //ListNode<int> * head2 = filterList<int>(head1, [](int x)-> bool {return x%2==0; } );    
   
    
    //print_list(head2);


}

