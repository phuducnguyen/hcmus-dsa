#pragma once
#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H

template <class T>
void Swap(T &a, T &b);
void GenerateRandomData(int* array, int n);
void GenerateSortedData(int* array, int n);
void GenerateReverseSortedData(int* array, int n);
void GenerateNearlySortedData(int* array, int n);
void GenerateData(int* array, int n, int dataType);

#endif // DATA_GENERATOR_H