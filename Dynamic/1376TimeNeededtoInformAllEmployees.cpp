#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/detonate-the-maximum-bombs/
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
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

void solve(int s,int &ans,int sum,vector<int> &v,vector<vector<int>> &g){
    sum += v[s];
    ans = max(ans,sum);
    for(auto &i: g[s]){
        solve(i,ans,sum,v,g);
    }
}
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& v) {
    vector<vector<int>> g(n);
    int i;
    for(i = 0; i < n; i++){
        if(manager[i] != -1){
            g[manager[i]].push_back(i);
        }
    }
    int ans = 0;
    solve(headID,ans,0,v,g);
    return ans;
}


int main() {


    //   vvi grid ={{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
    vi grid ={2,2,-1,2,2,2};
    vi informTime ={0,0,1,0,0,0};

    cout << numOfMinutes(6,2,grid,informTime) << endl;
    return 0;
}








