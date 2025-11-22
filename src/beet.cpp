#include "beet.hpp"
std::string Beet::symbol(){
    if(age < 2){
        return "_";
    }
    else if(age >= 2 && age < 5){
        return "!";
    }
    else{
        return "B";
    }
}
void Beet::end_day(){
    if(watered){
        age += 2;
    }
    else{
        age += 1;
    }
    watered = false;
}
bool Beet::can_harvest(){
    return age >= 5;
}
void Beet::water(){
    watered = true;
}
int Beet::get_age(){
    return age;
}