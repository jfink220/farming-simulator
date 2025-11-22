#include "lettuce.hpp"
std::string Lettuce::symbol(){
    if(age < 2){
        return "_";
    }
    else{
        return "L";
    }
}
void Lettuce::end_day(){
    if(watered){
        age += 2;
    }
    else{
        age += 1;
    }
    watered = false;
}
bool Lettuce::can_harvest(){
    return age >= 2;
}
void Lettuce::water(){
    watered = true;
}
int Lettuce::get_age(){
    return age;
}