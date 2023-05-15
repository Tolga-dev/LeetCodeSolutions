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

// brute force with memorization
int find1(vector<int>& arr, int n, int max)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){

            int take=0;
            // element is included if arr[curr]> arr[prev]
            if(prev==-1 || arr[curr]>arr[prev]){
                take = 1 + dp[curr+1][curr+1];
            }

            // excluding the element
            int notTake = dp[curr+1][prev+1];

            dp[curr][prev+1] = std::max(take, notTake);
        }
    }

    return dp[0][0];
}

int lengthOfLIS1(vector<int>& nums) {

    return find1(nums,nums.size(),1);
}

// brute force
int longestSubsequence_(vector<int>& a, int size)
{
    int dp[size];
    int maxlen = 0;
    for (int i = 0; i < size; i++) {
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i])
                max = std::max(dp[j], max);
        }
        dp[i] = max + 1;
        maxlen = std::max(dp[i], maxlen);
    }
    return maxlen;
}



int CeilIndex(std::vector<int>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}
int LongestIncreasingSubsequenceLength(std::vector<int>& nums)
{
    if (nums.size() == 0)
        return 0;
    int sizes = nums.size();
    std::vector<int> memeory(sizes, 0);
    int length = 1; // always points empty slot in memeory

    memeory[0] = nums[0];
    for (int i = 1; i < sizes; i++) {

        // new smallest numsalue
        if (nums[i] < memeory[0])
            memeory[0] = nums[i];
        else if (nums[i] > memeory[length - 1])
            memeory[length++] = nums[i];

        else
            memeory[CeilIndex(memeory, -1, length - 1, nums[i])] = nums[i];
    }

    return length;
}


int main()
{


    vi A = {10,9,2,5,3,7,101,18};
    cout << LongestIncreasingSubsequenceLength(A) << endl;

    return 0;
}