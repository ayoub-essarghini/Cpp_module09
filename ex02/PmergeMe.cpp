#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}
// Function to validate input
struct IsNotDigit
{
    bool operator()(char c) const
    {
        return !std::isdigit(c);
    }
};

bool PmergeMe::isValidInput(const std::string &str)
{
    return !str.empty() && std::find_if(str.begin(), str.end(), IsNotDigit()) == str.end();
}

// Merge-Insertion Sort for std::vector
void PmergeMe::mergeInsertionSortVector(std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return;

    // Pair and sort within pairs
    std::vector<int> mainChain, pendings;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (i + 1 < arr.size() && arr[i] > arr[i + 1])
            std::swap(arr[i], arr[i + 1]);
        mainChain.push_back(arr[i]);
        if (i + 1 < arr.size())
            pendings.push_back(arr[i + 1]);
    }

    // Sort main chain
    std::sort(mainChain.begin(), mainChain.end());

    // Insert pending elements
    for (size_t i = 0; i < pendings.size(); ++i)
    {
        int num = pendings[i];
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), num);
        mainChain.insert(pos, num);
    }

    arr = mainChain;
}

// Merge-Insertion Sort for std::deque
void PmergeMe::mergeInsertionSortDeque(std::deque<int> &arr)
{
    if (arr.size() <= 1)
        return;

    // Pair and sort within pairs
    std::deque<int> mainChain, pendings;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (i + 1 < arr.size() && arr[i] > arr[i + 1])
            std::swap(arr[i], arr[i + 1]);
        mainChain.push_back(arr[i]);
        if (i + 1 < arr.size())
            pendings.push_back(arr[i + 1]);
    }

    // Sort main chain
    std::sort(mainChain.begin(), mainChain.end());

    // Insert pending elements
    for (size_t i = 0; i < pendings.size(); ++i)
    {
        int num = pendings[i];
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), num);
        mainChain.insert(pos, num);
    }

    arr = mainChain;
}
