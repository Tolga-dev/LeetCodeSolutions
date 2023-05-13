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
long long maximum4Or(vector<int>& nums, int k) {
    int n=nums.size(),i;
    long long ans=0;

    vector<int> a(n),b(n);

    a[0] = nums[0];
    for(i=1;i<n;i++)
        a[i]=a[i-1]|nums[i];

    b[n-1] = nums[n-1];
    for(i=n-2; i>=0 ;i--)
        b[i]=b[i+1]|nums[i];

    for (auto s: a) {
        cout << s << " ";
    }
    cout << endl;
    for (auto s: b) {
        cout << s << " ";
    }
    cout << endl;
    cout << " ----------------" <<endl;

    long maxOr = 0;
    for (int i = 0; i < n; i++) {
        cout << ((long) nums[i]) * (1L << k) << " "
             <<  (i > 0 ?a[i-1] : 0) << " " << (i < n-1 ? b[i+1] : 0) << endl;
        long Or = ((long) nums[i]) * (1L << k) | (i > 0 ?a[i-1] : 0) | (i < n-1 ? b[i+1] : 0);

        maxOr = max(maxOr, Or);
    }
    return maxOr;

}



int main()
{
    vi nums = {8,1,2};
    int k = 2;
    vector<vi> nums2 = {{7,2,1},{6,4,2},{6,5,3},{3,2,1}};

    vector<string> pass = { "7868190130M7522","5303914400F9211","9273338290F4010"};
//    cout << maximumOr(nums,k) << endl;
    cout << maximum4Or(nums,k) << endl;
//    cout << (24 | 9) << endl;

    return 0;
}