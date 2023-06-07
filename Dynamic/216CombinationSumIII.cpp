#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/combination-sum-iii/description/
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

void helper(int ind, int c, int target,vvi& holder, vi& currentArray)
{
    if(target == 0)
    {
        if(c ==0) holder.emplace_back(currentArray);
        return;
    }
    for (int i = ind; i <=9 ; ++i) {
        if(target >= i && c > 0)
        {
            currentArray.push_back(i);
            c--;
            helper(i+1,c,target-i,holder,currentArray);
            currentArray.pop_back();
            c++;
        }
    }

}

vector<vector<int>> combinationSum3(int k, int n) {
    vvi ans;
    vi curr;

    helper(1,k,n,ans,curr);

    return ans;
}


int main() {

    for (auto m:combinationSum3(3,7)) {
        for (auto k: m) {
            cout << k << " ";
        }
        cout << endl;
    }

}



