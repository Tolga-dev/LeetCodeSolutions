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

int finder(map<pair<int, int>,int> &memo, int m, int i, vector<int> &p1, vector<int> &p2)
{
    if(i == p1.size()){
        return 0;
    }

    if(memo.find({i, m}) != memo.end())
    {

        return memo[{i, m}];

    }

    int ret = INT_MAX/2;

    int id = upper_bound(p2.begin(), p2.end(), m) - p2.begin();

    if(p1[i] > m)
    {

        ret = minx(ret, finder(memo, p1[i], i+1, p1, p2));

    }

    if(id < p2.size())
    {

        ret = minx(ret, finder(memo, p2[id], i+1, p1, p2)+1);

    }

    return memo[{i, m}] = ret;
}

int makeArrayIncreasing2(vector<int>& p1, vector<int>& p2) {

    sort(p2.begin(), p2.end());

    map<pair<int, int>, int> memo;

    int ret = finder(memo,INT_MIN, 0, p1, p2);

    return ret>=INT_MAX/2?-1:ret;
    
}


int makeArrayIncreasing(vector<int>& p1, vector<int>& p2) {
    sort(p2.begin(),p2.end());
    map<int,int> lst;
    lst[0]=-1;
    for(int ind:p1)
    {
        map<int,int> curride;
        for(auto [op,last]:lst)
        {
            auto it=upper_bound(p2.begin(),p2.end(),last);
            if(it!=p2.end()) curride[op+1]=*it;
        }
        for(auto [op,last]:lst)
        {
            if(last<ind)
            {
                if(auto it=curride.find(op);it==curride.end())
                {
                    curride[op]=ind;
                }
                else
                {
                    curride[op]=minx(ind,it->second);
                }
            }
        }
        lst=move(curride);
    }
    return lst.empty() ? -1 : lst.begin()->first;
}

int main() {



    return 0;
}



