#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;


class logical {
  public:
    virtual void print() = 0;
    virtual logical* remove_implies() = 0;
};

class log_const : public logical {
  public:
    log_const(bool value) : value(value) {}
    void print() { 
        cout << value ? "true" : "false";
    }

    virtual logical* remove_implies(){
      return this;
    }

  private:
    bool value;
};

class log_prop : public logical {
  public:
    log_prop(string name) : name(name) {}
    
    void print() {
        cout << name;
    }
    
    virtual logical* remove_implies(){
      return this;
    }
    


  private:
    string name;
};

class log_neg : public logical {
  public:
    log_neg(logical * inner) : inner(inner) {}
    void print() {
        cout << "~";
        inner->print();
    }
    virtual logical* remove_implies(){
      return new log_neg( inner->remove_implies() );
    }
    
  private:
    logical* inner;
};


class log_op : public logical {
  public:
    log_op(string op, logical * l, logical * r) : op(op), left(l), right(r) {}
    void print() {
        cout << "("; left->print(); cout << op; right->print(); cout << ")";
    }

    virtual logical* remove_implies(){
        logical * l = this->left->remove_implies();
        logical * r = this->right->remove_implies();

        if( this->op == "->")
        {  
          return new log_op("\\/", new log_neg(l), r);
        }
        else
        {
          return new log_op(this->op, l, r);
        }
    }

  private:
    string op;
    logical * left;
    logical * right;

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

    vector <string> bin_op({ "\\/", "/\\", "->", "<->" });

    
    for(int i = 0; i < bin_op.size(); i++){
        if( str == bin_op[i] )
            return true;
    }
    
    return false;
}

bool is_bool(string t){
    if( t == "true" || t == "false" ) return true;
    else return false;
}


logical * read_postfix(vector <string> tokens){
    stack <logical *> st;

    for(string t : tokens){
        
        if( is_bool(t) ){
            
            st.push( new log_const( t == "true" ) );
        }
        else if( is_variable(t) ){
            
            st.push( new log_prop(t) );
        }else if( t == "~"){
            logical * inner = st.top(); st.pop();
            st.push( new log_neg(inner) );
        }
        else if( is_op(t) ){
            logical * r = st.top(); st.pop();
            logical * l = st.top(); st.pop();

           
            st.push( new log_op(t , l, r) );
        } 
    }
    return st.top();
}


// logical * remove_implies(logical * exp){

//   log_neg * exp_neg = dynamic_cast<log_neg*>(exp);

//   if( exp_neg != nullptr){
    
//     return new log_neg( remove_implies( exp_neg->inner) );
//   }
//   else{
//     log_op * exp_op = dynamic_cast<log_op*>(exp);

//     if( exp_op == nullptr)
//     {
//       return exp;
//     }
//     else
//     {
//       logical * l = remove_implies( exp_op->left );
//       logical * r = remove_implies( exp_op->right);
        
//       if( exp_op->op == "->")
//       {  
//         return new log_op("\\/", new log_neg(l), r);
//       }
//       else
//         return new log_op(exp_op->op, l, r);
//     }
//   }

// }

// logical * remove_equivalence(logical * exp){

//   log_neg * exp_neg = dynamic_cast<log_neg*>(exp);

//   if( exp_neg != nullptr){
    
//     return new log_neg( remove_equivalence( exp_neg->inner) );
//   }
//   else{
//     log_op * exp_op = dynamic_cast<log_op*>(exp);

//     if( exp_op == nullptr)
//     {
//       return exp;
//     }
//     else
//     {
//       logical * l = remove_equivalence( exp_op->left );
//       logical * r = remove_equivalence( exp_op->right);
        
//       if( exp_op->op == "<->")
//       {  
//         return new log_op("/\\", new log_op("->", l, r), new log_op("->", r, l));
//       }
//       else
//         return new log_op(exp_op->op, l, r);
//     }
//   }

// }


int main(){

    string line;

    getline(cin, line);

    vector <string> tokens;

    stringstream ss(line);

    string token;

    while( ss >> token ){

        tokens.push_back(token);
    }

    logical * e = read_postfix(tokens);

    e->print();

    cout << endl;

    logical * f = e->remove_implies();

    f->print();

    cout << endl;

    

}

