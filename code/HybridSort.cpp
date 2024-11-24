#include "HybridSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"

void hybridMergeSort(std::vector<int>& array, int l, int r, int threshold) {
  if (r - l <= threshold) {
    insertionSort(array, l, r);
  } else {
    int m = l + (r - l) / 2;
    hybridMergeSort(array, l, m, threshold);
    hybridMergeSort(array, m + 1, r, threshold);
    merge(array, l, m, r);
  }
}