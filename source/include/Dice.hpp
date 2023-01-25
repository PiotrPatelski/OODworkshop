#pragma once
#include <iostream>

struct Dice
{
    int getRollSum()
    {
        int diceValue, diceValue2;
        std::cout<<"Enter 1st dice value: "<<std::endl;
        std::cin >> diceValue;
        std::cout<<"Enter 2nd dice value: "<<std::endl;
        std::cin >> diceValue2;
        return diceValue + diceValue2;
    }

};