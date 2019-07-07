#ifndef leafVar_hpp
#define leafVar_hpp
#include <iostream>
#include "node.h"


class leafVar: public Node{
    
    bool val_set;
    
    int val;
    
public:
    
    leafVar(std::string data);
    
    std::string print() override;
    
    int eval() override;
    
    void set(std::string target, int n) override;
    
    void unset(std::string target) override;
    
};

#endif /* leafVar_hpp */
