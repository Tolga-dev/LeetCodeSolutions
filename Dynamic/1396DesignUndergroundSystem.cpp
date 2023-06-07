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

/*

map<pair<string,string>,pair<int,int>> avr;
map<int,pair<string,int>> in;

class UndergroundSystem {
public:

    UndergroundSystem() {
    }

    void checkIn(const int& id, const string& stationName, const int& t) {
        in[id] = {stationName,t};
    }

    void checkOut(const int& id, const string& stationName, const int& t) {
        auto& dummy_id = in[id];
        auto& entry = avr[{stationName, dummy_id.first}];
        entry.first += t - dummy_id.second;
        entry.second++;
    }

    double getAverageTime(const string& startStation, const string& endStation) {
        auto& dummy = avr[{endStation,startStation}];
        return double(dummy.first)/(dummy.second);
    }
};
*/

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> userMp;
    unordered_map<string, pair<int ,int>> distance;

    UndergroundSystem() {
        userMp = unordered_map<int, pair<string, int>>();
        distance = unordered_map<string, pair<int ,int>> ();
    }

    void checkIn(int id, string stationName, int t) {
        userMp[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto& [startStation, time] = userMp[id];
        string start_end = startStation+"->"+stationName;
        auto [total, cnt] = distance[start_end];
        distance[start_end] = {total+(t-time), cnt+1};
    }

    double getAverageTime(string startStation, string endStation) {
        string start_end = startStation+"->"+endStation;
        auto [time, cnt] = distance[start_end];
        return (double)time/cnt;
    }
};


int main() {



    return 0;
}

