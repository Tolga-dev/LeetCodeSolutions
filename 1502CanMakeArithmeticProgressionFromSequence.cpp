#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/detonate-the-maximum-bombs/
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


bool canMakeArithmeticProgression1(vector<int>& arr) {

    sort(arr.begin(),arr.end());
    int po = arr[1] - arr[0];

    for (int i = 2; i < arr.size(); ++i) {
        if(arr[i] - arr[i-1] != po)
        {
            return false;
        }
    }

    return true;
}


int main() {

    vi arr = {3,5,1};

}



