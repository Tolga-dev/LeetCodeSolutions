#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/
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

int largestAltitude(vector<int>& gain) {
    int ans =0,temp = 0;

    for (int i = 0; i < gain.size(); ++i) {
        temp = temp + gain[i];
        if(ans < temp) ans = temp;

    }

    return ans;
}


int main(int argc, const char* argv[]) {

    vi  gain = {-5,1,5,0,-7};

    cout << largestAltitude(gain) << endl;

    return argc;
}



