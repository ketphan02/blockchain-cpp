#pragma once

#include <ctime>
#include <vector>
#include "block.h"
#include "transaction.h"

using namespace std;

class Chain
{
    private:

        Transactions init = Transactions("", "", 0);
        vector<Transactions> first_trans = {init};

        time_t now = time(0);
        char* dt = ctime(&now);

    public:

        vector<Block> chain;
        long long diff = 2;
        long long miningReward = 200;
        vector<Transactions> pendingTransactions;

        Chain()
        {
            chain.push_back(initBlock());
        }

        Block initBlock()
        {
            time_t now = time(0);
            char* dt = ctime(&now);

            return Block(dt, first_trans);
        }

        Block lastBlock()
        {
            return chain[chain.size() - 1];
        }

        void addBlock(Block newBlock)
        {
            newBlock.prevHash = lastBlock().curHash;
            newBlock.mineBlock(diff);
            chain.push_back(newBlock);
        }

        void minePendingTransactions(string miningRewardAddress)
        {
            cout << "Starting...\n";

            Block block = Block(dt, pendingTransactions);
            block.mineBlock(diff);

            pendingTransactions = {Transactions(NULL, miningRewardAddress, miningReward)};
        }

        bool isValid()
        {
            for (int i = 1; i < int(chain.size()); ++ i)
            {
                Block curBlock = chain[i];
                Block lastBlock = chain[i - 1];

                if (!curBlock.hasValidTransactions()) return false;

                if (curBlock.prevHash != lastBlock.curHash) return false;

                if (curBlock.curHash != curBlock.hashFunc()) return false;
            }

            return true;
        }

        long long getBalance(string address)
        {
            long long balance = 0;

            for (int i = 0; i < int(chain.size()); ++ i)
            {
                Block curBlock = chain[i];
                for (int j = 0; j < int(curBlock.transactions.size()); ++ j)
                {
                    Transactions curTrans = curBlock.transactions[j];

                    long long money = curTrans.amount;

                    if (curTrans.fromAddress == address) balance -= money;
                    if (curTrans.toAddress == address) balance += money;
                }
            }

            return balance;
        }
};