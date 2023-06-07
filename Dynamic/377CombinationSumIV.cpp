#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/combination-sum-iv/description/
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

int finder(int target,vi&memo,vi& nums, const int& size)
{
    if(target<0)
    {
        return 0;
    }
    if(target==0)
    {
        return 1;
    }
    if(memo[target]!=-1)
    {
        return memo[target];
    }

    int c=0;
    for (int i = 0; i < size; ++i) {
        c = c + finder(target-nums[i],memo,nums,size);
    }
    return memo[target]=c;
}

int combinationSum41(vi& nums, int target) {

    vi memo(target+1,-1);
    return finder(target,memo,nums,nums.size());
}


int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1);
    dp[0]=1;
    for(int i=1;i<=target;i++)
        for(int& num:nums)
        {
            if(num<=i&& dp[i - num] < INT_MAX -dp[i])
                dp[i]+=dp[i-num];
        }
    return dp[target];
}



int main() {

    vi cand = {1,2,3};
    int t = 4;

    cout << combinationSum4(cand,t) << endl;
}



