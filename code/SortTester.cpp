#include "SortTester.h"
#include <chrono>

long long SortTester::measureTime(void (*sortFunc)(std::vector<int>&, int, int), std::vector<int>& array, int l, int r) {
  auto start = std::chrono::high_resolution_clock::now();
  sortFunc(array, l, r);
  auto elapsed = std::chrono::high_resolution_clock::now() - start;
  return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
}

long long SortTester::measureTime(void (*sortFunc)(std::vector<int>&, int, int, int), std::vector<int>& array, int l, int r, int threshold) {
  auto start = std::chrono::high_resolution_clock::now();
  sortFunc(array, l, r, threshold);
  auto elapsed = std::chrono::high_resolution_clock::now() - start;
  return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
}