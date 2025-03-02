#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <deque>


void insertionSortVec(std::vector<int> &container)
{
    for (size_t i = 1; i < container.size(); ++i)
    {
        int key = container[i];
        size_t j = i;
        while (j > 0 && container[j - 1] > key)
        {
            container[j] = container[j - 1];
            --j;
        }
        container[j] = key;
    }
}


void insertionSortDeq(std::deque<int> &container)
{
    for (size_t i = 1; i < container.size(); ++i)
    {
        int key = container[i];
        size_t j = i;
        while (j > 0 && container[j - 1] > key)
        {
            container[j] = container[j - 1];
            --j;
        }
        container[j] = key;
    }
}


void mergeVec(std::vector<int> &container, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeVec(container, left, mid);
    mergeVec(container, mid + 1, right);

    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (container[i] <= container[j])
        {
            temp.push_back(container[i]);
            ++i;
        }
        else
        {
            temp.push_back(container[j]);
            ++j;
        }
    }

    while (i <= mid)
    {
        temp.push_back(container[i]);
        ++i;
    }

    while (j <= right)
    {
        temp.push_back(container[j]);
        ++j;
    }

    for (int i = left; i <= right; ++i)
    {
        container[i] = temp[i - left];
    }
}


void mergeDeq(std::deque<int> &container, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeDeq(container, left, mid);
    mergeDeq(container, mid + 1, right);

    std::deque<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (container[i] <= container[j])
        {
            temp.push_back(container[i]);
            ++i;
        }
        else
        {
            temp.push_back(container[j]);
            ++j;
        }
    }

    while (i <= mid)
    {
        temp.push_back(container[i]);
        ++i;
    }

    while (j <= right)
    {
        temp.push_back(container[j]);
        ++j;
    }

    for (int i = left; i <= right; ++i)
    {
        container[i] = temp[i - left];
    }
}


void mergeInsertSortVec(std::vector<int> &container, int left, int right)
{
    if (right - left <= 10)
    {
        insertionSortVec(container);
    }
    else
    {
        mergeVec(container, left, right);
    }
}

void mergeInsertSortDeq(std::deque<int> &container, int left, int right)
{
    if (right - left <= 10)
    {
        insertionSortDeq(container);
    }
    else
    {
        mergeDeq(container, left, right);
    }
}


void displayContainerVec(const std::vector<int> &container)
{
    for (size_t i = 0; i < container.size(); ++i)
    {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}


void displayContainerDeq(const std::deque<int> &container)
{
    for (size_t i = 0; i < container.size(); ++i)
    {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}


void pmergeMe(int argc, char *argv[])
{
    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];

        for (size_t j = 0; j < arg.length(); ++j)
        {
            if (!isdigit(arg[j]))
            {
                throw std::invalid_argument("Error");
            }
        }

        int num;
        std::istringstream iss(arg);
        iss >> num;

        if (num < 0)
        {
            throw std::invalid_argument("Error");
        }

        vec.push_back(num);
        deq.push_back(num);
    }

    std::cout << "Before: ";
    displayContainerVec(vec);

    clock_t start = clock();
    mergeInsertSortVec(vec, 0, vec.size() - 1);
    clock_t end = clock();
    double durationVec = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "After: ";
    displayContainerVec(vec);
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Time to process a range of "<< vec.size() << " elements with std::vector: " << durationVec << " s" << std::endl;

    start = clock();
    mergeInsertSortDeq(deq, 0, deq.size() - 1);
    end = clock();
    double durationDeq = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "After: ";
    displayContainerDeq(deq);
    std::cout << "Time to process a range of "<< deq.size() << " elements with std::deque: "  << durationDeq << " s" << std::endl;
}
