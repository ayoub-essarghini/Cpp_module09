#pragma once
#include <stack>
#include <sstream>
#include <stdexcept>
#include <string>
#include <iostream>
class RPN
{
private:
 
public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    static void evaluate(const std::string &expression);
    static bool isNumber(const std::string &str);
    static bool isOperator(const std::string &str);
    static int performOperation(int a, int b, char op);
};


