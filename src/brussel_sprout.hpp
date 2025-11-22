#pragma once

#include <string>

#include "plot.hpp"
class Brussel_Sprout : public Plot{
    private:
        int age = 0;
        bool watered = false;
    public:
        std::string symbol() override;
        void end_day() override;
        bool can_harvest() override;
        int get_age();
        void water() override;
};