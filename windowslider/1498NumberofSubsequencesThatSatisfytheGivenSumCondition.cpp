//https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

#define vi vector<int>
#define uosi vector<int>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

static vector<int> power_of_2 = {1};
const int mod_div = 1000000007;

static const int _ = []() { for (auto i = 1; i <= (pow(10,5)); ++i)
    power_of_2.push_back((power_of_2.back() << 1) % mod_div); return 0;
}();


int numSubseq_2(vector<int>& nums, int target) {
    int result = 0, left = 0, r = nums.size() - 1;

    sort(begin(nums), end(nums));

    while (left <= r) {
        if(nums[r] + nums[left] <= target){
            result += power_of_2[r-left];
            if(result >= mod_div)
                result -= mod_div;
            ++left;
        }
        else
            --r;
    }

    return result;
}

int main()
{




}