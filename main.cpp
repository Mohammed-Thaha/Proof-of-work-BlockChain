#include <iostream>
#include "blockchain.h"
int main()
{
    blockchain bc;
    std::cout << "Mining data-1" << std::endl;
    bc.Addblock(Block(1, "Block 1 data"));
    std::cout << "Mining data-2" << std::endl;
    bc.Addblock(Block(2, "Block 2 data"));
    std::cout << "Mining data-3" << std::endl;
    bc.Addblock(Block(3, "Block 3 data"));
}