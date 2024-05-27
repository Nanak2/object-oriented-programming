#include <iostream>
#include "bigint.h"
using namespace std;

int main()
{
    BigInt x("123456789012345");
    BigInt y(2);

    y.times10toThe(8);
    cout << "y = " << y << "\n";

    x.times(2); 
    cout << "x = " << x << "\n";
    
    cout << "x + y = " << (x+y) << "\n";
    cout << "x * y = " << (x*y) << "\n";
    
    cout << (x < y ? "x < y\n" : "x >= y\n");
    cout << (x == y ? "x == y\n" : "x != y\n");
}