#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/detonate-the-maximum-bombs/
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

int finder(unordered_map<int, vector<int>> &gp, int bomb, vector<bool> &vitd) {
    if(vitd[bomb])
        return 0;
    vitd[bomb] = true;
    int count = 1;
    for(auto &x: gp[bomb]) {
        count += finder(gp, x, vitd);
    }
    return count;
}

int maximumDetonation(vector<vector<int>>& arr) {
    unordered_map<int, vector<int>> gp;
    int size = arr.size();
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(sqrt(pow((arr[j][0]-arr[i][0]), 2) + pow((arr[j][1]-arr[i][1]), 2)) <= arr[i][2]) {
                gp[i].push_back(j);
            }
        }
    }
    int ans = 0;
    vector<bool> vitd(size, false);
    for(int i = 0; i < size; i++) {
        fill(vitd.begin(), vitd.end(), false);
        ans = maxx(ans, finder(gp, i, vitd));
    }
    return ans;
}


int main() {


 //   vvi grid ={{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
    vvi grid ={{2,1,3},{6,1,4}};

    cout << maximumDetonation(grid) << endl;
    return 0;
}








