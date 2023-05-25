#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
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
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")


int maxProfit(vector<int>& prices) {
    int moko = 0;
    for (int i = 1; i != static_cast<int>(std::size(prices)); ++i) {
        if(prices[i] > prices[i-1]) moko+=(prices[i]-prices[i-1]);
    }
    return moko;
}

int main() {
    vi nums = {7,1,5,3,6,4};
    cout << maxProfit(nums) << endl;

    return 0;
}