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


int helper(int ind, bool buy, vector<int>& pr, int fee, int size, vvi& memo)
{
    if(ind >= size) return 0;
    if(memo[ind][buy] != -1) return memo[ind][buy];

    return buy ?
        memo[ind][buy] = m_ax( -pr[ind] + helper(ind+1,false,pr,fee,size,memo),0+ helper(ind+1,true,pr,fee,size,memo))
    :
        memo[ind][buy] = m_ax( pr[ind] + helper(ind+1,true,pr,fee,size,memo)-fee,0+helper(ind+1,false,pr,fee,size,memo));
}
// memo recursion
int maxProfit1(vector<int>& prices, int fee) {
    int size = prices.size();
    vvi memo(size,vi(2,-1));
    return helper(0, true,prices,fee, size,memo);
}

// basic for
int maxProfit(vector<int>& prices, int fee) {
    int arr[4];
    arr[0] = 0;
    arr[1] = -prices[0];

    for (int i = 0; i < prices.size() ; ++i) {
        arr[0] = max(arr[0], arr[1] + prices[i] - fee);
        arr[1] = max(arr[1], arr[0] - prices[i]);
    }

    return arr[0];
}







int main() {
    vi nums = {1,3,2,8,4,9};
    cout << maxProfit(nums,2) << endl;

    return 0;
}

