#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/evaluate-division/description/
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

vi topKFrequent(vi& array_lab, int k) {
    unordered_map<int,pii> freq;
    priority_queue<pair<int,int>> vals;
    vector<int> ans;

    for (auto var: array_lab) {
        freq[var].second++;
        freq[var].first = var;
    }

    for (auto var: freq) {
        vals.push({var.second.second,var.second.first});
    }


    while(!vals.empty())
    {
        ans.push_back(vals.top().second);
        vals.pop();

        k--;
        if(k == 0)
            break;

    }
    return ans;
}




int main() {
    vi nums = {1,1,1,2,2,3};
    for (auto m: topKFrequent(nums,2)) {
        cout << m << " ";
    }

    return 0;
}

