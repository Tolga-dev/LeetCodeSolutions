#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/perfect-squares/?envType=study-plan-v2&id=dynamic-programming
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
int maxx(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;
}
int minx(const int& _a, const int& _b)
{
    if (_a > _b)
        return _b;
    return _a;
}

vector<vector<int>> ret;
void helper(int ind,int target,vi& can,vi &temp){
    if(ind==can.size() || target<=0){
        if(target==0) ret.push_back(temp);
        return;
    }

    if(target-can[ind]<=target){
        temp.push_back(can[ind]);
        helper(ind,target-can[ind],can,temp);
        temp.pop_back();
    }
    helper(ind+1,target,can,temp);
}

vector<vector<int>> combinationSum(vi& can, int target) {
    vi temp;
    helper(0,target,can,temp);
    return ret;
}


int main() {

    vi can = {2,3,6,7};

    for (auto sm : combinationSum(can,7)) {
        for (auto m: sm) {
            cout << m<< " ";
        }
        cout << endl;
    }

    return 0;
}

