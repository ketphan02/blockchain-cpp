#pragma once

#include <string.h>
#include <string>
#include "../libs/picosha2.h"

using namespace std;

class Transactions
{

    private:

        string hash_str, hex_str;
        
        string data = "";

    public:

        string toAddress, fromAddress;
        long long amount;

        Transactions(string to, string from, long long am)
        {
            toAddress = to;
            fromAddress = from;
            amount = am;
        }

        string hashFunc()
        {
            hash_str = toAddress + fromAddress + to_string(amount);
            picosha2::hash256_hex_string(hash_str, hex_str);
            return hex_str;
        }

        string toString()
        {
            data += "{\n";
            data += "'toAddress': " + toAddress + '\n';
            data += "'fromAddress': " + fromAddress + '\n';
            data += "'amount': " + to_string(amount) + '\n';
            data += '}';
            
            return data;
        }

        bool isValid()
        {
            if (fromAddress == NULL) return true;
        }
};