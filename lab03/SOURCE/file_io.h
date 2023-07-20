#ifndef FILE_IO_H
#define FILE_IO_H

#include <vector>
#include <string>

bool ReadInputFile(const std::string& filePath, std::vector<int>& data);
bool WriteOutputFile(const std::string& filePath, const std::vector<int>& data);

#endif // FILE_IO_H