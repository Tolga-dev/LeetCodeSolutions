#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/power-of-heroes/description/
#define vi vector<int>
#define vvi vector<vi>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

// tle
int sumOfPower(vector<int>& nums) {
    int n = nums.size();
    const int MOD = 1e9 + 7;
    int result = 0; // use long long to avoid overflow

    sort(nums.begin(),nums.end());
    if(nums[0] == nums[n-1])
    {
        int m = pow(2,n) - 1;
        return (int(pow(nums[0],3))%MOD)* m % MOD;
    }

    for (int i = 1; i < pow(2, n); i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (int)pow(2, j)) {
                subset.push_back(nums[j]);
            }
        }
        result += int(int(pow(subset[subset.size()-1],2))% MOD*subset[0])% MOD;
    }

    return result;

}

int sumOfPower(vector<int>& nums) {
    long long div = 1e9 + 7, ous = 0, ans = 0;
    sort(nums.begin(), nums.end());
    for (long long x: nums) {
        ans = (ans + (x * x % div) * x % div + (x * x % div) * ous % div) % div;
        ous = (ous * 2 + x) % div;
    }
    return ans;
}

int main()
{
    vi nums = {8,1,2};
    int k = 2;
    vector<vi> nums2 = {{7,2,1},{6,4,2},{6,5,3},{3,2,1}};

    vector<string> pass = { "7868190130M7522","5303914400F9211","9273338290F4010"};
//    cout << maximumOr(nums,k) << endl;
//    cout << (24 | 9) << endl;

    return 0;
}