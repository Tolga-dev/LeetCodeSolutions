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


vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    int n = obstacles.size();
    int len = 0;
    vi answer_arr(n);
    vi sub_array(n);
    for (int i = 0; i < n; ++i) {
        int l = 0, r = len;
        while(l < r)
        {
            int mid = ( l + r ) / 2;
            if(sub_array[mid] <= obstacles[i])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        answer_arr[i] = l +1;
        if(l == len)
            len++;
        sub_array[l] = obstacles[i];
    }
    return obstacles;
}

int main()
{


    vector<int> nums = {3,1,5,6,4,2};


    for (auto s:longestObstacleCourseAtEachPosition(nums)) {
        cout << s<< " " ;
    }


}