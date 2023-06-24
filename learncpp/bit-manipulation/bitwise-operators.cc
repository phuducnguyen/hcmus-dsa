// For readability, we’ll also omit the 0b prefix outside of code examples 
// (e.g. instead of 0b0101, we’ll just use 0101).

#include <bitset>
#include <iostream>

int main() {
	// Note that if you're using operator << for both output and left shift
	// => Parenthesization is required
	// unsigned int x { 0b0100 };
	std::bitset<4> x { 0b1100 };
	// x = x << 1;	// use operator<< for left shift

	// std::cout << std::bitset<4> { x } << '\n';	// use operator<< for output
	std::cout << x << 1 << '\n';

	// std::cout << (x >> 1) << '\n';	// shift right by 1, yielding 0110
	std::cout << (x << 1) << '\n';	// shift left by 1, yielding 1000

	// Bitwise NOT (~)
	// It simply flips each bit from a 0 to a 1, or vice versa.
	std::cout << ~std::bitset<4>{ 0b0100 } << ' ' << ~std::bitset<8>{ 0b0100 } << '\n';

	// Bitwise OR(|)
	// Bitwise OR evaluates to 1 if either the left, right, or both bits are 1, and 0 otherwise
	std::cout << (std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110 }) << '\n';
	std::cout << (std::bitset<4>{ 0b0111 } | std::bitset<4>{ 0b0011 } | std::bitset<4>{ 0b0001 }) << '\n';

	// Bitwise AND(&)
	std::cout << (std::bitset<4>{ 0b0101 } & std::bitset<4>{ 0b0110 }) << '\n';

	// Bitwise XOR(^), also known as exclusive or
	// XOR evaluates to true (1) if one and only one of its operands is true (1). 
	// If neither or both are true, it evaluates to 0
	std::cout << (std::bitset<4>{ 0b0101 } ^ std::bitset<4>{ 0b0110 }) << '\n';

	return 0; 
}

/**
	Summarizing how to evaluate bitwise operations utilizing the column method:

When evaluating bitwise OR, if any bit in a column is 1, the result for that column is 1.
When evaluating bitwise AND, if all bits in a column are 1, the result for that column is 1.
When evaluating bitwise XOR, if there are an odd number of 1 bits in a column, the result for that column is 1.
*/