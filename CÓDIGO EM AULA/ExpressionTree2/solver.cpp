#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>
#include <vector>
#include <sstream>
#include <map>
using namespace std;


class exp {
    public:
    virtual void print() = 0; // Pure virtual //inorder
    virtual int eval(std::map<string,int> vars) = 0;
};


class exp_num : public exp {
    public:
    int value;
    exp_num(int value) : value(value){}
    virtual void print() {
        cout << value;
    }

    virtual int eval(std::map<string,int> vars){
        return value;
    }

    
};

class exp_var : public exp {
    public:
    string name;
    exp_var(string name) : name(name){}
    virtual void print() {
        cout << name;
    }

    virtual int eval(std::map<string,int> vars){
        return vars[name];
    }

};


struct exp_op : public exp {
    public:
    char op;
    exp* left;
    exp* right;
    exp_op(char op, exp * left, exp * right) : op(op), left(left), right(right) {}
    virtual void print() {
        left->print();
        cout << op;
        right->print();
    }

    virtual int eval(std::map<string,int> vars){
        int l = left->eval(vars);
        int r = right->eval(vars);

        switch(op){
            case '+':
                return l + r;
                break;
            case '-':
                return l - r;
                break;
            case '*':
                return l * r;
                break;
            case '/':
                return l / r;
                break;
            default:
                return -1;
        }
    }

    
};

bool is_numeric(string str) {
   for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
         return false; //when one non numeric value is found, return false
      return true;
}

bool is_variable(string str) {
    if( !isalpha(str[0]) ) return false;
    for (int i = 0; i < str.length(); i++)
        if (isalnum(str[i]) == false)
            return false; //when one non numeric value is found, return false
   return true;
}

bool is_op(string str) {
    if( str.size() > 1) return false;

    char bin_op[] = { '+', '-', '*', '/' };
    int num_op = sizeof(bin_op)/sizeof(char);

    for(int i = 0; i < num_op; i++){
        if( str[0] == bin_op[i] )
            return true;
    }
    
    return false;
}


exp * read_postfix(vector <string> tokens){
    stack <exp *> st;

    for(string t : tokens){
        if( is_numeric(t) ){
            st.push( new exp_num(stoi(t)) );
        }
        else if( is_variable(t) ){
            st.push( new exp_var(t) );
        }else if( is_op(t) ){
            exp * r = st.top(); st.pop();
            exp * l = st.top(); st.pop();
            st.push( new exp_op(t.front(), l, r) );
        } 
    }
    return st.top();
}






int main(){

    

    string line;
    //leio uma linha
    getline(cin, line);
    
    //crio vetor de tokens
    vector <string> tokens;
    
    stringstream ss(line);
    string token;
    while( ss >> token ){
        tokens.push_back(token);
    }
    exp * e = read_postfix(tokens);
    e->print();

    cout << endl;

    map<string, int> vars;

    vars["a"] = 5;
    vars["b"] = 3;
    vars["c"] = 5;

    cout << e->eval(vars) << endl;
    
    
    
}

