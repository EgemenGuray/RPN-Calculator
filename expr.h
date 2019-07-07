#ifndef EXPR_H
#define EXPR_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "node.h"
#include "binaryNode.h"
#include "uniaryNode.h"
#include "leaf.h"
#include "leafVar.h"

class Expr{
    
    std::string s;
    Node *head;
    
public:
    
    Expr(std::string s, Node *head);
    
    ~Expr();

    void update_infix(std::string infix);
    
    int eval();
    
    std::string print();
    
    void set(std::string target, int n);
    
    void unset(std::string target);
    
    void setHead(Node *root);
    
    std::string getInfix();
    
    std::string unsettedVal();
};

std::istream &operator>>(std::istream &in, Expr *&e);



#endif
