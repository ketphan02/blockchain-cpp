#include <iostream>
#include <cstdio>
#include "libs/picosha2.h"
#include <vector>

#include "elements/chain.h"
#include "elements/transaction.h"

using namespace std;

int main()
{
    Chain PKcoin;
    cout << PKcoin.chain[0].transactions.size();
}