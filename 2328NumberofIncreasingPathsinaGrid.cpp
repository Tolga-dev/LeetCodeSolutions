#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
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

int mod = 1e9+7;
int f(int i, int j, int prev, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i<0 || j<0 || i>= grid.size() || j>= grid[0].size() || prev>= grid[i][j])
        return 0;

    if(dp[i][j] != -1) return dp[i][j];

    long long cnt = 1;

    cnt += f(i+1, j, grid[i][j], grid, dp)% mod;
    cnt += f(i-1, j, grid[i][j], grid, dp) % mod;
    cnt += f(i, j+1, grid[i][j], grid, dp) % mod;
    cnt += f(i, j-1,  grid[i][j], grid, dp) % mod;

    return dp[i][j] = cnt;
}

int countPaths(vector<vector<int>>& grid) {
    long long cnt = 0, n= grid.size(), m= grid[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1)); //dp table

    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            cnt += f(i, j, -1, grid, dp);
        }
    }

    return cnt%mod;
}

int main(int argc, const char* argv[]) {

    vvi grid = {{1,1},{3,4}};
    cout << countPaths(grid) << endl;

    return argc;
}



