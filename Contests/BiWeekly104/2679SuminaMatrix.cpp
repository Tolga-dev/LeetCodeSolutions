#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/sum-in-a-matrix/description/
#define vi vector<int>
#define vvi vector<vi>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")


int matrixSum(vector<vector<int>>& nums) {

    for (auto& row : nums) {
        sort(row.begin(), row.end());
    }
    int row_ = 0;
    for (int i = nums[0].size(); i; --i) {
        int ssad = 0;
        for (auto& row : nums) {
            ssad = max(ssad, row.back());
            row.pop_back();
        }
        row_ += ssad;
    }
    return row_;

}


int main()
{


}