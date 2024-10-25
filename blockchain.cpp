#include"blockchain.h"
#include"block.h"
blockchain::blockchain(){
    m_vblockchain.emplace_back(Block(0,"Genesis Block"));
 }
void blockchain::Addblock(const Block& bnewBlock) {
    std::string prevHash;
    if (!m_vblockchain.empty()) {
        prevHash = m_vblockchain.back().GetHash(); 
    }

    Block newBlock(m_vblockchain.size(), bnewBlock.GetHash()); // Create a new block
    newBlock.Setprevhash(prevHash); // Set the previous hash
    m_vblockchain.push_back(newBlock); 
}

