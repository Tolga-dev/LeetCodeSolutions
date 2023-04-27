#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
//https://leetcode.com/problems/longest-palindromic-subsequence/

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
int dp[1001][1001];
int n;

int f(string& s, int o, int p)
{
    if (o == 0 || p == 0) return 0;
    if (dp[o][p] != -1) return dp[o][p];

    if(s[o-1] == s[n-p]) return dp[o][p] = 1 + f(s, o - 1, p - 1);
    else return dp[o][p] = max(f(s, o - 1, p),f(s, o, p - 1));
}
int longestPalindromeSubseq0(string s) {
    n = s.size();
    dp[n][n];
    memset(dp, -1, sizeof(dp));

    return f(s,n,n);
}

int longestPalindromeSubseq140(string s) {
    n = s.size();
    dp[n][n];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int j, cl=2; cl <= n; cl++)
    {
        for (int i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (s[i] == s[j] && cl == 2)
                dp[i][j] = 2;
            else if (s[i] == s[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
        }
    }


    return dp[0][n-1];

}
int longestPalindromeSubseq(string s) {
    n = s.size();
    dp[n][n];
    memset(dp, -1, sizeof(dp));

    for (int i = n-1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i+1; j < n; ++j) {
            if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
            else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
        }

    }

    return dp[0][n-1];

}
int main()
{
    cout << longestPalindromeSubseq("bbbab") << endl;
    cout << longestPalindromeSubseq("cbbd") << endl;



}
