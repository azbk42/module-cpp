#include "RPN.hpp"

long add(int x, int y) 
{
    return x + y;
}

long subtract(int x, int y)
{
    return x - y;
}

long multiply(int x, int y) 
{
    return x * y;
}

long divide(int x, int y) 
{
    if (y == 0) {
        throw std::logic_error("Division by zero");
    }
    return x / y;
}

long operation(int x, int y, char c)
{
    if (c == '+'){
        return add(x, y);
    }
    else if (c == '-'){
        return subtract(x, y);
    }
    else if (c == '*'){
        return multiply(x, y);
    }
    else {
        return divide(x, y);
    }
}

void parsing_space(const std::string& str)
{
    size_t i = 0;
    size_t next;
    while (i < str.length()) {
        next = i + 1;
        if (next >= str.length() || str[next] == ' ') {
            i += 2;
        } else {
            std::string errorMessage;
            errorMessage += str[next];
            throw std::invalid_argument(errorMessage);
        }
    }
}

void parsing_logic_rpn(const std::string& str)
{
    int numbers = 0;
    size_t i = 0;

    while(i < str.length()){
        if (str[i] >= '0' && str[i] <= '9'){
            numbers += 1;
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'){
            if (numbers < 2){
                throw std::logic_error("You need 2 numbers in your stack minimum to use an operator");
            }
            numbers -= 1;
        }
        i+= 2;
    }
}

void reverse_polish(std::string str)
{
    std::stack<int> print;

    std::stack<int> polish;
    long result = 0;
    size_t i = 0;

    while (i < str.length()){

        if (str[i] >= '0' && str[i] <= '9'){
            int nb = str[i] - '0';
            polish.push(nb);
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'){
            int y = polish.top();
            polish.pop();
            int x = polish.top();
            polish.pop();
            result = operation(x, y, str[i]);
            polish.push(result);
        }
        else{
            throw std::invalid_argument("Invalide operator!");
        }
        i += 2;
    }
    if (polish.size() == 1){
        std::cout << "final result = " << polish.top() << std::endl;
    }
}
