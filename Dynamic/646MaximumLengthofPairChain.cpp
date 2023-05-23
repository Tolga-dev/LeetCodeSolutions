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



int findLongestChain1(vector<vector<int>>& p) {

    sort(p.begin(), p.end(),
         [](vector<int> &e1, vector<int> &e2){ return e1[1]<e2[1]; });

    int t = 0, rt = 1;
    for (int i = 1; i < p.size(); ++i) {
        if(p[t][1] < p[i][0] )
        {
            rt++;
            t = i;
        }

    }
    return rt;
}

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(),
         [](const vector<int>& e1, const vector<int>& e2) {
             return e1[1] < e2[1];
         });

    int count = 0;
    int last = INT_MIN;

    for (int i = 0; i < pairs.size(); ++i) {
        if (last < pairs[i][0]) {
            count++;
            last = pairs[i][1];
        }
    }

    return count;
}

int main() {

    vvi pairs = {{1,2},{3,4},{2,3}};
    cout << findLongestChain(pairs) << endl;

    return 0;
}

