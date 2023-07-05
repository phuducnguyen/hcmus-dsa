#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cassert>

using namespace std;

/**
 * Generates all permutations of a given string using backtracking.
 *
 * @param characters the string to generate permutations from
 * @param start the starting index of the substring
 * @param end the ending index of the substring
 */
void generatePermutations(string& characters, int start, int end) {
    if (start == end) {
        cout << characters << endl;
        return;
    }

    for (int i = start; i <= end; ++i) {
        swap(characters[start], characters[i]);
        generatePermutations(characters, start + 1, end);
        swap(characters[start], characters[i]); // Backtrack
    }
}

/**
 * Prints a 3D matrix.
 *
 * @param matrix the 3D matrix to be printed
 * @param layers the number of layers in the matrix
 * @param rows the number of rows in each layer
 * @param cols the number of columns in each layer
 */
void print3DMatrix(char*** matrix, int layers, int rows, int cols) {
    for (int i = 0; i < layers; ++i) {
        cout << "Layer " << i + 1 << ":" << endl;
        for (int j = 0; j < rows; ++j) {
            for (int k = 0; k < cols; ++k) {
                cout << matrix[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

/**
 * A debugging function to demonstrate the usage of print3DMatrix.
 * Creates a 3D matrix and prints its contents.
 */
void main_debug() {
    int layers = 2;
    int rows = 5;
    int cols = 7;

    // Create a 2D matrix using pointer-to-pointer
    char** tempMatrix = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        tempMatrix[i] = new char[cols];
        for (int j = 0; j < cols; ++j) {
            tempMatrix[i][j] = '*';
        }
    }

    // Create a 3D matrix using a pointer-to-pointer-to-pointer
    char*** matrix = new char**[layers];
    for (int i = 0; i < layers; ++i) {
        matrix[i] = tempMatrix;
    }

    // Print the 3D matrix
    print3DMatrix(matrix, layers, rows, cols);

    // Deallocate memory for the 2D matrix
    for (int i = 0; i < rows; ++i) {
        delete[] tempMatrix[i];
    }
    delete[] tempMatrix;

    // Deallocate memory for the 3D matrix
    delete[] matrix;
}

/**
 * A test case function to demonstrate the usage of generatePermutations.
 * Generates all permutations of a string and prints them.
 */
void test_case() {
    string characters = "ABCD";
    int length = characters.length();
    generatePermutations(characters, 0, length - 1);
}

int main() {
    main_debug();
    // test_case();
    return 0;
}
