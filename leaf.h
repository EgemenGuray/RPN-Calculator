#ifndef leaf_hpp
#define leaf_hpp

#include <iostream>
#include "node.h"

class leaf: public Node{
    
public:
    
    leaf(std::string data);
    
    std::string print() override;
    
    int eval() override;
    
    void set(std::string target, int n) override;
    
    void unset(std::string target) override;
    
};


#endif
