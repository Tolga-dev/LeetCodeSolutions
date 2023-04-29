//https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/
#include <bits/stdc++.h>
using namespace std;

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

int maximizesSum(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int max = nums[nums.size() - 1];
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += max;
        max += 1;
    }
    return sum;
}

int maximizeSum(vector<int>& nums, int k) {
    const int m = *max_element(nums.begin(), nums.end());
    return (m + m + k - 1) * k / 2;
    /*
 *         int m=*max_element(nums.begin(),nums.end());
        return (m+m+k-1)*k>>1;
     */
}


int main()
{
    vector<int> grid1 = {1,2,3,4,5};

    cout << maximizeSum(grid1,3) << endl;

}