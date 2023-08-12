#include <iostream>
#include <chrono>
#include <random>
#include <climits>


using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* sum(int* a, int* b) {
	int* result = new int;
	*result = *a + *b; 
	return result;
}

void inputArray(int* a, int &n) {
	cout << "Enter the size of the array: ";
  	cin >> n;

  	cout << "Enter the elements of the array: ";
  	for (int i = 0; i < n; i++) {
    	cin >> a[i];
	}
}

void printArray(int* a, int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int* findMax(int* arr, int n) {
	int* maxElement = arr;
	for (int i = 1; i < n; ++i) {
		if (*arr < arr[i]) { 
			maxElement = &arr[i];
		}
	}
	return maxElement;
}

int* findLongestAscendingSubarray(int* a, int n, int &length) {
	int* start = a;
	int maxLength = 1;
	int currentLength = 1;

	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1]) {
			currentLength++;
			if (currentLength > maxLength) {
				maxLength = currentLength;
				start = &a[i - maxLength + 1];
			}
		} else {
			currentLength = 1;
		}
	}

	length = maxLength;
	return start;
}

void swapArrays(int* a, int* b, int &na, int &nb) {
	int* temp = a;
	a = b;
	b = temp;

	int tempSize = na;
	na = nb;
	nb = tempSize;
}

// Concatenate 2 given array
int* concateante2Arrays(int* a, int* b, int na, int nb) {
	int* result = new int[na + nb];

	for (int i = 0; i < na; ++i) {
		result[i] = a[i];
	}

	for (int i = 0; i < nb; ++i) {
		result[na + i] = b[i];
	}

	return result;
}

// Given 2 ascending array with distinguish elements. 
// Generate a new ascending array with all elements from the given array.
int* merge2Arrays(int* a, int* b, int na, int nb, int&nc) {
	int* mergedArray = new int[na + nb];
	int i = 0, j = 0, k = 0;

	while (i < na && j < nb) {
		if (a[i] < b[j]) {
			mergedArray[k++] = a[i++];
		} else {
			mergedArray[k++] = b[j++];
		}
	}

	while (i < na) {
		mergedArray[k++] = a[i++];
	}

	while (j < nb) {
		mergedArray[k++] = b[j++];
	}

	nc = nb + nb;
	return mergedArray;
}

// Generate a random matrix with keyboard input size.
void generateMatrix1(int**& A, int &length, int &width) {
    cout << "Enter the number of rows: ";
    cin >> length;
    cout << "Enter the number of columns: ";
    cin >> width;
	
	// Create a random number generator using a high-resolution clock as the seed
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    uniform_int_distribution<int> distribution(0, 99);

    A = new int*[length];
    for (int i = 0; i < length; ++i) {
    	A[i] = new int[length];
    	for (int j = 0; j < width; ++j) {
    		A[i][j] = distribution(rng);	// Generate random values between 0 and 99
    	}
    }
}

// Function to generate a matrix where c[i][j] = a[i] * b[j]
int** generateMatrix2(int* a, int* b, int na, int nb) {
	int** c = new int*[na];
	for (int i = 0; i < na; ++i) {
		c[i] = new int[nb];
		for (int j = 0; j < nb; ++j) {
			c[i][j] = a[i] * b[j];
		}
	}
	return c;
}

// Function to swap two rows of a matrix
void swapRows(int** a, int length, int width, int row1, int row2) {
	for (int j = 0; j < width; ++j) {
		swap(a[row1][j], a[row2][j]);
	} 
}

// Function to swap two columns of a matrix
void swapCols(int** a, int length, int width, int col1, int col2) {
	for (int i = 0; i < length; ++i) {
		swap(a[i][col1], a[i][col2]);
	} 
}

// Function to generate the transpose matrix of a given matrix
int** transposeMatrix(int** a, int length, int width) {
    int** transposed = new int*[width];
    for (int i = 0; i < width; ++i) {
        transposed[i] = new int[length];
        for (int j = 0; j < length; ++j) {
            transposed[i][j] = a[j][i];
        }
    }
    return transposed;
}

// Function to concatenate two matrices horizontally
int** concatenate2MatricesH(int** a, int** b, int length, int widthA, int widthB) {
	int** result = new int*[length];
	for (int i = 0; i < length; ++i) {
		result[i] = new int [widthA + widthB];
		for (int j = 0; j < widthA; ++j) {
			result[i][j] = a[j][i];
		}

		for (int j = 0; j < widthB; ++j) {
			result[i][widthA + j] = b[i][j];
		}
	}

	return result;
}

// Function to concatenate two matrices vertically
int** concatenate2MatricesV(int** a, int** b, int lengthA, int lengthB, int width) {
	int** result = new int*[lengthA + lengthB];
	for (int i = 0; i < lengthA; ++i) {
		result[i] = new int [width];
		for (int j = 0; j < width; ++j) {
			result[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < lengthB; ++i) {
		result[lengthA + i] = new int[width];
		for (int j = 0; j < width; ++i) {
			result[lengthA + i][j] = b[i][j];
		}
	}

	return result;
}

// Function to multiply two matrices
bool multiply2Matrices(int** a, int** b, int** result, int lengtha, int widtha, int lengthb, int widthb) {
	if (widtha != lengthb) {
		return false;	// Cannot multiply matrices with incompatible dimension
	} 

	for (int i = 0; i < lengtha; ++i) {
		for (int j = 0; j < lengthb; ++j) {
			result[i][j] = 0;
			for (int k = 0; k < widtha; ++k) {
				result[i][j] += a[j][k] * b[k][j];
			}
		}
	}

	return true;
}

// Function to find the submatrix with the largest total value
int** findSubmatrix(int** a, int length, int width, int subLength, int subWidth, int &length_, int &width_) {
	if (subLength > length || subWidth > width)
		return nullptr;	// Invalid submatrix size

	int maxSum = INT_MIN;
	int** submatrix = nullptr;

	for (int i = 0; i <= length - subLength; ++i) {
		for (int j = 0; j <= width - subWidth; ++j) {
			int sum = 0;
			for (int k = i; k < i + subLength; ++k) {
				for (int l = j; l < j + subWidth; ++l) {
					sum += a[k][l];
				}
			}
			if (sum > maxSum) {
				maxSum = sum;
				submatrix = &a[i];
				length_ = subLength;
				width_ = subWidth;
			}
		}
	}
	return submatrix;
}



int main() {
	cout << "Success!";

}