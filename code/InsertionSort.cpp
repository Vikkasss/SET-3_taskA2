#include "InsertionSort.h"

void insertionSort(std::vector<int>& array, int l, int r) {
  for (int i = l + 1; i <= r; ++i) {
    int key = array[i];
    int j = i - 1;
    while (j >= l && array[j] > key) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}