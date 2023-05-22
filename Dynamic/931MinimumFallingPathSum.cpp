#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=study-plan-v2&id=dynamic-programming
#define vi vector<int>
#define pii pair<int,int>
#define qii vector<int>
#define qpii queue<pii>
#define umipii unordered_map<int,pii>
#define pqpii priority_queue<pair<int,int>>
#define vd vector<double>
#define vs vector<string>
#define vvs vector<vs>
#define vvi vector<vi>
#define uo_si unordered_set<int>
#define uo_ss unordered_set<string>

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

int find(int r, int c, vvi &gp,vvi &memo , int size)
{
    if(c<0 || c>size-1) return 1E9;
    if(r==0) return gp[r][c];
    if(memo[r][c] != -1) return memo[r][c];

    int up = gp[r][c] + find(r-1,c,gp,memo,size);
    int ld = gp[r][c] + find(r-1,c-1,gp,memo,size);
    int rd = gp[r][c] + find(r-1,c+1,gp,memo,size);
    
    return memo[r][c] = min(up,min(ld,rd));

}
int minFallingPathSum1(vvi& gp) {
    int rt = INT_MAX;
    int n = gp.size();
    vvi memo(n,vi(n,-1));

    for(int i=0;i<n;i++)
    {
        rt = min(rt,find(n-1,i,gp,memo,n));
    }
    return rt;
}


vector<vector<int>> stor;

int dfs(int r, int c, vector<vector<int>>& gp,int size){
    if(r == size-1)
        return gp[r][c];

    if(stor[r][c] != -1)
        return stor[r][c];

    int ans = dfs(r+1, c, gp,size);
    if(c > 0)
        ans = min(ans, dfs(r+1, c-1, gp,size));
    if(c < gp[0].size()-1)
        ans = min(ans, dfs(r+1, c+1, gp,size));

    stor[r][c] = ans + gp[r][c];
    return stor[r][c];
}

int minFallingPathSum(vector<vector<int>>& gp) {
    int minSum = INT_MAX;

    int size = gp.size();
    stor = vector<vector<int>>(size, vector<int>(size, -1));

    for(int i = 0; i<size; i++){
        minSum = min(minSum, dfs(0, i, gp,size));
    }

    return minSum;
}


int main() {
    vvi matrix = {{2,1,3},{6,5,4},{7,8,9}};

    cout << minFallingPathSum(matrix) << endl;
    return 0;
}

