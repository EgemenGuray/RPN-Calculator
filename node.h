#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>


class Node{
    
    std::string data;
    
public:
    
    Node(std::string data);
    
    virtual ~Node();
    
    virtual std::string print();
    
    virtual int eval();
    
    virtual void set(std::string target, int n);
    
    virtual void unset(std::string target);
    
    std::string getData();
    
    void setData(std::string s);
    
};



#endif /* node_h */
