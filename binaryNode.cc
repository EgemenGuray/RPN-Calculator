#include "binaryNode.h"

binaryNode::binaryNode(std::string data, Node *l, Node *r) : Node{data}, left{l}, right{r}{}

binaryNode::~binaryNode(){
    delete left;
    delete right;
}

std::string binaryNode::print(){
    std::string l_val;
    if(left == nullptr){
        l_val = "";
    }else{
        l_val = left->print();
    }
    
    
    std::string r_val;
    if(right == nullptr){
        r_val = "";
    }else{
        r_val = right->print();
    }
    
    return "(" + l_val + " " + getData() + " " + r_val + ")";
    
}

int binaryNode::eval(){
    
    int l_val;
    if(left == nullptr){
        l_val = 0;
    }else{
        l_val = left->eval();
    }
    
    
    int r_val;
    if(right == nullptr){
        r_val = 0;
    }else{
        r_val = right->eval();
    }
    
    if (getData()=="+"){
        
        return l_val+r_val;
        
    }else  if (getData()=="-"){
        
        return l_val-r_val;
        
    }else  if (getData()=="*"){
        
        return l_val*r_val;
        
    }else{
        
        return l_val/r_val;
    }
    
}

void binaryNode::set(std::string target, int n){
    
    if(left != nullptr){
        left->set(target, n);
    }
    
    if(right != nullptr){
        right->set(target, n);
    }
    
}

void binaryNode::unset(std::string target){
    
    if(left != nullptr){
        left->unset(target);
    }
    
    if(right != nullptr){
        right->unset(target);
    }
    
}
