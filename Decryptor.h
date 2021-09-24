#pragma once
#include <bitset>

class Decryptor {
public:
	Decryptor();
	std::bitset<8> decrypt(std::bitset<8> byte, int amount);
};