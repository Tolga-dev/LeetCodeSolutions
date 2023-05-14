#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/rotate-function/description/
#define vi vector<int>
#define vvi vector<vi>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")


int maxRotateFunction(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    int sum = accumulate(nums.begin(), nums.end(), 0);

    for (int i = 0; i < n; i++) {
        dp[0] += i * nums[i];
    }

    int ans = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = sum + dp[i-1] - n*nums[n-i];
        ans = max(ans, dp[i]);
    }

    return ans;
}

int maxRotateFunction_(vector<int>& array) {
    int n=array.size();

    int ans=0;
    int sum=0;
    for(int i=0;i<array.size();i++){
        ans+=i*array[i];
        sum+=array[i];
    }

    int temp=ans;
    for(int i=n-1;i>=0;i--){
        temp=temp+sum-n*array[i];
        ans=max(ans,temp);
    }
    return ans;
}

int main()
{


    vi nums = {4,3,2,6};

    cout << maxRotateFunction(nums) << endl;

    return 0;
}