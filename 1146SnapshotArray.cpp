#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
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

class SnapshotArray {
public:

    vector< vector<pair<int,int> > >v;
    int id;
    SnapshotArray(int length) {
        v.resize(length);
        id=-1;
        for(int i=0;i<length;i++)
        {
            v[i].push_back({id,0});
        }
    }

    void set(int index, int val) {
        v[index].push_back({id,val});
    }

    int snap() {
        id++;
        return id;
    }

    int get(int index, int snap_id) {
        int l=0,r=v[index].size()-1;
        int ans=0;
        while(l<=r)
        {
            int mid=(r-l)/2+l;
            if(v[index][mid].first<snap_id)
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return v[index][ans].second;
    }

};



int main() {



}



