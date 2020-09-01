#include <iostream>
#include <cstdio>
#include <vector>

#include "elements/chain.h"
#include "elements/transaction.h"

#include "libs/picosha2.h"

using namespace std;

int main()
{
    Chain PKcoin;
    cout << PKcoin.chain[0].transactions.size();

}