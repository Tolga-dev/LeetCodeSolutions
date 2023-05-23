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

int longestArithSeqLength1(vector<int>& nums) {
    int size = nums.size();
    int ans = 0;

    vector<unordered_map<int, int>> dp(size);


    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            int diff = nums[i] - nums[j];

            if(dp[j].count(diff) != 0)
            {
                dp[i][diff] = dp[j][diff] + 1;

            }
            else
                dp[i][diff] = 2;
            ans = max(ans,dp[i][diff]);
        }

    }

    return ans;
}


int longestArithSeqLength(vector<int>& nums) {
    int n=nums.size();
    int dp[n][1001];
    memset(dp,0,sizeof(dp));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int diff=nums[i]-nums[j]+500;
            dp[i][diff]=dp[j][diff]+1;
            ans=max(ans,dp[i][diff]);
        }
    }
    return ans+1;
}



int main() {
//    vi arr = {3,6,9,12,1,2,3};
    vi arr = {9,4,7,2,10};

    cout << longestArithSeqLength(arr) << endl;

    return 0;
}

