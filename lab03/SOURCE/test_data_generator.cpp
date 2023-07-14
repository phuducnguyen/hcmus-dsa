#include <iostream>
#include <vector>
#include "data_generator.h"

void PrintData(const std::vector<int>& data) {
  for (int num : data) {
      std::cout << num << " ";
  }
  std::cout << std::endl;
}

int main() {
	// Sample variables
	int size = 100;

  // Generate random data
  std::cout << "Random Data:" << std::endl;
  std::vector<int> randomData;
  GenerateRandomData(randomData, size);
  PrintData(randomData);

  // Generate nearly sorted data
  std::cout << "Nearly Sorted Data:" << std::endl;
  std::vector<int> nearlySortedData;
  GenerateNearlySortedData(nearlySortedData, size);
  PrintData(nearlySortedData);

  // Generate sorted data
  std::cout << "Sorted Data:" << std::endl;
  std::vector<int> sortedData;
  GenerateSortedData(sortedData, size);
  PrintData(sortedData);

  // Generate reverse sorted data
  std::cout << "Reverse Sorted Data:" << std::endl;
  std::vector<int> reverseSortedData;
  GenerateReverseSortedData(reverseSortedData, size);
  PrintData(reverseSortedData);

  return 0;
}
