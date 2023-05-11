#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/uncrossed-lines/
#define vi vector<int>
#define uosi vector<int>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

// time limit exceed
int recursion1(int i, int j, vector<int>& nums1, vector<int>& nums2)
{
    if(i < 0 && j >= 0) return 0;
    if(j < 0 && i >= 0) return 0;
    if(j < 0 && i < 0) return 0;

    if(nums1[i] == nums2[j])
        return  1 + recursion1(i - 1 , j - 1, nums1,nums2);
    else
        return max(recursion1(i - 1 ,j, nums1,nums2),recursion1(i, j - 1, nums1,nums2));
}

// time limit exceed
int recursion2(int i, int j, vector<int>& nums1, vector<int>& nums2,vector<vector<int>> dp)
{
    if(i < 0 && j >= 0) return 0;
    if(j < 0 && i >= 0) return 0;
    if(j < 0 && i < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(nums1[i] == nums2[j])
        return  dp[i][j] =  1 + recursion2(i - 1 , j - 1, nums1,nums2,dp);
    else
        return dp[i][j] = max(recursion2(i - 1 ,j, nums1,nums2,dp),recursion2(i, j - 1, nums1,nums2,dp));
}

int maxUncrossedLines_1(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> dp(nums1.size(),vector<int> (nums2.size()+1,-1));
    return recursion2(nums1.size()-1,nums2.size()-1,nums1,nums2,dp);
}

// time limit
int recursion(int i, int j, vector<int>& nums1, vector<int>& nums2,vector<vector<int>> dp, int& num1_size,int& num2_size)
{
    if(i == num1_size || j == num2_size) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(nums1[i] == nums2[j])
        return  dp[i][j] =  1 + recursion(i + 1 , j + 1, nums1,nums2,dp,num1_size,num2_size);
    else
        return dp[i][j] = max(recursion(i + 1 ,j, nums1,nums2,dp,num1_size,num2_size)
                             ,recursion(i, j + 1, nums1,nums2,dp,num1_size,num2_size));

}

int maxUncrossedLines_2(vector<int>& nums1, vector<int>& nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    vector<vector<int>>dp(n1, vector<int>(n2, -1));
    return recursion(0, 0,nums1, nums2, dp,n1,n2);
}


int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
{

    int n=nums1.size();
    int m=nums2.size();

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){

        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }

            else if(nums1[i-1]==nums2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }

            else{dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}
        }
    }
    return dp[n][m];
}

int main()
{

    vi nums1 = {2,5,1,2,5}, nums2 = {10,5,2,1,5,2};

    cout << maxUncrossedLines(nums1,nums2) << endl;

    return 0;
}