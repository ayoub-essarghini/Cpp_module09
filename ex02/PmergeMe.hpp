#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>
#include <iterator>

class PmergeMe
{

public:
    PmergeMe(/* args */);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    bool isValidInput(const std::string &str);
    void mergeInsertionSortDeque(std::deque<int> &arr);
    void mergeInsertionSortVector(std::vector<int> &arr);
};
