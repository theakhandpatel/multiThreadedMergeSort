#include "parallelMergeSort.hpp"
#include <future>

ParallelMergeSort::ParallelMergeSort(std::vector<int> nums, int threshold) : nums(nums), threadThreshold(threshold) {}

ParallelMergeSort::~ParallelMergeSort() {}

void ParallelMergeSort::sort() {
    recursiveSort(0, nums.size() - 1);
}

void ParallelMergeSort::recursiveSort(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        if (right - left + 1 > threadThreshold) {
            std::thread leftThread(&ParallelMergeSort::recursiveSort, this, left, middle);

            recursiveSort(middle + 1, right);

            leftThread.join();
        } else {
            recursiveSort(left, middle);
            recursiveSort(middle + 1, right);
        }

        merge(left, middle, right);
    }
}

void ParallelMergeSort::merge(int left, int middle, int right) {
    int leftArraySize = middle - left + 1;
    int rightArraySize = right - middle;

    std::vector<int> leftArray(leftArraySize);
    std::vector<int> rightArray(rightArraySize);

    std::copy(nums.begin() + left, nums.begin() + middle + 1, leftArray.begin());
    std::copy(nums.begin() + middle + 1, nums.begin() + right + 1, rightArray.begin());

    int leftPos = 0, rightPos = 0, mergedPos = left;

    while (leftPos < leftArraySize && rightPos < rightArraySize) {
        if (leftArray[leftPos] <= rightArray[rightPos]) {
            nums[mergedPos] = std::move(leftArray[leftPos]);
            leftPos++;
        } else {
            nums[mergedPos] = std::move(rightArray[rightPos]);
            rightPos++;
        }
        mergedPos++;
    }

    while (leftPos < leftArraySize) {
        nums[mergedPos] = std::move(leftArray[leftPos]);
        leftPos++;
        mergedPos++;
    }

    while (rightPos < rightArraySize) {
        nums[mergedPos] = std::move(rightArray[rightPos]);
        rightPos++;
        mergedPos++;
    }
}