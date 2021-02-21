#include <iostream>
using namespace std;

int main(void)
{
    int p = 4;
    using Rank = int*;
    Rank u = &p;
    cout << *u;
    return 0;
}