#include "quicksort.h"
#include <vector>

QuickSort::QuickSort() {}

int QuickSort::partition(std::vector<letter>& arr, int low, int high)
{
    double pivot = arr[high].freq;

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].freq > pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort::quickSort(std::vector<letter>& arr, int low, int high)
{

    if (low < high) {

        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int QuickSort::partitionDigrams(std::vector<digram>& arr, int low, int high)
{
    double pivot = arr[high].freq;

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].freq > pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort::quickSortDigrams(std::vector<digram>& arr, int low, int high)
{

    if (low < high) {

        int pi = partitionDigrams(arr, low, high);

        quickSortDigrams(arr, low, pi - 1);
        quickSortDigrams(arr, pi + 1, high);
    }
}


int QuickSort::partitionTrigrams(std::vector<trigram>& arr, int low, int high)
{
    double pivot = arr[high].freq;

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].freq > pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort::quickSortTrigrams(std::vector<trigram>& arr, int low, int high)
{

    if (low < high) {

        int pi = partitionTrigrams(arr, low, high);

        quickSortTrigrams(arr, low, pi - 1);
        quickSortTrigrams(arr, pi + 1, high);
    }
}
