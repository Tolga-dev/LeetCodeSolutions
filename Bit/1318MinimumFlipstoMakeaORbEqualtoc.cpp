#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vb vector<bool>
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

int minx(const int& _a, const int& _b)
{
    if (_a > _b)
        return _b;
    return _a;
}

int maxx(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;
}

int minFlips(int f, int s, int t)
{
    int r = 0;
    while (f || s || t)
    {
        if (t & 1)
        {
            if ((f & 1) == 0 && (s & 1) == 0)
            {
                r++;
            }
        }
        else
        {
            if (f & 1)
                r++;
            if (s & 1)
                r++;
        }
        f >>= 1, s >>= 1, t >>= 1;
    }
    return r;
}

int main() {

    cout << minFlips(2,6,5) << endl;

}



