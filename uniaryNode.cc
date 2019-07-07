#include "uniaryNode.h"


uniaryNode::uniaryNode(std::string data, Node *next): Node{data}, next{next}{}

uniaryNode::~uniaryNode(){
    delete next;
}

std::string uniaryNode::print(){

    std::string val;
    if(next == nullptr){
        val = "";
    }else{
        val = next->print();
    }
    
    if (getData()=="ABS"){
        
        return "|" + val + "|";
        
    }else {
        
        
        return "-(" + val + ")";
        
    }
    
}

int uniaryNode::eval(){
    
    double val;
    if(next == nullptr){
        val = 0;
    }else{
        val = next->eval();
    }
    
    if (getData()=="ABS"){
        if(val > 0){
            return val;
        }else{
            return -val;
        }
    }else {
        
        
        return -val;
        
    }
    
}

void uniaryNode::set(std::string target, int n){
    if(next != nullptr){
        next->set(target, n);
    }
}

void uniaryNode::unset(std::string target){
    if(next != nullptr){
        next->unset(target);
    }
}
