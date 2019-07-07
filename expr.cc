#include "expr.h"

Expr::Expr(std::string s, Node *head): s{s}, head{head} {} 
    
Expr::~Expr(){
    delete head;
}

std::string Expr::unsettedVal(){
    std::string s = head->print();
    std::stringstream ss;
    
    bool all_space = true;
    int i_max = s.length();
    for(int i = 0; i < i_max; i++){
        if(s.at(i) != '|' && s.at(i) != '(' && s.at(i) != ')' && s.at(i) != '-' && s.at(i) != '+' && s.at(i) != '*' && s.at(i) != '/'){
            if(s.at(i) < 48 || s.at(i) > 57){
                if(s.at(i) != ' '){
                    all_space = false;
                }
                ss << s.at(i);
            }
        }
    }
    if(all_space){
        return "";
    }else{
        return ss.str();
    }
}

void ::Expr::setHead(Node *root){
    if(head == nullptr){
       this->head = root;
    }
    
}


std::string Expr::getInfix(){
    return s;
}


void Expr::update_infix(std::string infix){
    s = infix;
}

int Expr::eval(){
    return head->eval();
}

std::string Expr::print(){
    std::string s = head->print();
    update_infix(s);
    return s;
}

void Expr::set(std::string target, int n){
    head->set(target,n);
}

void Expr::unset(std::string target){
    head->unset(target); 
}



std::istream &operator>>(std::istream &in, Expr *&e){
    
    std::vector<std::string> da_infix;
    
    std::vector<Node*> da_node;
    
    std::string s;
    
    while (in >> s) {
        std::istringstream ss(s);
        int n;
        if (ss >> n) {
            
            leaf *n1 = new leaf{s};
            da_node.emplace_back(n1);
            
            da_infix.emplace_back(s);
            
            
        }
        else if (s == "NEG" || s == "ABS") {
            
            Node *n1 = da_node.at(0);
            da_node.erase(da_node.begin());
            uniaryNode *n3 = new uniaryNode{s, n1};
            da_node.emplace_back(n3);
            
            if(s == "NEG"){
                
                std::string c = da_infix.at(0);
                da_infix.erase(da_infix.begin());
                da_infix.emplace_back("-(" + c + ")");
                
            }
            else if(s == "ABS"){
                
                std::string c = da_infix.at(0);
                da_infix.erase(da_infix.begin());
                da_infix.emplace_back("|" + c + "|");
                
            }
        }
        else if (s == "+" || s == "-" || s == "*" || s == "/") {
            
            std::string c = da_infix.at(0);
            da_infix.erase(da_infix.begin());
            std::string d = da_infix.at(0);
            da_infix.erase(da_infix.begin());
            da_infix.emplace_back("(" + d + " " + s + " " + c + ")");
            
            
            Node *n1 = da_node.at(0);
            da_node.erase(da_node.begin());
            Node *n2 = da_node.at(0);
            da_node.erase(da_node.begin());
            binaryNode *n3 = new binaryNode{s, n2, n1};
            da_node.emplace_back(n3);
            
        }
        else if (s == "done") {
            
            e->update_infix(da_infix.at(0));
            e->setHead(da_node.at(0));
            
            da_node.erase(da_node.begin());
            
            std::cout << e->print() << std::endl;
            
            
            da_infix.erase(da_infix.begin());
            break;
            
        }
        else {
            leafVar *n1 = new leafVar{s};
            da_node.emplace_back(n1);
            da_infix.emplace_back(s);
            
        }
    }
    return in;
}
