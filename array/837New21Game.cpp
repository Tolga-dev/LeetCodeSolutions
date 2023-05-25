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

bool firstCheck(int k, int maxPts, int n)
{
    return (n >= k + maxPts) || (k == 0);
}

double new21Game1(int n, int k, int maxPts, double pr = 1.0, double ret = 0.0) {
    if(firstCheck(k,maxPts,n)) return 1.0;
    vector<double> memo(maxPts + 1,0.0);
    memo[0] = 1.0;
    for (int i = 1; i < n + 1; i++) {
        memo[i % (maxPts + 1)] = pr / maxPts;
        i<k ? pr += memo[i % (maxPts + 1)] : ret += memo[i % (maxPts + 1)];
        if (i - maxPts >= 0) pr -= memo[(i - maxPts) % (maxPts + 1)];
    }
    return ret;
}

double new21Game(int n, int k, int ts, double pr = 1.0, double ret = 0.0) {
    if(firstCheck(k,ts,n)) return 1.0;
    vector<double>mo(n+1,0);
    mo[0] = 1.0;
    for(int i=1;i<=n;i++){
        mo[i] = pr/ts;
        (i<k) ? pr += mo[i]: ret += mo[i];
        if(i-ts >=0) pr -= mo[i-ts];
    }
    return ret;
}

int main() {
    string s = "mbadm";
    cout << new21Game(10,1,10) << endl;
    cout << new21Game(6,1,10) << endl;

    return 0;
}

