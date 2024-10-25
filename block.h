#ifndef BLOCK_H  
#define BLOCK_H

#include <cstdint>  
#include <string>
#include <ctime>    

class Block {
private:
    std::string m_shash, m_sprevhash;  
    uint32_t m_index;                 
    int32_t m_nNounce;                
    time_t m_time;                     
    std::string m_sdata;             
    std::string Calculatehash() const;

public:
    
    Block(uint32_t nIndex, const std::string& sdata);
    void Mineblock();
    void Setprevhash(const std::string& sprevhash) {
        m_sprevhash = sprevhash;
    }
    std::string GetHash() const {
        return m_shash;
    }
    std::string GetPrevHash() const {
        return m_sprevhash;
    }
};
#endif
