#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/count-ways-to-build-good-strings/
#define vi vector<int>
#define uosi vector<int>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")


int solve(int i, vector<int> &nums, vector<int> &memory)
{
    if (i == 0)
        return nums[0];
    if (i < 0)
        return 0;

    if (memory[i] != -1)
        return memory[i];
    return memory[i] = max(nums[i] + solve(i - 2, nums, memory), 0 + solve(i - 1, nums, memory));
}

int rob(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
        return nums[0];

    vector<int> memory(n, -1);

    solve(n - 1, nums, memory);
    return memory[n - 1];
}


int find_max(vector<int>& nums, int i )
{
    if(i < 0) return 0;
    return max(find_max(nums,i-2) + nums[i], find_max(nums,i-1));
}
int rob1(vector<int>& nums) {
    return find_max(nums, nums.size());
}


int rob2(vector<int>& nums) {
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

int main()
{
    vi nums = {1,2,3};

    cout << rob(nums) << endl;

    return 0;
}