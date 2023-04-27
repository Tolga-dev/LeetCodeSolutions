#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
//https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();


#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
int numWsays(vector<string>& words, string target) {
    int n = words[0].size(), m = target.size();
    int md = 1e9 + 7;

    vvll dp(n, vll(m, -1));
    vvll cnt(n, vll(26));
    for (auto & word : words) {
        for (int j = 0; j < n; j++) {
            cnt[j][word[j] - 'a']++;
        }
    }
    int res,c;
    function<int(int,int)> dfs = [&](int i, int j) {

        if (j == m) return 1;
        if (i == n) return 0;

        if (dp[i][j] != -1) return (int) dp[i][j];

        res = dfs(i + 1, j);
        c = target[j] - 'a';

        if (cnt[i][c]) res = (res + cnt[i][c] * dfs(i + 1, j + 1)) % md;

        return (int) (dp[i][j] = res);
    };
    return dfs(0, 0);
}




int main()
{
    vector<string> words = {"abba","baab"}; string target = "aba";
    cout << numWays(words,target);

}

