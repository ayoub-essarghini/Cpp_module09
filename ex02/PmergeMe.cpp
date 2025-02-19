#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

template <typename Container>
void insertionSort(Container &container) {
    for (size_t i = 1; i < container.size(); ++i) {
        int key = container[i];
        size_t j = i;
        while (j > 0 && container[j - 1] > key) {
            container[j] = container[j - 1];
            --j;
        }
        container[j] = key;
    }
}

template <typename Container>
void merge(Container &container, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge(container, left, mid);
    merge(container, mid + 1, right);

    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (container[i] <= container[j]) {
            temp.push_back(container[i]);
            ++i;
        } else {
            temp.push_back(container[j]);
            ++j;
        }
    }

    while (i <= mid) {
        temp.push_back(container[i]);
        ++i;
    }

    while (j <= right) {
        temp.push_back(container[j]);
        ++j;
    }

    for (int i = left; i <= right; ++i) {
        container[i] = temp[i - left];
    }
}

template <typename Container>
void mergeInsertSort(Container &container, int left, int right) {
    if (right - left <= 10) {
        insertionSort(container);
    } else {
        merge(container, left, right);
    }
}

template <typename Container>
void displayContainer(const Container &container) {
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

void pmergeMe(int argc, char *argv[]) {
    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) {
        try {
            int num = std::atoi(argv[i]);
            vec.push_back(num);
            deq.push_back(num);
        } catch (const std::invalid_argument &e) {
            std::cerr << "Error: invalid argument '" << argv[i] << "'" << std::endl;
            return;
        }
    }

    std::cout << "Before: ";
    displayContainer(vec);

    // Timing with clock() for std::vector
    clock_t start = clock();
    mergeInsertSort(vec, 0, vec.size() - 1);
    clock_t end = clock();
    double durationVec = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "After: ";
    displayContainer(vec);
    std::cout << std::fixed << std::setprecision(6); // Set precision to 6 decimal places
    std::cout << "Time to process with std::vector: " << durationVec << " s" << std::endl;

    // Timing with clock() for std::deque
    start = clock();
    mergeInsertSort(deq, 0, deq.size() - 1);
    end = clock();
    double durationDeq = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "After: ";
    displayContainer(deq);
    std::cout << "Time to process with std::deque: " << durationDeq << " s" << std::endl;
}
