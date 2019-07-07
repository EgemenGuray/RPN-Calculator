#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "expr.h"


int main(){
    string s;
    
    Expr *e = new Expr("",nullptr);
    cin >> e;
    
    // Command interpreter
    while (cin >> s) {
        if (s == "eval") {
            std::string unset = e->unsettedVal();
            if(unset == ""){
                int print_val = e->eval();
                cout << print_val << endl;
            }else{
                stringstream iss(unset);
                string unset_var;
                iss >> unset_var;
                cout << unset_var << " has no value." << endl;
            }
            
        }
        else if (s == "set") {
            
            string target;
            cin >> target;
            string val;
            cin >> val;
            std::istringstream ss(val);
            int n;
            ss >> n;
            e->set(target, n);
            
        }
        else if (s == "unset") {
            
            string target;
            cin >> target;
            e->unset(target);
            
        }
        else if (s == "print") {
            
            
            cout << e->print() << endl;
            
        }
    }
    delete e;
}
