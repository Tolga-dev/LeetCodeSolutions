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

int divider = 1e9 + 7;
int finder(int i, int j, int prev, vvi& map, vvi& memo)
{
    if(i<0 || j<0 || i>= map.size() || j>= map[0].size() || prev>= map[i][j])
        return 0;

    if(memo[i][j] != -1) return memo[i][j];

    long long ans = 1;

    ans += finder(i+1, j, map[i][j], map, memo)% divider;
    ans += finder(i-1, j, map[i][j], map, memo) % divider;
    ans += finder(i, j+1, map[i][j], map, memo) % divider;
    ans += finder(i, j-1,  map[i][j], map, memo) % divider;

    return memo[i][j] = ans;

}

void print(vvi memo)
{
    for (auto m : memo) {
        for (auto n : m) {
            cout << n << " ";
        }
        cout << endl;
    }

}

int countPaths(vector<vector<int>>& map) {
    ll ans = 0, n = map.size(), m = map[0].size();
    vvi memo(n,vi(m,-1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            print(memo);
            ans += finder(i,j,-1,map,memo);
            print(memo);
        }
    }
    return ans%divider;
}

int main(int argc, const char* argv[]) {

    vvi grid = {{1,1},{3,4}};
    cout << countPaths(grid) << endl;

    return argc;
}



