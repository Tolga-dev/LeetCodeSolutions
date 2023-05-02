//https://leetcode.com/problems/sliding-subarray-beauty/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    int n = (int)nums.size();
    int fq[51] = {0};
    vi res;

    for(int i = 0, j = 0; i < n; i++) {
        if(nums[i] < 0) fq[abs(nums[i])]++;
        if(i - j + 1 >= k) {
            int checker = 0;
            for(int k = 50; k >= 1; k--) {
                checker += fq[k];
                if(checker >= x) { res.push_back(-k); break;}
            }
            if(checker < x) res.push_back(0);
            if(nums[j] < 0) fq[abs(nums[j])]--;
            j++;
        }
    }
    return res;
}

int main()
{
    vi nums = {1,-1,-3,-2,3};
    int k = 3, x = 2;
    for (auto s: getSubarrayBeauty(nums,k,x)) {
        cout << s <<" ";
    }
}