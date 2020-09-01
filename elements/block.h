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

    public:
        int key;
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
};
