#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/unique-paths/description/


// time limit exceed
int uniquePaths0(int m, int n, int c = 1) {
    if(c){ m--; n--; }
    if(m < 0 || n < 0 ) return 0;
    if(m == 0 || n == 0 ) return 1;

    return uniquePaths0(m-1,n,0) + uniquePaths0(m,n-1,0);
}
// time limit exceed
int dfs(vector<vector<int>> dp, int m, int n, int x,int y)
{
    if(m >= x || n >= y) return 0;
    if(m == x-1 || n == y-1) return 1;
    if(dp[m][n]) return dp[m][n];

    return dp[m][n] = dfs(dp, m+1, n,x,y) + dfs(dp, m, n+1,x,y);
}
int uniquePaths1(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n));

    return dfs(dp,0,0,dp.size(),n);
}

int uniquePaths4(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n,1));

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}


int main()
{
    int m = 3, n = 7;

}