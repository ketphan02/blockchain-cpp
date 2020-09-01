#pragma once

#include <string.h>
#include <string>
#include <vector>

#include "../libs/picosha2.h"
#include "transaction.h"

using namespace std;

class Block
{
    private:

        string hash_str, hex_str;

        string trans_string = "";

        string standard_0 = "";

    public:
        long long key;
        string time, prevHash, curHash;
        vector<Transactions> transactions;

        Block(string t, vector<Transactions> trans, string pH = "")
        {
            key = 0;
            time = t;
            transactions = trans;
            prevHash = pH;
            curHash = hashFunc();
        }

        string hashFunc()
        {
            for (int i = 0; i < int(transactions.size()); ++ i)
            {
                trans_string += transactions[i].toString();
            }

            hash_str = time + trans_string + prevHash + to_string(key);
            picosha2::hash256_hex_string(hash_str, hex_str);
            return hex_str;
        }

        void mineBlock(long long diff)
        {
            for (int i = 0; i < diff; ++ i) standard_0 += '0';

            while (curHash != standard_0)
            {
                ++key;
                curHash = hashFunc();
            }

            cout << curHash << '\n';
        }

        bool hasValidTransactions()
        {
            for (int i = 0; i < int(transactions.size()); ++ i)
            {
                if (!transactions[i].isValid()) return false;
            }
            return true;
        }
};
