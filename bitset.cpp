#include <bitset>
#include <iostream>

int func() {
	//char a{ 'A' }, b{ 'B' }, c{ 'C' };

	std::bitset<8> char1('A');
	std::bitset<8> char2('5');
	std::bitset<8> char3('z');

	std::cout << char1 << " ^ " << char2 << " = " << (char1 ^ char2) << std::endl;
	std::cout << char1 << " ^ " << char3 << " = " << (char1 ^ char3) << std::endl;
	std::cout << char2 << " ^ " << char3 << " = " << (char2 ^ char3) << std::endl;

	return 0;
}