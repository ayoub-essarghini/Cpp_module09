#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }

    PmergeMe pmergeMe;

    // Parse input
    std::vector<int> numbers;
    for (int i = 1; i < argc; ++i) {
        if (!pmergeMe.isValidInput(argv[i])) {
            std::cerr << "Error: Invalid input detected." << std::endl;
            return 1;
        }
        numbers.push_back(std::atoi(argv[i]));
    }

    // Display unsorted sequence
    std::cout << "Before: ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Sort using std::vector
    std::vector<int> vectorContainer = numbers;
    std::clock_t startVector = std::clock();
    pmergeMe.mergeInsertionSortVector(vectorContainer);
    std::clock_t endVector = std::clock();



    // Display sorted sequence
    std::cout << "After: ";
    for (size_t i = 0; i < vectorContainer.size(); ++i) {
        std::cout << vectorContainer[i] << " ";
    }
    std::cout << std::endl;

    // Measure and display time
    double vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1e6; // in microseconds

    std::cout << "Time to process a range of " << vectorContainer.size() 
              << " elements with std::vector: " << vectorTime << " us" << std::endl;


    return 0;
}