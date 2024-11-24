#include <iostream>
#include <vector>

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

int main() {
  int threshold = 15;
  int n;
  std::cin >> n;
  std::vector<int> array(n);
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }
  if (array.empty()) {
    return 0;
  } else {
    hybridMergeSort(array, 0, n - 1, threshold);
  }

  for (int i : array) {
    std::cout << i << " ";
  }
  return 0;
}
