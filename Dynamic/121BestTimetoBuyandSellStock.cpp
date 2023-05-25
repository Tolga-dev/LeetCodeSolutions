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

static int U_max(const int __a, const int& __b)
{
    if (__a < __b)
        return __b;
    return __a;
}
static int U_min(const int __a, const int& __b)
{
    if (__a > __b)
        return __b;
    return __a;
}

int maxProfit2(vector<int>& prices) {
    if (prices.empty())
        return 0 ;
    int minPrice = prices[0];
    int profit = 0;
    for (int i = 1 ; i != static_cast<int>(std::size(prices)); i++)
    {
        minPrice = U_min (minPrice, prices[i]) ;
        profit = U_max (profit, prices[i] - minPrice) ;
    }
    return profit;
}

int pros[2];

int maxProfit(vector<int>& prices) {
    pros[0] = 0;
    pros[1] = prices[0];
    for (int i = 0; i != static_cast<int>(std::size(prices)); i++)
    {
        if (prices[i] - pros[1] > pros[0]) pros[0] = prices[i] - pros[1];
        if (pros[1] > prices[i]) pros[1] = prices[i];
    }
    return pros[0];
}


int main() {
    vi nums = {7,1,5,3,6,4};
    cout << maxProfit(nums) << endl;

    return 0;
}