#include <iostream>
#include <vector>
#include "data_generator.h"
#include "sorting_algorithms.h"

void PrintData(const std::vector<int>& data) {
  for (int num : data) {
      std::cout << num << " ";
  }
  std::cout << std::endl;
}

int main() {
	// Sample variables
	int size = 100;

  // Generate nearly sorted data
  std::cout << "Nearly Sorted Data:" << std::endl;
  std::vector<int> nearlySortedData;
  GenerateNearlySortedData(nearlySortedData, size);
  PrintData(nearlySortedData);

  // Using Selection Sort
  SelectionSort(nearlySortedData);
  PrintData(nearlySortedData);

  return 0;
}
