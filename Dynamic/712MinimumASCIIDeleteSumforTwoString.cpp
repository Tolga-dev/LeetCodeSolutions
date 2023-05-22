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


int minimumDeleteSum1(string a, string b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1 , vector<int> (m+1));

    for(int i=1 ; i<=n ; i++)
    {
        dp[i][0] = dp[i-1][0] + a[i-1];
    }

    for(int j=1; j<=m ; j++)
    {
        dp[0][j] = dp[0][j-1] + b[j-1];
    }

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=m ; j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min( dp[i-1][j] + a[i-1] ,
                                dp[i][j-1] + b[j-1] );
        }
    }
    return dp[n][m];
}

int minimumDeleteSum(string word1, string word2) {

    int m = word1.size(), n = word2.size();
    int ops[m+1][n+1];
    ops[0][0] = 0;

    for (int j = 1; j <= n; j++)
    {
        ops[0][j] = ops[0][j-1]+word2[j-1];

    }
    for (int i = 1; i <= m; i++) {
        ops[i][0] = ops[i-1][0]+word1[i-1];

        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1])
            {
                ops[i][j] = ops[i-1][j-1];
            }
            else
            {
                ops[i][j] = min(ops[i-1][j]+word1[i-1], ops[i][j-1]+word2[j-1]);

            }
        }
    }
    return ops[m][n];
}


int main() {
    string w1 = "horse";
    string w2 = "ros";

    cout << minimumDeleteSum(w1,w2) << endl;

    return 0;
}
