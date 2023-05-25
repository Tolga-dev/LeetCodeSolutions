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

int m_ax(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;

}
/*
int helper(int i, bool y, vector<int>& pr)
{
    if(i >= pr.size()) return 0;
    int profit = 0;

    if(y)
    {
        profit = m_ax( -pr[i] + helper(i+1,false,pr), helper(i+1,true,pr));
    }
    else
    {
        profit = m_ax( pr[i] + helper(i+2,true,pr), helper(i+1,false,pr));
    }
    return profit;
}
// brute force
int maxProfit1(vector<int>& prices) {
    return helper(0,true,prices);
}
 */

int helper1(int i, bool y, vi& pri, vvi& memo, int size)
{
    if(i >= size) return 0;
    if(memo[i][y] != -1) return memo[i][y];
    int profit = 0;

    if(y)
    {
        profit = m_ax( -pri[i] + helper1(i+1,false,pri,memo,size), helper1(i+1,true,pri,memo,size));
    }
    else
    {
        profit = m_ax( pri[i] + helper1(i+2,true,pri,memo,size), helper1(i+1,false,pri,memo,size));
    }
    return memo[i][y] = profit;
}

// memorization
int maxProfit2(vector<int>& prices) {
    int s= prices.size();
    vvi memo(s,vi(2,-1));
    return helper1(0,true,prices,memo,s);
}
/*

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<2;buy++){
            if(buy){
                dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
            }
            else{

                dp[ind][buy]=max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
            }
        }
    }
    return dp[0][1];

}
*/


int maxProfit3(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>>dp(n+2, vector<int>(2, 0));
    for(int ind=n-1; ind>=0; ind--){
        for(int canBuy=0; canBuy<=1; canBuy++){
            if(canBuy){
                int take=-prices[ind] + dp[ind+1][0];
                int notTake= dp[ind+1][1];
                dp[ind][canBuy]= max(take, notTake);
            }
            else{
                int take = prices[ind] + dp[ind+2][1];
                int notTake= dp[ind+1][0];
                dp[ind][canBuy]= max(take, notTake);
            }
        }
    }
    return dp[0][1];
}


int maxProfit4(vi prices) {
    int n = prices.size();
    if(n<=1)
        return 0;
    vector<int> mem(6,0);
    int buy = -prices[0];
    int sell = 0;
    int cooldown = 0;

    for(int i=1;i<n;i++)
    {
        int pre_buy = buy, pre_sell = sell;
        int pre_cooldown = cooldown;

        buy = max(pre_buy, pre_cooldown-prices[i]);
        sell = max(pre_sell, prices[i]+pre_buy);
        cooldown = max(pre_cooldown,pre_sell);

    }
    return max(sell,cooldown);
}


int maxProfit(vi prices) {
    int n = prices.size();
    if(n<=1)
        return 0;
    int mem[6];

    mem[0] = -prices[0];
    mem[1] = 0;
    mem[2] = 0;

    for(int i=1;i<n;i++)
    {
        mem[3] = mem[0];
        mem[4] = mem[1];
        mem[5] = mem[2];

        mem[0] = m_ax(mem[3], mem[5]-prices[i]);
        mem[1] = m_ax(mem[4], prices[i]+mem[3]);
        mem[2] = m_ax(mem[5],mem[4]);

    }
    return m_ax(mem[1],mem[2]);
}




int main() {
    vi nums = {1,2,3,0,2};
    cout << maxProfit(nums) << endl;

    return 0;
}

