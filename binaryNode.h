#ifndef binaryNode_hpp
#define binaryNode_hpp

#include <iostream>
#include "node.h"


class binaryNode: public Node{
    
    Node *left;
    
    Node *right;
    
public:
    
    binaryNode(std::string data, Node *l, Node *r);
    
    ~binaryNode();
    
    std::string print() override;
    
    int eval() override;
    
    void set(std::string target, int n) override;
    
    void unset(std::string target) override;
    
};


#endif /* binaryNode_hpp */
