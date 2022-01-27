#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>
#include <vector>
#include <sstream>
#include <fstream> 

using namespace std;


template <typename T> 
class NodeTree{
    public:
    T key;
    NodeTree<T> * left;
    NodeTree<T> * right;
    NodeTree(T key) : key(key), left(nullptr), right(nullptr) {};
    NodeTree(T key, NodeTree * l, NodeTree * r) : key(key), left(l), right(r) {};    
};


template <typename T> 
int btsize(NodeTree<T> * ptr){
    
}

template <typename T> 
int btheight(NodeTree<T> * ptr){
    
}

template <typename T> 
vector<T> btleaves(NodeTree<T> * ptr){
    

}

template <typename T> 
vector<T> btlevel(NodeTree<T> * ptr, int k){

    

}

/*
Inicialmente, keys.size() nós da árvore binária.
Em seguida, o parent[i] indica o índice da nó pai do nó i
*/



template <typename T> 
NodeTree<T> * createTree( vector<T> keys, vector<int> parent){

    NodeTree<T>* tree[keys.size()];
    NodeTree<T>* root;

    for(int i = 0; i < keys.size(); i++){
        tree[i] = new NodeTree<T>(keys[i]);
    }

    for(int i = 0; i < keys.size(); i++){

        if( parent[i] == -1)
            root = tree[i];
        else
        {
            NodeTree<T>* ptr = tree[ parent[i] ];

            if( ptr->left ){
                ptr->right = tree[i];
            }else{
                ptr->left = tree[i];
            }

        }
    }

    return root;

} 

template <typename T>
void dotfileaux(ofstream & ofs, NodeTree<T> * ptr){

    static int nullcount = 0;

    if(ptr != nullptr){
        
        if(ptr->left){
            ofs << ptr->key << "->" << ptr->left->key  << ";" << endl;
            dotfileaux(ofs, ptr->left);
        }else{
            ofs << "null" << nullcount << " [shape=point];" << endl;
            ofs << ptr->key << "->" << "null" << nullcount << ";" << endl; 
            nullcount++;
        }

        if(ptr->right != nullptr){
            ofs << ptr->key << "->" << ptr->right->key  << ";" << endl;
            dotfileaux(ofs, ptr->right);
        }else{
            ofs << "null" << nullcount << " [shape=point];" << endl;
            ofs << ptr->key << "->" << "null" << nullcount << ";" << endl; 
            nullcount++;
        }
         

    }

} 

template <typename T>
void dotfile(NodeTree<T> * ptr)
{
    ofstream ofs ("bt.dot", ofstream::out);

    ofs << "digraph G {" << endl;

    dotfileaux(ofs, ptr);

    ofs << "}" << endl;

    ofs.close();

}





template <typename T>
bool is_full_binary(NodeTree<T> * ptr)
{
    int h = btheight(ptr);
    int n = btsize(ptr);
    return n == (1 << h) - 1;
}


template <typename T>
bool is_complete_binary(NodeTree<T> * ptr, int index, int numnodes)
{
    if(ptr == nullptr)
        return true;
    if( index > numnodes-1)
        return false;
    else
        return  is_complete_binary(ptr->left, 2*index+1, numnodes) &&
                is_complete_binary(ptr->right, 2*index+2, numnodes);
}


template <typename T> 
NodeTree<T> * createCompleteTree( vector<T> keys, int index = 0){


}


template <typename T>
ostream& operator<<(ostream &output, const vector<T>& v)
{
    output << "[";
    for(auto x : v)
        cout << x << " ";
    output << "]";
    return output;
}


template <typename T>
ostream& operator<<(ostream &output, const NodeTree<T> * ptr)
{
    
    if( ptr != nullptr)
    {
        output << "[";
        cout << ptr->key;
        cout << ptr->left;
        cout << ptr->right;
        output << "]";
    }
    
    return output;
}




int main(){

    vector<int> keys( {1,2,3,4,5,6,7});
    vector<int> parent({-1,0,1,1,2,2,4});
    auto root = createTree(keys, parent);

    dotfile(root);

    //cout << root << endl;
    //cout << btsize(root) << endl;
    //cout << btheight(root) << endl;
    //cout << btleaves(root) << endl;    

    //cout << is_full_binary(root) << endl;
    
    //cout << is_complete_binary(root, 0, btsize(root) ) << endl;
    
    
    dotfile(root);

}

