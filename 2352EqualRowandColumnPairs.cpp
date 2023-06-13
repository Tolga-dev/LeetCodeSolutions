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

int equalPairs(vector<vector<int>>& grid) {
    map<vector<int>,int>hash;
    
    int ret = 0;
    
    int n = grid.size();
    
    for(int i = 0;i<n;i++){
        
        vector<int>arr;
        
        for(int j = 0;j<n;j++){
            
            arr.push_back(grid[i][j]);
            
        }
        
        hash[arr]++;
    }
    
    for(int i = 0;i<n;i++){
        
        vector<int>arr;
        
        for(int j = 0;j<n;j++){
            
            arr.push_back(grid[j][i]);
            
        }
        
        ret+=hash[arr];
        
    }
    return ret;

}

int main() {

    vvi grid = {{3,2,1},{1,7,6},{2,7,7}};
    cout << equalPairs(grid) << endl;

    return 0;
}



