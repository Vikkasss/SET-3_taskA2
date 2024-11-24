#ifndef ARRAYGENERATOR_H
#define ARRAYGENERATOR_H

#include <vector>

class ArrayGenerator {
public:
  static std::vector<int> generateRandomArray(int size, int minVal, int maxVal);
  static std::vector<int> generateReverseSortedArray(int size, int minVal, int maxVal);
  static std::vector<int> generateNearlySortedArray(int size, int minVal, int maxVal, int swapCount);
};

#endif // ARRAYGENERATOR_H