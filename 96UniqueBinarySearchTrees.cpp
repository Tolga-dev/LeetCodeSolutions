#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
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



int numTrees(int sz) {
    int ans = 1;
    for (int i = 1; i <= sz; ++i) {
        ans *= (sz+i);
        ans /= i;
    }
    return ans/(sz+1);
}

int main() {
    cout << numTrees(19) << endl;

    return 0;
}
