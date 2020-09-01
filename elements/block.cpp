#include <string.h>
#include <string>
#include "../libs/picosha2.h"
#include <vector>

using namespace std;

class Block
{
    private:

        // something

    public:
        int key;
        string time, data, prevHash, curHash;

        string hash_str, hex_str;


        Block(string t, string d, string pH = "")
        {
            key = 0;
            time = t;
            data = d;
            prevHash = pH;
            curHash = hashFunc();
        }

        string hashFunc()
        {
            hash_str = time + data + prevHash + to_string(key);
            picosha2::hash256_hex_string(hash_str, hex_str);
            return hex_str;
        }
};
