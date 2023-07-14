#include "data_generator.h"
#include <algorithm>	// for std::swap
#include <random>			// for std::mt19937

// Generates a random sequence of integers
void GenerateRandomData(std::vector<int>& data, int size) {
	std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> distribution(0, size - 1);

  data.clear();
  for (int i = 0; i < size; i++) {
      data.push_back(distribution(generator));
  }
}

// Generates data in ascending order
void GenerateSortedData(std::vector<int>& data, int size) {
	data.clear();
	
	for (int i = 0; i < size; i++)	{
		data.push_back(i);
	}
}

// Generates data in descending order
void GenerateReverseSortedData(std::vector<int>& data, int size)
{
	data.clear();

	for (int i = size - 1; i >= 0; i--) {
		data.push_back(i);
	}
}

// Generates nearly sorted data where only a few elements are out of order
void GenerateNearlySortedData(std::vector<int>& data, int size) {
	GenerateSortedData(data, size);
	
	std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> distribution(0, size - 1);

  for (int i = 0; i < 10; i++) {
    int r1 = distribution(generator);
    int r2 = distribution(generator);
    std::swap(data[r1], data[r2]);
  }
}

void GenerateData(std::vector<int>& data, int size, DataOrder order) {
	switch (order) {
		case DataOrder::Random:
			GenerateRandomData(data, size);
			break;
		case DataOrder::Sorted:
			GenerateSortedData(data, size);
			break;
		case DataOrder::ReverseSorted:
			GenerateReverseSortedData(data, size);
			break;
		case DataOrder::NearlySorted:
			GenerateNearlySortedData(data, size);
			break;
		default:
			printf("Error: unknown data type!\n");
			// throw std::runtime_error("Unknown data order!");
	}
}