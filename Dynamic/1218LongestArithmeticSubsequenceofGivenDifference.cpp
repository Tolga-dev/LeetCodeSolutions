#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define qii vector<int>
#define qpii queue<pii>
#define umipii unordered_map<int,pii>
#define pqpii priority_queue<pair<int,int>>
#define vd vector<double>
#define vs vector<string>
#define vvs vector<vs>
#define vvi vector<vi>
#define uo_si unordered_set<int>
#define uo_ss unordered_set<string>
#define ll long long
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

int longestSubsequence(vector<int>& arr, int diff) {
    int sz = arr.size();
    vector<int> dp(sz,1);
    int ans = 1;

    unordered_map<int,int> unorder_;

    for (int i = 0; i < sz; ++i) {
        if(unorder_.find(arr[i] - diff) != unorder_.end())
        {
            dp[i] = max(dp[i], 1 + dp[unorder_[arr[i] - diff]]);
            ans = max(ans,dp[i]);
        }
        unorder_[arr[i]] = i;
    }

    return ans;
}

int main() {
    vi arr = {1,2,3,4};
    int difference = 1;

    cout << longestSubsequence(arr,difference) << endl;

    return 0;
}

