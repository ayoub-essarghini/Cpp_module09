#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

template <typename Container>
void insertionSort(Container &container);

template <typename Container>
void merge(Container &container, int left, int right);

template <typename Container>
void mergeInsertSort(Container &container, int left, int right);

template <typename Container>
void displayContainer(const Container &container);

void pmergeMe(int argc, char *argv[]);

#endif
