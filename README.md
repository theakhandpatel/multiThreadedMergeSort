# Parallel and Sequential Merge Sort

This project implements both parallel and sequential versions of the merge sort algorithm in C++. The parallel version uses multithreading to improve performance on large datasets.


### Files

- **main.cpp**: Contains the main function which initializes the dataset and measures the performance of both the parallel and sequential merge sort algorithms.
- **mergeSort.cpp**: Implements the sequential merge sort algorithm.
- **mergeSort.hpp**: Header file for the sequential merge sort algorithm.
- **parallelMergeSort.cpp**: Implements the parallel merge sort algorithm using multithreading.
- **parallelMergeSort.hpp**: Header file for the parallel merge sort algorithm.

## Design Choices

### Threshold for Parallelization

In the parallel merge sort implementation, a threshold is set to determine when to switch from parallel to sequential sorting. This threshold is crucial for the following reasons:

1. **Overhead of Thread Creation**: Creating and managing threads has overhead. For small subarrays, the overhead of creating threads outweighs the benefits of parallel execution. Therefore, a threshold is set to ensure that only sufficiently large subarrays are sorted in parallel.
2. **Resource Management**: If the threshold is set too low, the number of threads created can become excessively high, leading to resource exhaustion and potential errors. This is especially problematic when the array size is large compared to the threshold.

### Why Parallelization Doesn't Make Sense for Small Arrays

For small arrays, the overhead of thread management can be significant compared to the actual sorting time. In such cases, the sequential merge sort is more efficient. The threshold ensures that parallelization is only used when it provides a performance benefit.

### Potential Errors with Low Thresholds

If the threshold is set too low, the number of threads created can be very high, leading to:

1. **Resource Exhaustion**: The system may run out of resources to create new threads, leading to errors.
2. **Context Switching Overhead**: With too many threads, the overhead of context switching can degrade performance, negating the benefits of parallelization.

## Usage

### Building the Project

To build the project, you can use a C++ compiler like `g++`. Navigate to the `src/app` directory and run:

```sh
g++ -std=c++11 -o merge_sort 

main.cpp

 

mergeSort.cpp

 

parallelMergeSort.cpp

 -pthread
```

### Running the Project

After building the project, you can run the executable with the desired size of the dataset:

```sh
./merge_sort <size>
```

Replace `<size>` with the number of elements you want to sort. For example:

```sh
./merge_sort 1000000
```

### Example Output

```
ParallelMergeSort (chunk size 131072) time taken: 0.123456 seconds
ParallelMergeSort (chunk size 65536) time taken: 0.234567 seconds
ParallelMergeSort (chunk size 32768) time taken: 0.345678 seconds
ParallelMergeSort (chunk size 16384) time taken: 0.456789 seconds
ParallelMergeSort (chunk size 8192) time taken: 0.567890 seconds
MergeSort time taken: 0.678901 seconds
```

## Code Overview

### `main.cpp`

The main function initializes a vector of random integers and measures the performance of both the parallel and sequential merge sort algorithms.

### `mergeSort.cpp` and `mergeSort.hpp`

These files implement the sequential merge sort algorithm. The `MergeSort` class contains methods for sorting and merging subarrays.

### `parallelMergeSort.cpp` and `parallelMergeSort.hpp`

These files implement the parallel merge sort algorithm using multithreading. The `ParallelMergeSort` class contains methods for sorting and merging subarrays, and it uses threads to sort subarrays in parallel when the size of the subarray exceeds a certain threshold.

## License

This project is licensed under the MIT License. So do whatever you want with it.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.


