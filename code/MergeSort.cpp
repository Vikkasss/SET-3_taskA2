#include "MergeSort.h"

void merge(std::vector<int>& array, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  std::vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; ++i) L[i] = array[l + i];
  for (int i = 0; i < n2; ++i) R[i] = array[m + 1 + i];
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      array[k] = L[i];
      ++i;
    } else {
      array[k] = R[j];
      ++j;
    }
    ++k;
  }
  while (i < n1) {
    array[k] = L[i];
    ++i;
    ++k;
  }
  while (j < n2) {
    array[k] = R[j];
    ++j;
    ++k;
  }
}

void mergeSort(std::vector<int>& array, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(array, l, m);
    mergeSort(array, m + 1, r);
    merge(array, l, m, r);
  }
}