#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/house-robber-ii/
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
int masx(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;
}

int memo[101][101];
int solve(int s, int e, vector<int>& cuts, int l, int r){
    if(l > r) return 0;
    if(memo[l][r] != -1) return memo[l][r];
    int ans = 1e9;
    for(int i=l; i<=r; i++){

        ans = min(ans,
                   (e - s)+
                   solve(s, cuts[i], cuts, l, i-1) +
                   solve(cuts[i], e, cuts, i+1, r));
    }

    return memo[l][r] = ans;
}

int minCostS(int n, vector<int>& cuts) {
    memset(memo,-1,sizeof(memo));
    sort(cuts.begin(),cuts.end());
    return solve(0, n, cuts, 0, cuts.size()-1);
}

int memoz[101][101];
int minCost(int n, vector<int>& arr) {
    int size=arr.size();
    sort(arr.begin(), arr.end());
    for(int i=0; i<size; ++i) {
        memoz[i][i]=memoz[size][i]=memoz[i][size]=0;
    }
    for(int i=size-1, j, k, ans, lower; i>=0; --i) {
        for(j=i+1; j<=size; ++j) {
            ans=(j==size? n : arr[j])-(!i? 0 : arr[i-1]);
            lower=ans+memoz[i+1][j];
            for(k=i+1; k<j; ++k) {
                lower=min(lower, ans+memoz[i][k]+memoz[k+1][j]);
            }
            memoz[i][j]=lower;
        }
    }
    return memoz[0][size];
}

int main() {
    int n = 7;
    vi cuts = {1,3,4,5};

    cout << minCost(n,cuts);


    return 0;
}

