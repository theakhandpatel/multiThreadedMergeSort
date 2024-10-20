#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

class MergeSort
{
private:
  std::vector<int> &nums;
  void recursiveSort(int leftIndex, int rightIndex);
  void merge(int leftIndex, int middleIndex, int rightIndex);

public:
  MergeSort(std::vector<int> &nums);
  ~MergeSort();
  void sort();
};

#endif