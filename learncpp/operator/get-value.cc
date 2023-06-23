#include <iostream>

int getValue() {
	std::cout << "Enter an integer: ";

	int x{};
	std::cin >> x;
	return x;
}

int main() {
	// The compiler may choose a different order
	// left-to-right order	-> 1 + (2 * 3) = 7
	// right-to-left order	-> 3 + (2 * 1) = 5
	// std::cout << getValue() + (getValue() * getValue()) << '\n';	// a + (b * c)

	int x{ getValue() };	// will execute first
	int y{ getValue() };	// will execute second
	int z{ getValue() };	// will execute third

	// std::cout << a + (b * c) << '\n';	// order of eval doesn't matter now
	x = 2 + 3 % 4;
	x = y = z;			// x = (y == z)
	z *= ++y + 5;		// z *= ((++y) + 5)
	// a || b && c || d; 	// (a || (b && c)) || d; 
	std::cout << x << '\n';
	return 0;
}