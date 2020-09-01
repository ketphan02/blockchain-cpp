#include <cstdio>
#include <ctime>
#include <iostream>
#include <vector>
#include "block.cpp"

using namespace std;

class Chain
{
    private:
    
        // something

    public:

        vector<Block> chain;
        int diff = 2;
        int miningReward = 200;

        Chain()
        {
            chain.push_back(initBlock());
        }

        Block initBlock()
        {
            time_t now = time(0);
            char* dt = ctime(&now);

            return Block(dt, "amount: ??");
        }

        Block lastBlock()
        {
            return chain[chain.size() - 1];
        }

        void addBlock(Block newBlock)
        {
            newBlock.prevHash = lastBlock().curHash;
            newBlock.curHash = newBlock.hashFunc();
            chain.push_back(newBlock);
        }
};