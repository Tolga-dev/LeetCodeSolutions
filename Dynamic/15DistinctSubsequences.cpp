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
#define ll long long
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")


int finder(int oi, int pj, string& v, string& b,int v_size, int b_size,vector<vector<ll>> &memo)
{
    if(pj > b_size) return 1;
    if(oi > v_size) return 0;

    if(memo[oi][pj] != -1) return memo[oi][pj];

    if(v[oi-1] == b[pj - 1])
    {
        memo[oi][pj] = finder(oi+1,pj+1,v,b,v_size,b_size,memo) +
                     finder(oi+1,pj,v,b,v_size,b_size,memo);
    }
    else
        memo[oi][pj] = finder(oi+1,pj,v,b,v_size,b_size,memo);

    return memo[oi][pj];
}

int numDistinct1(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<ll>> memo(n+1, vector<ll>(m+1, -1));
    // memo
  //  return finder(1,1,s,t,n,m,memo);

    // memo
    for(int i=0;i<=n;i++)
    {
        memo[i][0] = 1;
    }
    for(int j=1;j<=m;j++)
    {
        memo[0][j] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1] == t[j-1])
            {
                memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
            }
            else
            {
                memo[i][j] = memo[i-1][j];
            }
        }
    }
    return memo[n][m];

}


int helper(int i, int j, char s[], char t[])
{
    if(j<0)
        return 1;

    if(i<0)
        return 0;

    if(s[i] == t[j])
        return helper(i-1,j-1,s,t) + helper(i-1,j,s,t);

    return helper(i-1,j,s,t);
}

int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<double> memo(m+1, 0);

    memo[0] = 1;

    for (int i=1; i<=n; i++)
        for (int j=m; j>=1; j--)
            if (s[i-1] == t[j-1]) memo[j] = memo[j-1] + memo[j];

    return (int)memo[m];
}


int main() {
    string s = "rabbbit", t = "rabbit";

    cout << numDistinct(s,t) << endl;

    return 0;
}


/*
 * int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<double>dp(m+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = m; j > 0; j--) {
                if(s[i-1] == t[j-1]) dp[j] = dp[j-1] + dp[j];
            }
        }
        return dp[m];
    }

 */