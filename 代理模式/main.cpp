#include <iostream>
#include "Gril.h"

using namespace std;

int main()
{
    Gril mm("小娟");
    Proxy pro(mm);
    pro.GiveChocolate();
    pro.GiveDolls();
    pro.GiveFlowers();

    return 0;
}