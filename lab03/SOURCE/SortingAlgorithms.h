#pragma once
#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

/* Prototypes in the order 
 * The naming function standard: [AlgorithmName]Sort()
 * e.g: RadixSort(), FlashSort(),...
 */


/* Funtion prototypes for each sorting algorithms 
   Note: Helper for each algorithm be added in its section below
*/

/* 1. Selection Sort */
void SelectionSort(int* arr, int n);

/* 2. Insertion Sort */
void InsertionSort(int* arr, int n);

/* 3. Bubble Sort */
void BubbleSort(int* arr, int n);

/* 4. Heap Sort */
void HeapSort(int* arr, int n);

/* 5. Merge Sort */
void MergeSort(int* arr, int n);

/* 6. Quick Sort */
void QuickSort(int* arr, int n);

/* 7. Radix Sort */
void RadixSort(int* arr, int n);

/* 8. Shaker Sort */
void ShakerSort(int* arr, int n);

/* 9. Shell Sort */
void ShellSort(int* arr, int n);

/* 10. Counting Sort */
void CountingSort(int* a, int n);

/* 11. Flash Sort */
void FlashSort(int* arr, int n);

#endif // SORTING_ALGORITHMS_H
