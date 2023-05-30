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

int helper2(vector<int>& coins, int ind, int amount) {
    if (amount == 0) return 1;
    else if (amount < 0) return 0;

    int count = 0;
    for (int i = ind; i < coins.size(); ++i) {
        if (coins[i] <= amount) {
            count += helper2(coins, i, amount - coins[i]);
        }
    }

    return count;
}
//tle
int change1(int amount, vector<int>& coins) {
    return helper2(coins, 0, amount);
}


int helper(vector<int>& coins, int ind, int amount,const int& size, vvi& memo) {
    if (amount == 0) return 1;
    else if (amount < 0) return 0;

    if (memo[ind][amount] != -1) {
        return memo[ind][amount];
    }

    int count = 0;
    for (int i = ind; i < size; ++i) {
        if (coins[i] <= amount) {
            count += helper(coins, i, amount - coins[i],size,memo);
        }
    }
    memo[ind][amount] = count;
    return count;
}
//
int change2(int amount, vector<int>& coins) {
    int size = coins.size();
    vvi memo(size, vi(amount+1,-1));
    return helper(coins, 0, amount,size,memo);
}


int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int j = 0; j < coins.size(); ++j)
        for (int value = coins[j]; value <= amount; ++value)
            dp[value] += dp[value - coins[j]];
    return dp[amount];
}


int main() {

    vi coins = {1,2,5};
    int amount = 5;

    cout << change(amount,coins) << endl;


    return 0;
}

