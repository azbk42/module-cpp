#pragma once
#include <string>
#include <iostream>

bool isDouble(const std::string& literal);

bool isChar(const std::string& literal);

bool isInt(const std::string& literal);

bool isFloat(const std::string& literal);

void displayResults(char c, int i, float f, double d);