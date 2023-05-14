#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/maximize-score-after-n-operations/description/
#define vi vector<int>
#define vvi vector<vi>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")


constexpr int MAX = 15;

int d[MAX][MAX], dp[1 << MAX];

int maxScore(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            d[i][j] = gcd(nums[i], nums[j]);
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < (1 << n); ++i) {
        int cnt = __builtin_popcount(i);
        if (cnt & 1) {
            continue;
        }
        for (int p = 0; p < n; ++p) {
            if (!((i >> p) & 1)) {
                continue;
            }
            for (int q = p + 1; q < n; ++q) {
                if (!((i >> q) & 1)) {
                    continue;
                }
                int cur = cnt / 2 * d[p][q];
                dp[i] = max(dp[i], dp[i ^ (1 << p) ^ (1 << q)] + cur);
            }
        }
    }
    return dp[(1 << n) - 1];
}


int main()
{


    vi nums = {3,4,6,8};

    cout << maxScore(nums) << endl;

    return 0;
}