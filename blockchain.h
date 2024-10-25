#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "block.h"

class blockchain {
private:
    std::vector<Block> m_vblockchain; 

public:
    blockchain(); 
    void Addblock(const Block& bnewBlock); 
    Block GetLastBlock() const; 
};

#endif 
