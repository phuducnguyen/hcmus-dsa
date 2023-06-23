#include <iostream>

int main() {
	std::cout << "You have 12 apples. Enter how many people to divide them between: ";
	int x {};
	double d {};
	// std::cin >> x;	// Enter 0 -> program will likely crash
	std::cin >> d;

	// std::cout << "Each person gets " << 12 / x << " whole apples.\n";	// this is integer division
	std::cout << "Each person gets " << 12 / d << " apples.\n";	// d is double, so this is floating point division

	return 0;
}

