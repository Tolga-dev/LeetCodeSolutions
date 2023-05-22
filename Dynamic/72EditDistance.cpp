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

int minUser(int a, int b)
{
    if(a > b) return b; return a;
}
int find(string s1, string s2, int m, int n)
{
    if(m == 0) return n;
    if(n == 0) return m;

    if(s1[m-1] == s2[n-1]) return find(s1,s2,m-1,n-1);

    return 1 +  minUser(find(s1, s2, m, n - 1), // Insert
                        minUser(
                                find(s1, s2, m - 1, n), // Remove
                                find(s1, s2, m - 1,n - 1) // Replace
                        )       );

}
int minDistance1(string word1, string word2) {

    return  find(word1, word2, word1.length(),
                 word2.length());
}




int mmin(int x, int y, int z)
{
    if (x <= y && x <= z)
        return x;
    if (y <= x && y <= z)
        return y;
    return z;
}

int minDistance2(string word1, string word2) {
    int m = word1.length(), n = word2.length();

    int memo[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                memo[i][j] = j; // Min. operations = j

            else if (j == 0)
                memo[i][j] = i; // Min. operations = i

            else if (word1[i - 1] == word2[j - 1])
                memo[i][j] = memo[i - 1][j - 1];

            else
                memo[i][j]
                        = 1
                          + mmin(memo[i][j - 1], // Insert
                                 memo[i - 1][j], // Remove
                                 memo[i - 1][j - 1]); // Replace
        }
    }

    return memo[m][n];
}



int finds(string s1, string s2, int m, int n,vector<vector<int>> memo)
{
    if(m == 0) return memo[m][n] = n;
    if(n == 0) return memo[m][n] = m;

    if(memo[m][n]!=-1) return memo[m][n];
    if(s1[m-1] == s2[n-1]) return memo[m][n] = finds(s1,s2,m-1,n-1,memo);

    return memo[m][n] = 1 +  minUser(finds(s1, s2, m, n - 1,memo), // Insert
                        minUser(
                                finds(s1, s2, m - 1, n,memo), // Remove
                                finds(s1, s2, m - 1,n - 1,memo) // Replace
                        )       );

}
//Time Limit Exceeded
int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();

    vector<vector<int>> memo(m+1,vector<int>(n+1,-1));

    return  finds(word1, word2, word1.length(),
                  word2.length(), memo);
}



int main() {
    string w1 = "horse";
    string w2 = "ros";

    cout << minDistance(w1,w2) << endl;

    return 0;
}

/*
 * int minDistance(string s1, string s2) {
        int m = s1.length(),n=s2.length(),i,j;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(i = 0; i <= m; i++){
            for(j = 0; j <= n; j++){
                if(i==0&&j==0){
                    dp[i][j] = 0;
                }else if(i==0){
                    dp[i][j] = j;
                }else if(j==0){
                    dp[i][j] = i;
                }
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
            }
        }
        return dp[m][n];
    }
 */