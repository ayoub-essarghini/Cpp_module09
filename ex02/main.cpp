#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error: insufficient arguments." << std::endl;
        return 1;
    }

    pmergeMe(argc, argv);
    return 0;
}
