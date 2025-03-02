#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error: insufficient arguments." << std::endl;
        return 1;
    }
    try
    {
        pmergeMe(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
 
    return 0;
}
