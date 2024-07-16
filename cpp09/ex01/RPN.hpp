#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <stack>


// ################################################################################
// #                                  OPERATOR                                    #
// ################################################################################

long add(int x, int y);

long subtract(int x, int y);

long multiply(int x, int y);

long divide(int x, int y) ;

long operation(int x, int y, char c);

// ################################################################################
// #                                  PARSING                                     #
// ################################################################################
void parsing_space(const std::string& str);

void parsing_logic_rpn(const std::string& str);

// ################################################################################
// #                                  RPN                                         #
// ################################################################################

void reverse_polish(std::string str);
