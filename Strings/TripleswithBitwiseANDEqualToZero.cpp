#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

int countTriplets0(vector<int>& a) {
    int n = a.size(), ans = 0, c[1 << 16];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++)
        for (int j = a[i]; j > 0; j = (j - 1) & a[i])
            c[j]++;
    for (int i = 1; i < (1 << 16); i++)
        if (__builtin_popcount(i) & 1)
            ans += c[i] * c[i] * c[i];
        else
            ans -= c[i] * c[i] * c[i];
    ans = n * n * n - ans;
    return ans;
}

int countTriplets(vector<int>& nums) {
    vector<int> freq(1<<16,0);
    for (auto a : nums)
        for (auto b : nums)
            freq[a & b]++;

    int cnt = 0;
    for (auto a : nums)
        for (auto mask = 0; mask < (1 << 16); mask++)
            if ((mask & a) == 0)
                cnt += freq[mask];
    return cnt;
}


int main()
{
    vector<int> nums = {2,1,3};

    cout << countTriplets(nums) << endl;



}