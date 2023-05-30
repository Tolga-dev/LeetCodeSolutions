#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/perfect-squares/?envType=study-plan-v2&id=dynamic-programming
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
int maxx(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;
}
int minx(const int& _a, const int& _b)
{
    if (_a > _b)
        return _b;
    return _a;
}

int helper(vector<int>& c, int j, vector<int> &memo,const int & size){
    if(j==0)
        return 0;
    if(j<0)
        return INT_MAX;
    if(memo[j]!=-1)
        return memo[j];
    int ret=INT_MAX;
    for(int i=0;i<size;i++){
        int ans=helper(c,j-c[i], memo,size);
        if(ans!=INT_MAX)
            ret=min(ret,ans+1);
    }
    memo[j]=ret;
    return ret;
}
int coinChange1(vector<int>& c, int am) {
    vector<int> memo(am+1,-1);

    int ans=helper(c,am, memo,c.size());
    if(ans==INT_MAX)    return -1;
    return ans;
}

int memo[10001];
int helper(vector<int>& c, int ret){
    if(ret==0) return 0;
    if(memo[ret]!=-1){
        return memo[ret];
    int ans = 1e9;
    for(auto i:c){
        if(ret>=i)
            ans = minx(ans,helper(c,ret-i)+1);
    }
    memo[ret] = ans;
    return ans;
}

int coinChange(vector<int>& c, int am) {
    memset(memo,-1,sizeof(memo));
    int ans = helper(c, am);
    if(ans >= 1e9){
        return -1;
    }
    return ans;
}

int main() {

    vi coins = {1,2,5};
    int amount = 11;

    cout << coinChange(coins,amount) << endl;


    return 0;
}

