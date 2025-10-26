#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
  if(age == 0){
    return "v";
  }else if(age == 1){
    return "V";
  }else{
    return "W";
  }
}
void Carrot::end_day(){
  age += 1;
}
bool Carrot::can_harvest(){
  return age >= 1; // specify harvesting age
}
