#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/house-robber/description/
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

int rob(vector<int> &nums)
{
    int size_ = nums.size();

    if(size_==1) return nums[0];
    if(size_==2) return max(nums[0],nums[1]);

    int wer = 0, we = nums[0];

    for (int i = 1; i < size_; i++)
    {
        int curr = max(nums[i] + wer, we);
        wer = we;
        we = curr;
    }

    return we;
}


int main() {




    return 0;
}

