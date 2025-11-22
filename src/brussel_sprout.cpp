#include "brussel_sprout.hpp"
std::string Brussel_Sprout::symbol(){
    if(age < 5){
        return "_";
    }
    else if(age >= 5 && age < 10){
        return "!";
    }
    else{
        return "N";
    }
}
void Brussel_Sprout::end_day(){
    if(watered){
        age += 2;
    }
    else{
        age += 1;
    }
    watered = false;
}
bool Brussel_Sprout::can_harvest(){
    return age >= 10;
}
void Brussel_Sprout::water(){
    watered = true;
}
int Brussel_Sprout::get_age(){
    return age;
}