// Lab0-Decryption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include "Decryptor.h"

#include <fstream>
#include <string>

std::bitset<8> encrypt(std::bitset<8>, int);
std::bitset<8> decrypt(std::bitset<8>, int);


// TODO: Make classes for Reader, Parser, Decryptor
// all in one .cpp file


int main()
{
    std::cout << "Hello World!\n";
    Decryptor d;

    auto x = encrypt(std::bitset<8>('X'), 3);
    auto y = d.decrypt(x, 3);

    if (std::bitset<8>('X') == y) std::cout << "Match!" << std::endl;
    else std::cout << "No Match..." << std::endl;

    
    std::string myLine;
    std::ifstream myFile("EncryptedCC.bin", std::ios::binary | std::ios::in);
    
    // std::cout << *chunk << std::endl;
    if (myFile.is_open()) {
        
        myFile.seekg(0, std::ios::end);
        std::fstream::pos_type fileSize = myFile.tellg();
        myFile.seekg(0, std::ios::beg);

        std::cout << "reading " << fileSize << " characters" << std::endl;
        char* chunk = new char[fileSize] {'a'};
        char* head = chunk;

        myFile.read(chunk, fileSize);
        std::cout << *chunk << std::endl;
        for (int j = 0; j < 8; j++) {
            std::cout << "Rotation: " << j << std::endl;
            for (int i = 0; i < fileSize; i++) {
                std::cout << static_cast<unsigned char>(d.decrypt(*chunk, j).to_ulong()) << " ";
                chunk++;
            }
            std::cout << "\n";
            chunk = head;
        }
        std::cout << '\n';
        

    }
    if (!myFile) {
        std::cout << "Can't open file!" << std::endl;
    }

    
    /*
    * static_cast<unsigned char>(d.decrypt(*chunk, 0).to_ulong());
    * 
    * EncryptedAA.bin rotation = 7
    * EncryptedBB.bin rotation = 6
    * EncryptedCC.bin rotation = 5
    */
    
}

// for development purposes 
std::bitset<8> encrypt(std::bitset<8> byte, int amount) {
    const std::bitset<8> mask ((2 << (amount-1)) - 1);
    std::bitset<8> lowByte = byte & mask;
    std::bitset<8> highShift = byte >> amount;
    std::bitset<8> lowShift = lowByte << (8 - amount);
    // use of XOR here is fine bc the shifts occupy separate bits
    // there is no loss of bits
    std::bitset<8> wholeByte = lowShift ^ highShift;

    std::cout << byte << std::endl << mask << std::endl << lowByte << std::endl
        << highShift << std::endl << lowShift << std::endl
        << wholeByte << std::endl << (2 << (amount - 1)) << std::endl;

    return wholeByte;
}

std::bitset<8> decrypt(std::bitset<8> byte, int amount) {
    const std::bitset<8> mask(((2 << (amount - 1)) - 1) << (8 - amount)); // shift left amount
    std::bitset<8> lowByte = byte & mask;
    std::bitset<8> highShift = byte << amount;
    std::bitset<8> lowShift = lowByte >> (8 - amount);

    std::bitset<8> wholeByte = lowShift ^ highShift;

    return wholeByte;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
