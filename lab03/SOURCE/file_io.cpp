#include "file_io.h"
#include <fstream>

bool ReadInputFile(const std::string& filePath, std::vector<int>& data) {
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        return false;
    }

    int size;
    inputFile >> size;
    data.resize(size);
    for (int i = 0; i < size; i++) {
        inputFile >> data[i];
    }

    inputFile.close();
    return true;
}

bool WriteOutputFile(const std::string& filePath, const std::vector<int>& data) {
    std::ofstream outputFile(filePath);
    if (!outputFile) {
        return false;
    }

    int size = static_cast<int>(data.size());
    outputFile << size << '\n';
    for (int i = 0; i < size; i++) {
        outputFile << data[i] << ' ';
    }
    outputFile << '\n';

    outputFile.close();
    return true;
}