#include "sorting_algorithms.h"

// Helper function to swap two elements
void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// Selection Sort
void SelectionSort(std::vector<int>& data) {
	int n = static_cast<int>(data.size());
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (data[j] < data[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			Swap(data[i], data[minIndex]);
		}
	}
}

// Insertion Sort
void InsertionSort(std::vector<int>& data) {
	int n = static_cast<int>(data.size());
	for (int i = 1; i < n; ++i) {
		int key = data[i];
		int j = i - 1;
		while (j >= 0 && data[j] > key) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = key;
	}
}

// Bubble Sort
void BubbleSort(std::vector<int>& data) {
	int n = static_cast<int>(data.size());
	bool swapped;
	for (int i = 0; i < n - 1; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				Swap(data[j], data[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}
}

// Heap Sort
void Heapify(std::vector<int>& data, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && data[left] > data[largest]) {
		largest = left;
	}

	if (right < n && data[right] > data[largest]) {
		largest = right;
	}

	if (largest != i) {
		Swap(data[i], data[largest]);
		Heapify(data, n, largest);
	}
}

void HeapSort(std::vector<int>& data) {
	int n = static_cast<int>(data.size());
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(data, n, i);
	}

	for (int i = n - 1; i > 0; i--) {
		Swap(data[0], data[i]);
		Heapify(data, i, 0);
	}
}


void MergeSort(std::vector<int>& data) {
	int divide = 0;
	for (int i = 0; i < 
}
// void QuickSort(std::vector<int>& data);
// void RadixSort(std::vector<int>& data);
