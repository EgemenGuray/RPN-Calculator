#include "node.h"

Node::Node(std::string data): data{data}{}

Node::~Node(){}

std::string Node::print(){return "";}

int Node::eval(){return 0;}

void Node::set(std::string target, int n){}

void Node::unset(std::string target){}

std::string Node::getData(){return data;}

void Node::setData(std::string s){data = s;}

