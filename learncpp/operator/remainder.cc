#include <iostream>


// Best practice: Prefer to compare the result of the remainder operator% against 0 if possible.
bool isOdd(int x) {
	// return (x % 2) == 1;	// fails when x is -5
	return (x % 2) != 0;	// better to compare against 0
}

bool isEven(int x) {
	return (x % 2) == 0;
}

void testEven() {
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	if (isEven(x))
		std::cout << x << " is even\n";
	else 
		std::cout << x << " is odd\n";
}

int main() {
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	std::cout << "The remainder is: " << x % y << '\n';

	if ((x % y) == 0) 
		std::cout << x << " is evenly divisible by " << y << '\n';
	else
		std::cout << x << " is not evenly divisible by " << y << '\n';

	// testEven(); 
	return 0;
}