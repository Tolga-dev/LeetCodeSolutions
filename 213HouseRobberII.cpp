#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/house-robber-ii/
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
static const int ____ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")
int masx(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;
}

int  f1(vector<int>& nums , int n  , int memo[]){
    if(n == 1)
        return nums[1];
    else if(n <= 0)
        return 0;
    if(memo[n] != -1)
        return memo[n];
    return memo[n] = max(nums[n] +  f1(nums , n-2 , memo) , f1(nums , n-1 , memo));
}

int  f2(vector<int>& nums , int n , int memo2[], int size){
    if(n == size)
        return nums[size];
    if(n >= size+1)
        return 0 ;
    if(memo2[n] != -1)
        return memo2[n];
    return memo2[n] =  max( nums[n] +  f2(nums , n+2 , memo2,size) ,  f2(nums , n+1 , memo2,size));
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    else if(n == 2) return max(nums[0],nums[1]);
    int memo[n+1];
    memset(memo,-1,4*n + 4);
    int ans1 =  f1(nums, n - 1, memo);
    memset(memo,-1,4*n + 4);
    return  max( f2(nums, 0, memo,n-2),ans1);
}





int find(vector<int>& nums, const int& k, const int& l, const int& size) {
    if (size <= k + 1)
    {
        return nums[k];
    }
    int prev2 = nums[k];
    int prev = masx(prev2, nums[k + 1]);
    int result = masx(prev, prev2);

    for (int i = k + 2; i < l; ++i) {
        int value = masx(nums[i] + prev2, prev);
        result = masx(result, value);
        prev2 = prev;
        prev = value;
    }
    return result;
}


int rob(vector<int>& nums) {
    int s = nums.size();
    int result = find(nums, 0, s - 1,s);
    if (s == 1)
    {
        return result;
    }
    return masx(result, find(nums, 1, s,s));
}

int main() {

    vi nums = {1,2,3};
    cout << rob(nums) << endl;


    return 0;
}

