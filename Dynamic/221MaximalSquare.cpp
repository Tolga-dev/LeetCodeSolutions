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


int _min(int _a,int _b)
{
    if (_b < _a)
        return _b;
    return _a;
}

int maximalSquare(vector<vector<char>>& matrix) {
    int m=matrix.size(),n=matrix[0].size(),ans=0;
    int dp[m][n];
    for(int i=0;i<n;i++)
    {
        if(matrix[0][i]=='0')
        {
            dp[0][i] = 0;
        }
        else
        {
            dp[0][i] = 1;
            ans = 1;
        }
    }
    for(int i=1;i<m;i++)
    {
        if(matrix[i][0]=='0')
        {
            dp[i][0] = 0;
        }
        else
        {
            dp[i][0] = 1;
            ans = 1;
        }
    }

    for(int i=1;i<m;i++){

        for(int j=1;j<n;j++){

            if(matrix[i][j]=='0')
                dp[i][j]=0;
            else
                dp[i][j]=_min(dp[i-1][j],_min(dp[i][j-1],dp[i-1][j-1])) + 1;

            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}

int main() {
//    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    vector<vector<char>> matrix = {{'0','1'},{'1','0'}};

    cout << maximalSquare(matrix) << endl;

    return 0;
}

/*
 *  int m=matrix.size();
    int n=matrix[0].size();
    int sz=0, pre;
    vector<int> dp(n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int temp=dp[j];
            if(i==0 || j==0 || matrix[i][j]=='0')
                dp[j]=matrix[i][j]-'0';
            else
            {
                dp[j]=min({dp[j], dp[j-1], pre})+1;
            }
            sz=max(sz, dp[j]);
            pre=temp;
        }
    }
    return sz*sz;
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int maxi=0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrix[i-1][j-1] == '1'){
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                maxi = max(maxi, dp[i][j]);
            }
        }
    }
    return maxi*maxi;
 */