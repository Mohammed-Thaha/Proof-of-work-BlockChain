#include "block.h"
#include "sha256.h"
#include <sstream>   // For stringstream
#include <iostream>  // For console outpu
#include<time.h>
#define nDifficulty 1
// Constructor to initialize the block
Block::Block(uint32_t nIndex, const std::string& sdata)
    : m_index(nIndex), m_sdata(sdata), m_nNounce(-1), m_time(time(nullptr)) {
    m_shash = Calculatehash();  // Generate hash when block is created
}

// Function to calculate the hash of the block
inline std::string Block::Calculatehash() const {
    std::stringstream stream;
    stream << m_index << m_time << m_sdata << m_sprevhash;

    std::cout << "Calculating hash with: "
              << "Index: " << m_index << ", "
              << "Time: " << m_time << ", "
              << "Data: " << m_sdata << ", "
              << "Prev Hash: " << m_sprevhash << std::endl;

    return sha256(stream.str());
}


void Block::Mineblock() {
    char cstr[nDifficulty + 1];
    for (uint32_t index = 0; index < nDifficulty; ++index) {
        cstr[index] = '0';
    }
    cstr[nDifficulty] = '\0';
    std::string str(cstr);
    
    do {
        m_shash = Calculatehash();
        m_nNounce++;
        // Output the current mining status with hash
        std::cout << "Mining " << m_sdata << " with hash: " << m_shash << std::endl; // Print current hash
        std::cout << "Nonce: " << m_nNounce << std::endl; // Print current nonce
    } while (m_shash.substr(0, nDifficulty) != str);
    
    std::cout << "Block Mined: " << m_shash << std::endl;
}
