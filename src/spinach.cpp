#include "spinach.hpp"
std::string Spinach::symbol(){
    if(age < 2){
        return "_";
    }
    else if(age == 2){
        return "!";
    }
    else{
        return "U";
    }
}
void Spinach::end_day(){
    if(watered){
        age += 2;
    }
    else{
        age += 1;
    }
    watered = false;
}
bool Spinach::can_harvest(){
    return age >= 3;
}
void Spinach::water(){
    watered = true;
}
int Spinach::get_age(){
    return age;
}