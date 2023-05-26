#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
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


int stoneGameII(vector<int>& pils)
{
    int memo[101][101];
    int gsm[101];
    int sz = pils.size(); memset(memo, 0, sizeof(memo)); memset(gsm, 0, sizeof(gsm));
    gsm[sz - 1] = pils[sz - 1];
    for(int i = sz - 2; i >= 0; i--) gsm[i] = pils[i] + gsm[i + 1];
    for(int i = sz - 1; i >= 0; i--)
    {
        for(int m = 1; m <= sz; m++)
        {
            if(i + 2*m >= sz) memo[i][m] = gsm[i];
            else
            {
                for(int x = 1; x <= 2*m; x++)
                {
                    memo[i][m] = max(memo[i][m], gsm[i] - memo[i + x][max(m, x)]);
                }
            }
        }
    }
    return memo[0][1];
}

int main() {
    vi nums = {2,7,9,4,4};
    cout << stoneGameII(nums) << endl;

    return 0;
}
