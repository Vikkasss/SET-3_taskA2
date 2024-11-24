#ifndef SORTTESTER_H
#define SORTTESTER_H

#include <vector>

class SortTester {
public:
  static long long measureTime(void (*sortFunc)(std::vector<int>&, int, int), std::vector<int>& array, int l, int r);
  static long long measureTime(void (*sortFunc)(std::vector<int>&, int, int, int), std::vector<int>& array, int l, int r, int threshold);
};

#endif // SORTTESTER_H