#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/maximum-subarray/
/*

#pragma GCC target("avx,mmx,sse2,sse3,sse4")
#pragma GCC optimize (-O3, -flto, -ffast-math, -march=native, -mtune=native)

static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
*/

// sol1 time limit, brute force
static int U_max(const int _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;
}

int maxSubArray2(vector<int>& nums) {
    int n = nums.size(); int ans= -__INT_MAX__ - 1;

    for (int i = 0; i < n; ++i) {
        for (int j = i,sums=0; j < n; ++j) {
            sums += nums[j];
            ans = U_max(ans,sums);
        }
    }

    return ans;
}

// sol1 Kadane's algorithm
//https://en.wikipedia.org/wiki/Maximum_subarray_problem
int maxSubArray3(vector<int>& nums, int ans= -__INT_MAX__ - 1,int m = 0) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        m = U_max(nums[i],m + nums[i]);
        ans = U_max(ans,m);
    }

    return ans;
}

// RECURSIVE TIME EXCEED
int solve(vector<int>& nums, int i,int m) {

    if(i >= size(nums)) return m ? 0 : -__INT_MAX__ - 1;

    if(m) return max(0,nums[i] + solve(nums, i+1, 1));

    return max(solve(nums,i+1,0), nums[i] + solve(nums,i+1,1));

}
int maxSubArray5(vector<int>& nums) {

    return solve(nums,0,0);
}




int main()
{
    std::vector<int> k = {-2,1,-3,4,-1,2,1,-5,4};


//    1
//    5,4,-1,7,8
//    cout << maxSubArray(k) << endl;


}