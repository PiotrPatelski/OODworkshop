#pragma once
#include <iostream>

struct Dice
{
    int getRollSum()
    {
        int diceValue, diceValue2;
        std::cin >> diceValue >> diceValue2;
        return diceValue + diceValue2;
    }

};