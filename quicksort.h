#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "alphabet.h"

class QuickSort
{
private:
    static int partition(std::vector<letter>& array, int low, int high);
    static int partitionDigrams(std::vector<digram>& array, int low, int high);
    static int partitionTrigrams(std::vector<trigram>& array, int low, int high);
public:
    QuickSort();
    static void quickSort(std::vector<letter>& arr, int low, int high);
    static void quickSortDigrams(std::vector<digram>& arr, int low, int high);
    static void quickSortTrigrams(std::vector<trigram>& arr, int low, int high);
};

#endif // QUICKSORT_H
