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

// finding max subsequence
int MaxSubsExample(vector<int>& arr) {
    int size = arr.size();
    vector<int> lis(size,1);

    cout << lis[0] << endl;
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        cout << lis[i] << endl;
    }

    return 0;
}

int findNumberOfLIS(vector<int>& nums) {

    int len = nums.size();
    vector<int> dp(len,1);
    vector<int> cnt(len,0);

    int ret = 0, max = 1;
    for (int i = 0; i < len; i++) {
        int count = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (1 + dp[j] > dp[i]) {
                    count = cnt[j];
                    dp[i] = 1 + dp[j];
                } else if (1 + dp[j] == dp[i]) {
                    count += cnt[j];
                }
            }
        }
        cnt[i] = count;

        if (dp[i] > max) {
            ret = count;
            max = dp[i];
        } else if (dp[i] == max) {
            ret += count;
        }
    }
    return ret;
}
int main() {

    vi arr = { 1,3,5,4,7};
    cout << findNumberOfLIS(arr) << endl;

    return 0;
}

