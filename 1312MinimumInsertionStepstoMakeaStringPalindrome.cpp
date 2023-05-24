#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
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

int m_ax(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;

}

int find(const std::string& ss1, const std::string& ss2) {
    int n = ss1.length();
    int memo[n + 1][n + 1];
    memset(memo,0,sizeof(memo));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ss1[i] == ss2[j]) {
                memo[i + 1][j + 1] = memo[i][j] + 1;
            }
            else {
                memo[i + 1][j + 1] = m_ax(memo[i + 1][j], memo[i][j + 1]);
            }
        }
    }
    return memo[n][n];
}

int minInsertions0(const std::string& s) {
    string m = s;
    std::reverse(m.begin(), m.end());

    return s.length() - find(s, m);
}

int minInsertions(const string& t1) {
    int m = t1.size();
    int memo[m][m];
    for (int i = 0; i < m; ++i) memo[i][i] = 1;
    for (int i = 0; i < m; ++i)
        for (int j = i - 1; j >= 0; --j) {
            if (t1[i] == t1[j])
            {
                if(i - j > 1)
                {
                    memo[i][j] = 2 + memo[i - 1][j + 1];
                }
                else
                {
                    memo[i][j] = 2;
                }
            }
            else
            {
                memo[i][j] = m_ax(memo[i - 1][j], memo[i][j + 1]);
            }
        }
    return m - memo[m - 1][0];
}




int main() {
    string s = "mbadm";
    cout << minInsertions(s);

    return 0;
}

