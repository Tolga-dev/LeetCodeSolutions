#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/combination-sum-iv/description/
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

int countNegatives(vector<vector<int>>& grid) {
    int n = grid[0].size();
    int l = 0, r = n-1, md = 0, ans = 0, rn= 0;
    for (auto & i : grid) {
        if(i[0] < 0)
        {
            rn += n;
            continue;
        }

        while (l <= r) {
            md = (l + r) / 2;
            if (i[md] < 0) {
                ans = n - md;
                r = md - 1;
            } else {
                l = md + 1;
            }
        }
        l = 0;
        r = n - 1;
        rn += ans;
        ans = 0;
    }
    return rn;
}


int main() {

    vvi grid = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};

    cout << countNegatives(grid)<< endl;
}



