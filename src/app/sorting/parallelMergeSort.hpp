#ifndef PARALLELMERGESORT_H
#define PARALLELMERGESORT_H

#include <vector>
#include <thread>
#include <mutex>
#include <iostream>

class ParallelMergeSort {
private:
    std::vector<int> nums;
    int threadThreshold;
    void recursiveSort(int leftIndex, int rightIndex);
    void merge(int leftIndex, int middleIndex, int rightIndex);

public:
    ParallelMergeSort(std::vector<int> nums, int threshold);
    ~ParallelMergeSort();
    void sort();
};

#endif