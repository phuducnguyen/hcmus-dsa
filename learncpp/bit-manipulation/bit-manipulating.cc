#include <bitset>	// for std::bitset
#include <iostream>

/*
std::bitset provides 4 key member functions that are useful for doing bit manipulation:

	test() allows us to query whether a bit is a 0 or 1
	set() allows us to turn a bit on (this will do nothing if the bit is already on)
	reset() allows us to turn a bit off (this will do nothing if the bit is already off)
	flip() allows us to flip a bit value from a 0 to a 1 or vice versa
*/

int main() {
	std::bitset<8> bits{ 0b0000'0101 };	// we need 8 bits, start with bit pattern 0000 0101
	bits.set(3);	// set bit position 3 to 1 (now we have 0000 1101)
	bits.flip(7);	// flip bit 4 (now we have 0001 0101)
	bits.reset(7);	// set bit 4 back to 0 (now we have 0000 1101)

	std::cout << "All the bits: " << bits << '\n';
	std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
	std::cout << "Bit 7 has value: " << bits.test(7) << '\n';
	
	std::cout << "The size of std::bitset: " << sizeof(bits) << '\n';
	// The number of bytes needed to hold the bits
	// 4 bytes on 32-bit machines, 8 bytes on 64-bit machines
	// Technically only need 1 byte to store 8 bits 
	std::cout << "The size of std::bitset: " << sizeof(size_t) << '\n';
	return 0;
}