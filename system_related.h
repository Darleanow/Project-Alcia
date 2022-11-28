#pragma once
#include <iostream>

void cls();

int generate_random_number(int min, int max);

bool roll_boolDice(int succes_percentage);

std::string color(std::string attr);

bool is_digits(const std::string& str);