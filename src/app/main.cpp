#include <iostream>
#include <vector>
#include <mutex>
#include <chrono>
#include <cstdlib>
#include "sorting/mergeSort.hpp"
#include "sorting/parallelMergeSort.hpp"

void measureParallelSort(const std::vector<int>& nums, int chunkSize) {
    ParallelMergeSort* mergesort = new ParallelMergeSort(nums, chunkSize);
    auto start = std::chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "ParallelMergeSort (chunk size "<< chunkSize<<" )" << " time taken: " << duration.count() << " seconds" << std::endl;

    delete mergesort;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <size>" << std::endl;
        return 1;
    }

    int SIZE = std::atoi(argv[1]);
    if (SIZE <= 0) {
        std::cerr << "Invalid size: " << SIZE << std::endl;
        return 1;
    }

    std::vector<int> nums(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        nums[i] = rand() % SIZE;
    }

    int chunkSize = 1024*128;

    measureParallelSort(nums, chunkSize);
    measureParallelSort(nums, chunkSize/=2);
    measureParallelSort(nums, chunkSize/=2);
    measureParallelSort(nums, chunkSize/=2);
    measureParallelSort(nums, chunkSize/=2);


    MergeSort* mergesort = new MergeSort(nums);
    auto start = std::chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergeSortDuration = end - start;

    std::cout << "MergeSort time taken: " << mergeSortDuration.count() << " seconds" << std::endl;

    delete mergesort;
    return 0;
}