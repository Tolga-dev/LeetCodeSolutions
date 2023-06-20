#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/k-radius-subarray-averages/description/
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vb vector<bool>
#define qii vector<int>
#define qpii queue<pii>
#define umipii unordered_map<int,pii>
#define pqpii priority_queue<pair<int,int>>
#define vd vector<double>
#define vs vector<string>
#define vvs vector<vs>
#define uo_si unordered_set<int>
#define uo_ss unordered_set<string>
#define ll long long
static const int ____ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

int minx(const int& _a, const int& _b)
{
    if (_a > _b)
        return _b;
    return _a;
}

int maxx(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;
}

vector<int> getAverages1(vector<int>& nums, int k) {
    if(k==0) return nums;

    int n=nums.size();

    vector<int> ans(n,-1);

    if(k>n/2) return ans;

    vector<ll> prefix(n,0);

    prefix[0]=nums[0];

    for(int i=1;i<n;i++)
    {
        prefix[i] = prefix[i-1] + nums[i];
    }

    int divisor=2*k+1;
    long sum=0;

    for(int i=k;i<n-k;i++){
        ans[i]=(prefix[i+k]-sum)/divisor;
        sum+=nums[i-k];
    }

    return ans;

}

vector<int> getAverages(vector<int>& arr, int ind) {
    std::vector<int> ret(arr.size(), -1);
    if (arr.size() <= 2 * ind) {
        return ret;
    }

    double get = 0;
    for (auto i = 0; i < 2 * ind; i++) {
        get += arr[i];
    }

    size_t left = 0,right = 2 * ind,n = right + 1;
    for (auto i = ind; i < arr.size()-ind; i++, left++, right++) {
        get += arr[right];
        ret[i] = static_cast<int>(get / n);
        get -= arr[left];
    }
    return ret;
}

int main(int argc, const char* argv[]) {

    vi  gain = {7,4,3,9,1,8,5,2,6};

    for (auto to: getAverages(gain,3)) {
        cout << to << " ";
    }

    return argc;
}



