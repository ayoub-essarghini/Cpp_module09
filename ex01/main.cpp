#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }

    RPN::evaluate(argv[1]);
    return 0;
}
