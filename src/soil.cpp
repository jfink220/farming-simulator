#include "soil.hpp"

std::string Soil::symbol() {
  return ".";
}
void Soil::end_day(){
  // no-op
}
bool Soil::can_harvest(){
  return false;
}

