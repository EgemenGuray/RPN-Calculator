#include "leaf.h"


leaf::leaf(std::string data): Node{data}{}

std::string leaf::print(){
    return getData();
}

int leaf::eval(){
    return stoi(getData());
}

void leaf::set(std::string target, int n){
    return;
}

void leaf::unset(std::string target){ 
    return;
}
