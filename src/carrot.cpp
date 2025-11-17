#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
  if(age == 0){
    return "_";
  }else if(age >= 1){
    return "V";
  }
}
void Carrot::end_day(){
  if(watered){
    age += 2;
  }else{
    age += 1;
  }
  watered = false;
}
void Carrot::water(){
  watered = true;
}
bool Carrot::can_harvest(){
  return age >= 1; // specify harvesting age
}
int Carrot::get_age(){
  return age;
}
