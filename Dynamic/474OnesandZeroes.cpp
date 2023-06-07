#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/combination-sum-iv/description/
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vb vector<bool>
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

int minx(const int& _a, const int& _b)
{
    if (_a > _b)
        return _b;
    return _a;
}

int maxx(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;
}

int findMaxForm(vector<string>& strings, int w, int n) {
    int arr[101][101]{0};

    for (string ss : strings) {

        int szs = 0, sos = 0;

        for (char c : ss)
        {
            c == '0' ? szs++ : sos++;

        }
        for (int i = w; i >= szs; i--)
        {
            for (int j = n; j >= sos; j--)
            {
                arr[i][j] = max(arr[i][j], arr[i-szs][j-sos] + 1);
            }
        }

    }

    return arr[w][n];
}


int main() {

    vector<string >strs = {"10","0001","111001","1","0"}; int m = 5, n = 3;

    cout << findMaxForm(strs,m,n) << endl;
}



