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


int helper1(int index, int onBuy, int maxTrans, vi& prices, vvi& memo, int size)
{
    if(index == size || maxTrans == 0) return 0;
    if(memo[index][onBuy] == -1) return memo[index][onBuy];

    if(onBuy)
    {
        return memo[index][onBuy] = max(-prices[index] + helper1(index+1,0,maxTrans,prices,memo,size),
                   helper1(index+1,1,maxTrans,prices,memo,size)
                   );
    }
    else
    {
        return memo[index][onBuy] =  max(prices[index] + helper1(index+1,1,maxTrans-1,prices,memo,size),
                   helper1(index+1,0,maxTrans,prices,memo,size)
        );
    }

}
// tle
int maxProfit1(int k, vector<int>& prices) {
    int pricecs_size = prices.size();
    vvi memo(pricecs_size,vi(2,0));
    return helper1(0,1,k,prices,memo,pricecs_size);
}


int helper(int m,int onB,int sz,vector<int>& prm,vector<vector<vector<int>>>&memo, int size){
    if(sz==0)return 0;
    if(m == size)return 0;
    if(memo[m][onB][sz]!=-1)return memo[m][onB][sz];
    if(onB) return  memo[m][onB][sz]=max(-prm[m]+helper(m+1,0,sz,prm,memo,size),helper(m+1,1,sz,prm,memo,size));
    else return memo[m][onB][sz]=max(prm[m]+helper(m+1,1,sz-1,prm,memo,size),helper(m+1,0,sz,prm,memo,size));
}
int maxProfit(int k,vector<int>& prices) {
    int s = prices.size();
    vector<vector<vector<int>>>memo(s,vector<vector<int>>(2,vector<int>(k+1,-1)));
    return helper(0,1,k,prices,memo,s);
}


int main() {
    vi nums = {3,2,6,5,0,3};
    cout << maxProfit(2,nums) << endl;

    return 0;
}
