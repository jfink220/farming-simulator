#pragma once

#include <string>

class Plot {
  public:
    virtual std::string symbol() = 0;
    virtual void end_day() = 0;
    virtual bool can_harvest() = 0;
};
