#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/greatest-common-divisor-of-strings/

unsigned long x_gcd(unsigned long a, unsigned long b)
{
    return b == 0 ? a : x_gcd(b, a % b);
}

string gcdOfStrings2(string str1, string str2) {
    if(str1 + str2 == str2 + str1)
        return str1.substr(0, x_gcd(str1.size(),str2.size()));
    else
        return "";

}

string gcdOfStrings(string str1, string str2) {

    return (str1 + str2 == str2 + str1)? str1.substr(0, gcd(size(str1),size(str2))): "";
}

int main()
{
    string s = "ABABAB";
    string b = "ABAB";

    cout << gcdOfStrings(s,b) << endl;
    cout << gcdOfStrings2(s,b) << endl;

}

