#include <iostream>

int main() {
	int x{ 7 };
	int y{ 5 };

	std::cout << "int / int = " << x / y << '\n';
	// static_cast<> operator to convert a char into an integer
	// It would print as an integer rather than a character
	std::cout << "double / double = " << static_cast<double>(x) / y << '\n';
	std::cout << "int / double = " << x / static_cast<double>(y) << '\n';
	std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << '\n';

	return 0; 
}