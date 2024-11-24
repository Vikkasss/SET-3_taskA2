#include <iostream>
#include <vector>
#include <chrono>
#include "ArrayGenerator.h"
#include "SortTester.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include "HybridSort.h"

int main() {
    std::vector<int> thresholds = {5, 10, 20, 30, 50};
    std::vector<int> sizes;
    std::vector<int> random_time_value;
    std::vector<int> reverse_time_value;
    std::vector<int> nearly_time_value;
    for (int size = 500; size <= 10000; size += 100) {
        sizes.push_back(size);
    }

    for (int size : sizes) {
        std::vector<int> randomArray = ArrayGenerator::generateRandomArray(size, 0, 6000);
        std::vector<int> reverseSortedArray = ArrayGenerator::generateReverseSortedArray(size, 0, 6000);
        std::vector<int> nearlySortedArray = ArrayGenerator::generateNearlySortedArray(size, 0, 6000, size / 100);

        //std::cout << "Size: " << size << "\n" ;

        // Замеры для стандартного MERGE SORT
        std::vector<int> randomCopy = randomArray;
        std::vector<int> reverseCopy = reverseSortedArray;
        std::vector<int> nearlyCopy = nearlySortedArray;
        //
        // long long randomTime = SortTester::measureTime(mergeSort, randomCopy, 0, size - 1);
        // random_time_value.push_back(randomTime);
        // long long reverseTime = SortTester::measureTime(mergeSort, reverseCopy, 0, size - 1);
        // reverse_time_value.push_back(reverseTime);
        // long long nearlyTime = SortTester::measureTime(mergeSort, nearlyCopy, 0, size - 1);
        // nearly_time_value.push_back(nearlyTime);
        //
        // std::cout << "Merge Sort - Random: " << randomTime << " ms" << "\n";
        // std::cout << "Merge Sort - Reverse: " << reverseTime << " ms" << "\n";
        // std::cout << "Merge Sort - Nearly Sorted: " << nearlyTime << " ms" << "\n";

        //Замеры для гибридного MERGE+INSERTION SORT
        for (int threshold : thresholds) {
            randomCopy = randomArray;
            reverseCopy = reverseSortedArray;
            nearlyCopy = nearlySortedArray;

            long long randomHybridTime = SortTester::measureTime(hybridMergeSort, randomCopy, 0, size - 1, threshold);
            random_time_value.push_back(randomHybridTime);
            long long reverseHybridTime = SortTester::measureTime(hybridMergeSort, reverseCopy, 0, size - 1, threshold);
            reverse_time_value.push_back(reverseHybridTime);
            long long nearlyHybridTime = SortTester::measureTime(hybridMergeSort, nearlyCopy, 0, size - 1, threshold);
            nearly_time_value.push_back(nearlyHybridTime);

            // std::cout << "Hybrid Merge+Insertion Sort (Threshold " << threshold << ") - Random: " << randomHybridTime << " ms" << "\n";
            // std::cout << "Hybrid Merge+Insertion Sort (Threshold " << threshold << ") - Reverse: " << reverseHybridTime << " ms" << "\n";
            // std::cout << "Hybrid Merge+Insertion Sort (Threshold " << threshold << ") - Nearly Sorted: " << nearlyHybridTime << " ms" << "\n";
        }
    }

    for (int i : random_time_value) {
        std::cout << i << ", ";
    }
    std::cout << "\n";
    for (int i : reverse_time_value) {
        std::cout << i << ", ";
    }
    std::cout << "\n";
    for (int i : nearly_time_value) {
        std::cout << i << ", ";
    }

    return 0;
}