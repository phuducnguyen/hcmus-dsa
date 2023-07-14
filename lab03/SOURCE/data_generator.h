#pragma once
#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H

#include <vector>

enum class DataOrder {
    Random,
    Sorted,
    ReverseSorted,
    NearlySorted
};

void GenerateRandomData(std::vector<int>& data, int size);
void GenerateSortedData(std::vector<int>& data, int size);
void GenerateReverseSortedData(std::vector<int>& data, int size);
void GenerateNearlySortedData(std::vector<int>& data, int size);
void GenerateData(std::vector<int>& data, int size, DataOrder order);

#endif // DATA_GENERATOR_H