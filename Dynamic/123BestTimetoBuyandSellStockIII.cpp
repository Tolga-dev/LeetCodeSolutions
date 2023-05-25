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
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

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
int pros[4];
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        pros[0] = INT_MAX, pros[1] = INT_MAX;
        pros[2] = 0, pros[3] = 0;

        for (int i = 0; i != static_cast<int>(std::size(prices)); i++) {
            pros[0] = U_min(pros[0], prices[i]);
            pros[2] = U_max(pros[2], prices[i] - pros[0]);
            pros[1] = U_min(pros[1], prices[i] - pros[2]);
            pros[3] = U_max(pros[3], prices[i] - pros[1]);
        }
        return pros[3];
    }
};


int maxProfit_2(vector<int>& prices) {
    int n1 = INT_MAX, n2 = INT_MAX;
    int v1 = 0, v2 = 0;

    for (int i = 0; i != static_cast<int>(std::size(prices)); i++) {
        n1 = std::min(n1, prices[i]);
        v1 = std::max(v1, prices[i] - n1);
        n2 = std::min(n2, prices[i] - v1);
        v2 = std::max(v2, prices[i] - n2);
    }
    return v2;

}


// brute force, recursion
int helper1(int index, int onBuy, int maxTransaction, vi& prices)
{
    if(index == prices.size() || maxTransaction == 0) return 0;

    if(onBuy)
    {
        return max(-1*prices[index] + helper1(index+1,0,maxTransaction,prices),
                   helper1(index+1,1,maxTransaction,prices)
        );
    }
    else
    {
        return max(prices[index] + helper1(index+1,1,maxTransaction-1,prices),
                   helper1(index+1,0,maxTransaction,prices)
                   );
    }

}

int maxProfit_1(vector<int>& prices) {
    return helper1(0,1,2,prices);
}


int helper(int index, int onBuy, int maxTransaction, vi& prices, vvi& memo)
{
    if(index == prices.size() || maxTransaction == 0) return 0;
    if(memo[index][onBuy] == -1) return memo[index][onBuy];
    if(onBuy)
    {
        return memo[index][onBuy]= max(-1*prices[index] + helper(index+1,0,maxTransaction,prices,memo),
                   helper(index+1,1,maxTransaction,prices,memo)
        );
    }
    else
    {
        return memo[index][onBuy] = max(prices[index] + helper(index+1,1,maxTransaction-1,prices,memo),
                   helper(index+1,0,maxTransaction,prices,memo)
        );
    }

}


int maxProfit(vector<int>& prices) {
    vvi memo(prices.size(),vi(2,0));
    return helper(0,1,2,prices,memo);
}


int main() {
    vi nums = {3,3,5,0,0,3,1,4};
    cout << maxProfit(nums) << endl;

    return 0;
}