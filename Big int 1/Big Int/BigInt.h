#include <iostream>

class BigInt{
    std::string digits;
    void reverse();

    public:
    BigInt();
    BigInt(std::string s);
    BigInt(int x); 
    BigInt(const BigInt &a);
    const BigInt &operator=(const BigInt &a);
 
    BigInt times10toThe(int n); 
    BigInt times(int x);

    friend std::ostream &operator<<(std::ostream &out, const BigInt &a);
    friend BigInt operator+(const BigInt &a, const BigInt &b);
    friend BigInt operator*(const BigInt &a, const BigInt &b);
    friend bool operator<(const BigInt &a,const BigInt &b);
    friend bool operator==(const BigInt &a, const BigInt &b);
    friend bool operator!=(const BigInt &a, const BigInt &b);
    friend bool operator>(const BigInt &a, const BigInt &b);
    friend bool operator>=(const BigInt &a, const BigInt &b);
    friend bool operator<=(const BigInt &a, const BigInt &b);
};
