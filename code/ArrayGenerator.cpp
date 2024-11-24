#include "ArrayGenerator.h"
#include <random>
#include <algorithm>

//Массивы, которые заполнены случайными значениями в некотором диапазоне
std::vector<int> ArrayGenerator::generateRandomArray(int size, int minVal, int maxVal) {
  std::vector<int> array(size);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(minVal, maxVal);
  for (int i = 0; i < size; ++i) {
    array[i] = dis(gen);
  }
  return array;
}

//Массивы, которые отсортированы в обратном порядке по невозрастанию.
std::vector<int> ArrayGenerator::generateReverseSortedArray(int size, int minVal, int maxVal) {
  std::vector<int> array = generateRandomArray(size, minVal, maxVal);
  std::sort(array.begin(), array.end(), std::greater<int>());
  return array;
}

// Массивы, которые «почти» отсортированы.
std::vector<int> ArrayGenerator::generateNearlySortedArray(int size, int minVal, int maxVal, int swapCount) {
  std::vector<int> array = generateRandomArray(size, minVal, maxVal);
  std::sort(array.begin(), array.end());
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, size - 1);
  for (int i = 0; i < swapCount; ++i) {
    int idx1 = dis(gen);
    int idx2 = dis(gen);
    std::swap(array[idx1], array[idx2]);
  }
  return array;
}