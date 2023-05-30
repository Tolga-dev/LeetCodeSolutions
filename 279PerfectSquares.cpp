#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/perfect-squares/?envType=study-plan-v2&id=dynamic-programming
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define qii vector<int>
#define qpii queue<pii>
#define umipii unordered_map<int,pii>
#define pqpii priority_queue<pair<int,int>>
#define vd vector<double>
#define vs vector<string>
#define vvs vector<vs>
#define uo_si unordered_set<int>
#define uo_ss unordered_set<string>
#define ll long long
static const int ____ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")
int maxx(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;
}
int minx(const int& _a, const int& _b)
{
    if (_a > _b)
        return _b;
    return _a;
}

static vi squs;

static const int ___ = []() {

    for (int i = 1; i*i <= 10000; ++i) {
        squs.push_back(i*i);
    }

    return  0;
}();
//brute

bool p(int x) {
    int r = sqrt(x);
    return (r * r == x);
}

int numSquares1(int n) {
    if (p(n))
        return 1;

    // Check if the number can be expressed as n = (4^a)*(8b + 7)
    while (n % 4 == 0)
        n /= 4;

    if (n % 8 == 7)
        return 4;

    // Check if the number can be expressed as n = a^2 + b^2
    for (int i = 1; i * i <= n; i++) {
        if (p(n - i * i))
            return 2;
    }

    return 3;
}


int main() {

    cout << numSquares1(13) << endl;
    cout << numSquares1(12) << endl;
    cout <<(12 >> 2) << endl;


    return 0;
}

