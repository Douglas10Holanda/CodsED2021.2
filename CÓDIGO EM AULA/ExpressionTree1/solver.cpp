#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>
using namespace std;

//Uma expressão matemática é
// (1) um número
// (2) uma variável
// (3) se x é uma expr então (x) é uma expr
// (4) se x é uma expr então -x é uma expr
// (5) se x e y são expr então x @ y é uma expr


class exp {
    public:
    typedef enum { NUM, VAR, BINOP} exp_type;
    exp_type type;
    int value;
    string name;
    char op;
    exp * left;
    exp * right;
    exp(int value);
    exp(string name);
    exp(char op, exp * left, exp * right);
};


exp::exp(int value):  type( exp::NUM), value(value), left(nullptr), right(nullptr) {}
exp::exp(string name):type( exp::VAR), name(name), left(nullptr), right(nullptr) {}
exp::exp(char op, exp * left, exp * right) :op(op), type( exp::BINOP), left(left), right(right) {}


void print(exp * e){
    switch(e->type){
        case exp::NUM:
            cout << e->value;
            break;
        case exp::VAR:
            cout << e->name;
            break;
        case exp::BINOP:
            cout << e->op;
            cout << " ";
            print(e->left);
            cout << " ";
            print(e->right);
            break;
    }

}



int main(){

    exp * e =  new exp('+', 
                new exp(2),
                new exp(3)
                );
 
    print(e);

    cout << endl;


}