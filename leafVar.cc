#include "leafVar.h"

leafVar::leafVar(std::string data): Node{data}, val_set(false), val(0){}

std::string leafVar::print(){
    if(val_set){
        return std::to_string(val);
    }else{
        return getData();
        
    }
}

int leafVar::eval(){
    if(val_set){
        return val;
    }else{
        return 0;
    }
}

void leafVar::set(std::string target, int n){
    if(target == getData()){
        val_set = true;
        val = n;
    }
}

void leafVar::unset(std::string target){
    if(target == getData()){
        val_set = false;
    }
}
