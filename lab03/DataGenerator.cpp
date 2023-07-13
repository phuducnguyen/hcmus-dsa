#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

template <class T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//-------------------------------------------------
// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(vector<int>& data, int n) {
	std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> distribution(0, n-1);

  data.clear();
  for (int i = 0; i < n; i++) {
      data.push_back(distribution(generator));
  }
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(vector<int>& data, int n) {
	data.clear();
	for (int i = 0; i < n; i++)	{
		data.push_back(i);
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(vector<int>& data, int n)
{
	data.clear();
	for (int i = n - 1; i >= 0; i--) {
		data.push_back(i);
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(vector<int>& data, int n) {
	GenerateSortedData(data, n);
	std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> distribution(0, n-1);

  for (int i = 0; i < 10; i++)
  {
    int r1 = distribution(generator);
    int r2 = distribution(generator);
    Swap(data[r1], data[r2]);
  }
}

void GenerateData(vector<int>& data, int n, int dataType) {
	switch (dataType)	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(data, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(data, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(data, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(data, n);
		break;
	default:
		cout << "Error: Unknown data type!" << endl;
	}
}