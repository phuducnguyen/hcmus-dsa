#include "DataGenerator.h"
#include <algorithm>	// for std::swap
#include <random>		// for std::mt19937

template <class T>
void Swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

/* We was modified to Dynamic Arrays */
// Generates a random sequence of integers
void GenerateRandomData(int* array, int n) {
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(0, n - 1);

	for (int i = 0; i < n; i++) {
	array[i] = distribution(generator);
	}
}

// Generates array in ascending order
void GenerateSortedData(int* array, int n) {
	for (int i = 0; i < n; i++)	{
		array[i] = i;
	}
}

// Generates array in descending order
void GenerateReverseSortedData(int* array, int n)
{
	for (int i = n - 1; i >= 0; i--) {
		array[i] = i;
	}
}

// Generates nearly sorted array where only a few elements are out of order
void GenerateNearlySortedData(int* array, int n) {
	GenerateSortedData(array, n);
	
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(0, n - 1);

	for (int i = 0; i < 10; i++) {
		int r1 = distribution(generator);
		int r2 = distribution(generator);
		Swap(array[r1], array[r2]);
	}
}

void GenerateData(int* array, int n, int dataType) {
	switch (dataType) {
		case 0:
			GenerateRandomData(array, n);
			break;
		case 1:
			GenerateSortedData(array, n);
			break;
		case 2:
			GenerateReverseSortedData(array, n);
			break;
		case 3:
			GenerateNearlySortedData(array, n);
			break;
		default:
			printf("Error: unknown array type!\n");
			// throw std::runtime_error("Unknown array order!");
	}
}
