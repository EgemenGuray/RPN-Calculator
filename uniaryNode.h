#ifndef uniaryNode_h
#define uniaryNode_h

#include <iostream>
#include "node.h"

class uniaryNode: public Node{
    
    Node *next;
    
public:
    
    uniaryNode(std::string data, Node *next);
    
    ~uniaryNode();
    
    std::string print() override;
    
    int eval() override;
    
    void set(std::string target, int n) override;
    
    void unset(std::string target) override;
    
};

#endif
