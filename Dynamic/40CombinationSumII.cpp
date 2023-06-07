#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
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



void finder(int target, std::vi& nums, std::vi& currentSubset, int index, vvi& ans)
{

    if(target == 0)
    {
        ans.push_back(currentSubset);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        if(i>index && nums[i]==nums[i-1]) continue;

        if(nums[i] > target) break;

        currentSubset.push_back(nums[i]);

        finder(target - nums[i],nums, currentSubset, i + 1,ans);

        currentSubset.pop_back();
    }

}

vector<vector<int>> combinationSum2(vi& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vvi ans;
    std::vi currentSubset;
    finder(target,candidates, currentSubset, 0,ans);
    return ans;
}

int main() {

    vi cand = {2,5,2,1,2};
    int t = 5;

    for (auto m:combinationSum2(cand,t)) {
        for (auto k: m) {
            cout << k << " ";
        }
        cout << endl;
    }

}



