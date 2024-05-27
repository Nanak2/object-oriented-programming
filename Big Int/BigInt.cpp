#include <iostream>
#include <string>
#include <assert.h>
#include "BigInt.h"
using namespace std;

BigInt::BigInt(){
    digits = "0";
}

BigInt::BigInt(string s){
    string a;
    for(int i = (s.length() - 1); i >= 0; i--){
        a += s[i];
    }
    digits = a;
}

BigInt::BigInt(int x){
    string a;
    string b = to_string(x);
    for(int i = b.length() - 1; i >= 0; i--){
        a += b[i];
    }
    digits = a;
}

BigInt::BigInt(const BigInt &a){
    digits = a.digits;
}

const BigInt &BigInt::operator=(const BigInt &a){
    if(&a != this){
        digits = a.digits;
    }
    return *this;
}
BigInt BigInt::times10toThe(int n){
    while(n > 0){
        digits = "0" + digits;
        n--;
    }
    return *this;
} 

BigInt BigInt::times(int x){
    int carry = 0;
    for(int i = 0; i < (int)digits.length(); i++){
        int prod = (int)(digits[i] - '0') * x + carry;
        digits[i] = (prod % 10) + '0';
        carry = prod / 10;
    }
    if(carry > 0)
        digits += to_string(carry);
    return *this;
}

BigInt operator+(const BigInt &a, const BigInt &b){
    BigInt c("");
    int carry = 0;
    int pos;
    int diff = 0;
    int x = (a.digits).length();
    int y = (b.digits).length();
    BigInt longs;

    if(x == y){
        pos = x;
    }
    else{
        pos = (x < y ? x : y);
        diff = (x > y ? (x - y) : (y - x));
        longs = (a > b ? a : b);
    }
    for(int i = 0; i < pos; i++){
        int nums = (a.digits[i] - '0') + (b.digits[i] - '0') + carry;
        c.digits += to_string(nums % 10);
        carry = nums / 10;
    }
    if(diff != 0 || carry > 0){
        for(int i = pos; i < (pos + diff); i++){
            int xs = (longs.digits[i] - '0') + carry;
            c.digits += to_string(xs % 10);
            carry = xs / 10;
        }
    }
    if(carry > 0){
        c.digits += to_string(carry);
    }
    return c;
}

ostream &operator<<(std::ostream &out, const BigInt &a){
    for(int i = (int)a.digits.length() - 1; i >= 0; i--){
        if((i + 1) % 3 == 1 && i != 0){
            out << a.digits[i] << ",";
        }
        else{
            out << a.digits[i];
        }
    }
    return out;
}

BigInt operator*(const BigInt &a, const BigInt &b){
    BigInt result("");
    int carry = 0;
    BigInt longs = a;
    BigInt shorts = b;
    if((a.digits).length() != (b.digits).length()){
        longs = (a > b ? a : b);
        shorts = (a < b ? a : b);
    }
    for(int i = 0; i < (int)(shorts.digits).length(); i++){
        BigInt c("");
        for(int j = 0; j < (int)(longs.digits).length(); j++){
            int pod = (longs.digits[j] - '0') * (shorts.digits[i] - '0') + carry;
            c.digits += to_string(pod % 10);
            carry = pod / 10;
        }
        if(carry > 0){
            c.digits += to_string(carry);
        } 
        carry = 0;
        c.times10toThe(i);
        result = result + c;
    }
    return result;
}

bool operator<(const BigInt &a, const BigInt &b){
    if(a == b){
        return false;
    }
    else if (a.digits.length() < b.digits.length()){
        return true;
    }
    if(a.digits.length() > b.digits.length()){
        return false;
    }
    else{
        for(int i = a.digits.length() - 1; i >= 0; i--){
            if(a.digits[i] < b.digits[i]){
                return true;
            }
            if(a.digits[i] > b.digits[i]){
                return false;
            }
        }
    }
    return false;
}

bool operator<=(const BigInt &a, const BigInt &b){
    return (a == b || a < b);
}

bool operator>=(const BigInt &a, const BigInt &b){
    return (b <= a || a == b);
}

bool operator>(const BigInt &a, const BigInt &b){
    return (b < a);
}


bool operator==(const BigInt &a, const BigInt &b){
    return (a.digits == b.digits);
}

bool operator!=(const BigInt &a, const BigInt &b){
    return (a.digits != b.digits);
}