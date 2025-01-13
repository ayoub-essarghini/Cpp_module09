#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    (void)other;
    return *this;
}

void RPN::evaluate(const std::string &expression)
{
    try
    {
        std::stack<int> stack;
        std::istringstream tokens(expression);
        std::string token;

        while (tokens >> token)
        {
            if (isNumber(token))
            {
                std::istringstream iss(token);
                int number;
                iss >> number;
                stack.push(number);
            }
            else if (isOperator(token))
            {
                if (stack.size() < 2)
                {
                    throw std::runtime_error("Error: Not enough operands");
                }
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                stack.push(performOperation(a, b, token[0]));
            }
            else
            {
                throw std::runtime_error("Error: Invalid token");
            }
        }

        if (stack.size() != 1)
        {
            throw std::runtime_error("Error: Invalid expression");
        }
        std::cout << stack.top() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

bool RPN::isNumber(const std::string &str)
{
    for (size_t i = 0; i < str.length() ; i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

bool RPN::isOperator(const std::string &str)
{
    return str.size() == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/');
}

int RPN::performOperation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            throw std::runtime_error("Error: Division by zero");
        }
        return a / b;
    default:
        throw std::runtime_error("Error: Unknown operator");
    }
}



