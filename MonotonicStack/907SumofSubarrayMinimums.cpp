#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/sum-of-subarray-minimums/
#define vi vector<int>
#define vvi vector<vi>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

const int MOD = 1e9 + 7;
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> prevSmaller(n, -1);  // store index of previous smaller element
    vector<int> nextSmaller(n, n);   // store index of next smaller element
    int i = 0;
    stack<int> st;  // monotonic stack
    for (; i < n; i++) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            nextSmaller[st.top()] = i;
            st.pop();
        }
        if (!st.empty())
            prevSmaller[i] = st.top();
        st.push(i);
    }
    i = 0;
    long long result = 0;
    for (; i < n; i++) {
        result = (result + arr[i] * ((i - prevSmaller[i]) * (nextSmaller[i] - i)) % MOD) % MOD;
    }

    return result;
}

int main() {
    vector<int> arr = {11,81,94,43,3};
    int result = sumSubarrayMins(arr);
    cout << result << endl;

    return 0;
}