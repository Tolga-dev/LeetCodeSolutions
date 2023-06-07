#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/detonate-the-maximum-bombs/
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


bool checkStraightLine(vector<vector<int>>& coordinates) {
    int x1 = coordinates[0][0], y1 = coordinates[0][1];
    int x2 = coordinates[1][0], y2 = coordinates[1][1];
    int dx = x2 - x1, dy = y2 - y1;

    for (int i = 2; i < coordinates.size(); i++) {
        int x = coordinates[i][0], y = coordinates[i][1];
        if ((x - x1) * dy != (y - y1) * dx) {
            return false;
        }
    }
    return true;
}


int main() {
//    vvi isConnected = {{1,0,0},{0,1,0},{0,0,1}};
    vvi coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};

    cout << checkStraightLine(coordinates) << endl;
    return 0;
}








