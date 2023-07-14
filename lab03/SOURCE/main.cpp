#include "DataGenerator.cpp"

int main() {
	const int dataSize = 100;
	vector<int> data;

	// Generate random data
	GenerateData(data, dataSize, 3);

	// Print the generated data
	cout << "Generated data: ";
	for (int i = 0; i < dataSize; ++i) {
		cout << data[i] << " ";
	}

	cout << endl;

	return 0;
}