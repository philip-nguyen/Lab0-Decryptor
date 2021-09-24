#include "Decryptor.h"

// default constructor
Decryptor::Decryptor() {}

std::bitset<8> Decryptor::decrypt(std::bitset<8> byte, int amount) {
    const std::bitset<8> mask(((2 << (amount - 1)) - 1) << (8 - amount)); // shift left amount
    std::bitset<8> lowByte = byte & mask;
    std::bitset<8> highShift = byte << amount;
    std::bitset<8> lowShift = lowByte >> (8 - amount);

    std::bitset<8> wholeByte = lowShift ^ highShift;

    return wholeByte;
}