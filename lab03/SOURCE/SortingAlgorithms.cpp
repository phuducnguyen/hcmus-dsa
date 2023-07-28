#include "SortingAlgorithms.h"

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

// Merge Sort
void Merge(std::vector<int>& data, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = data[left + i];
    }

    for (int j = 0; j < n2; j++) {
        rightArr[j] = data[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            data[k] = leftArr[i];
            i++;
        } else {
            data[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = rightArr[j];
        j++;
        k++;
    }
}

//== Helper for merge sort
void MergeSortUtil(std::vector<int>& data, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        MergeSortUtil(data, left, middle);
        MergeSortUtil(data, middle + 1, right);

        Merge(data, left, middle, right);
    }
}

//== Drive code of MergeSort
void MergeSort(std::vector<int>& data) {
    int n = static_cast<int>(data.size());
    MergeSortUtil(data, 0, n - 1);
}

// Quick Sort
int Partition(std::vector<int>& data, int low, int high) {
    int pivot = data[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (data[j] < pivot) {
            i++;
            Swap(data[i], data[j]);
        }
    }

    Swap(data[i + 1], data[high]);
    return (i + 1);
}

void QuickSortUtil(std::vector<int>& data, int low, int high) {
    if (low < high) {
        int pivotIndex = Partition(data, low, high);

        QuickSortUtil(data, low, pivotIndex - 1);
        QuickSortUtil(data, pivotIndex + 1, high);
    }
}

void QuickSort(std::vector<int>& data) {
    int n = static_cast<int>(data.size());
    QuickSortUtil(data, 0, n - 1);
}

// Radix Sort
int GetMax(std::vector<int>& data) {
    int maxVal = data[0];
    int n = static_cast<int>(data.size());
    for (int i = 1; i < n; i++) {
        if (data[i] > maxVal) {
            maxVal = data[i];
        }
    }
    return maxVal;
}

void CountSort(std::vector<int>& data, int exp) {
    int n = static_cast<int>(data.size());
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        count[(data[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(data[i] / exp) % 10] - 1] = data[i];
        count[(data[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        data[i] = output[i];
    }
}

void RadixSort(std::vector<int>& data) {
    int maxVal = GetMax(data);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        CountSort(data, exp);
    }
}


// Shaker Sort
void ShakerSort(std::vector<int>& data) {
	int left = 0;
	int right = data.size() - 1;
	bool swapped;

	do {
		swapped = false;

		// Move from left to right
		for (int i = left; i < right; i++) {
			if (data[i] > data[i + 1]) {
				Swap(data[i], data[i + 1]);
				swapped = true;
			}
 		}

 		//
  		right--;

 		// The list is already sorted
 		if (!swapped) {
 			break;	
 		}

 		// Move from right to left
 		for (int i = right; i > left; ++i) {
 			if (data[i] < data[i - 1]) {
 				Swap(data[i], data[i - 1]);
 				swapped = true;
 			}
 		}

 		left++;
	} while (swapped);
}

// Shell Sort
#include <vector>

void ShellSort(std::vector<int>& data) {
    int n = data.size();
    int gap = n / 2;

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = data[i];
            int j = i;

            while (j >= gap && data[j - gap] > temp) {
                data[j] = data[j - gap];
                j -= gap;
            }

            data[j] = temp;
        }

        gap /= 2;
    }
}

// Flash Sort
void FlashSort(std::vector<int>& data) {
    int n = data.size();
    if (n == 0) return;

    int m = static_cast<int>(0.45 * n);
    std::vector<int> temp(m, 0);

    int maxVal = data[0];
    int minVal = data[0];
    int maxIndex = 0;

    for (int i = 1; i < n; i++) {
        if (data[i] > maxVal) {
            maxVal = data[i];
            maxIndex = i;
        } else if (data[i] < minVal) {
            minVal = data[i];
        }
    }

    if (maxVal == minVal) return; // All elements are the same

    double c = static_cast<double>(m - 1) / (maxVal - minVal);

    for (int i = 0; i < n; i++) {
        int k = static_cast<int>(c * (data[i] - minVal));
        temp[k]++;
    }

    for (int i = 1; i < m; i++) {
        temp[i] += temp[i - 1];
    }

    int hold = data[maxIndex];
    data[maxIndex] = data[0];
    data[0] = hold;

    int moveIndex = 0;
    int j = 0;
    int k = m - 1;

    while (moveIndex < n - 1) {
        while (j > temp[k] - 1) {
            j++;
            k = static_cast<int>(c * (data[j] - minVal));
        }

        if (k < 0) break;

        int flash = data[j];

        while (j != temp[k]) {
            k = static_cast<int>(c * (flash - minVal));
            int hold = data[temp[k] - 1];
            data[--temp[k]] = flash;
            flash = hold;
            moveIndex++;
        }
    }

    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}
