#include "mergeSort.hpp"

MergeSort::MergeSort(std::vector<int> &nums) : nums(nums){}

MergeSort::~MergeSort() {}

void MergeSort::sort() {
  if(nums.empty()) {
    return;
  }
  recursiveSort(0, nums.size() - 1);
}

void MergeSort::recursiveSort(int leftIndex, int rightIndex) {
  if(leftIndex >= rightIndex) {
    return;
  }
  int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
  recursiveSort(leftIndex, middleIndex);
  recursiveSort(middleIndex + 1, rightIndex);
  merge(leftIndex, middleIndex, rightIndex);
}

void MergeSort::merge(int leftIndex, int middleIndex, int rightIndex) {
  std::vector<int> mergedArray(rightIndex - leftIndex + 1);
  int leftSubarrayIndex = leftIndex;
  int rightSubarrayIndex = middleIndex + 1;
  int mergedArrayIndex = 0;

  while(leftSubarrayIndex <= middleIndex && rightSubarrayIndex <= rightIndex) {
    if(nums[leftSubarrayIndex] <= nums[rightSubarrayIndex]) {
      mergedArray[mergedArrayIndex++] = nums[leftSubarrayIndex++];
    } else {
      mergedArray[mergedArrayIndex++] = nums[rightSubarrayIndex++];
    }
  }

  while(leftSubarrayIndex <= middleIndex) {
    mergedArray[mergedArrayIndex++] = nums[leftSubarrayIndex++];
  }

  while(rightSubarrayIndex <= rightIndex) {
    mergedArray[mergedArrayIndex++] = nums[rightSubarrayIndex++];
  }

  for(int i = 0; i < mergedArray.size(); i++) {
    nums[leftIndex + i] = mergedArray[i];
  }
}
