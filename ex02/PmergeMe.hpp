#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

void insertionSortVec(std::vector<int> &container);
void insertionSortDeq(std::deque<int> &container);
void mergeVec(std::vector<int> &container, int left, int right);
void mergeDeq(std::deque<int> &container, int left, int right);
void mergeInsertSortVec(std::vector<int> &container, int left, int right);
void mergeInsertSortDeq(std::deque<int> &container, int left, int right);
void displayContainerVec(const std::vector<int> &container);
void displayContainerDeq(const std::deque<int> &container);

void pmergeMe(int argc, char *argv[]);

#endif
