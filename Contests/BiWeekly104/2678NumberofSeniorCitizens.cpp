#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/number-of-senior-citizens/
#define vi vector<int>
#define vvi vector<vi>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

int countSeniors1(vector<string>& details) {
    int count = 0;
    for (std::string& passenger_info : details) {
        std::string age_str = passenger_info.substr(11, 2);
        int age = std::stoi(age_str);
        if (age > 60) {
            count++;
        }
    }
    return count;
}

int countSeniors(vector<string>& details) {
    int solution = 0;
    for (auto &s: details) {
        if((s[11] - '0') * 10 + (s[12] - '0') > 60)
        {
            solution++;
        }
    }
    return solution;
}

int main()
{

    vector<string> pass = { "7868190130M7522","5303914400F9211","9273338290F4010"};
    cout << countSeniors(pass) << endl;

    return 0;
}