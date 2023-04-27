#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/


/*
int dp[10][51][51];
int n, m, mod = 1e9+7;
bool valid(vector<string>& pizza, int r, int c) {
    for(int i = r; i < n; i++) {
        for(int j = c; j < m; j++) {
            if(pizza[i][j] == 'A') return true;
        }
    }
    return false;
}
int solution(vector<string>& p, int k, int r, int c) {
    if(r == n or c == m) return 0;
    if(dp[k][r][c] != -1) return dp[k][r][c];
    if(!k) return dp[k][r][c] = valid(p,r,c);

    int nr = r, nc = c;
    bool brk = false;
    for(; nr < n and !brk; nr++) {
        for(int i = c; i < m and !brk; i++) {
            if(p[nr][i] == 'A') brk = true;
        }
    }

    brk = false;
    for(; nc < m and !brk; nc++) {
        for(int i = r; i < n and !brk; i++) {
            if(p[i][nc] == 'A') brk = true;
        }
    }

    dp[k][r][c] = 0;

    for(; nr < n; nr++) {
        dp[k][r][c] = (dp[k][r][c] + solution(p,k-1,nr,c)) % mod;
    }

    for(; nc < m; nc++) {
        dp[k][r][c] = (dp[k][r][c] + solution(p,k-1,r,nc)) % mod;
    }

    return dp[k][r][c];
}
int ways(vector<string>& pizza, int k) {
    memset(dp,-1,sizeof(dp));
    n = pizza.size(), m = pizza[0].size();
    return solution(pizza, k-1, 0,0);
}
*/


int dfs(int m, int n, int k, int r, int c, vector<vector<vector<int>>>& dp, vector<vector<int>>& preSum) {

    if (preSum[r][c] == 0) return 0;
    if (k == 0) return 1;
    if (dp[k][r][c] != -1) return dp[k][r][c];
    int ans = 0;

    for (int nr = r + 1; nr < m; nr++)
        if (preSum[r][c] - preSum[nr][c] > 0)
            ans = (ans + dfs(m, n, k - 1, nr, c, dp, preSum)) % 1000000007;
    for (int nc = c + 1; nc < n; nc++)
        if (preSum[r][c] - preSum[r][nc] > 0)
            ans = (ans + dfs(m, n, k - 1, r, nc, dp, preSum)) % 1000000007;

    return dp[k][r][c] = ans;
}


int ways(vector<string>& pizza, int k) {
    int m = pizza.size(), n = pizza[0].size();
    vector<vector<vector<int>>> dp(vector(k, vector(m, vector(n, -1))));
    vector<vector<int>> preSum(vector(m+1, vector(n+1, 0)));

    for (int r = m - 1; r >= 0; r--)
        for (int c = n - 1; c >= 0; c--)
            preSum[r][c] = preSum[r][c+1] + preSum[r+1][c] - preSum[r+1][c+1] + (pizza[r][c] == 'A');

    return dfs(m, n, k-1, 0, 0, dp, preSum);
}



int main()
{
    vector<string> names = {"AA","AA"};
    int k = 3   ;

    cout << ways(names,k) << endl;

}

