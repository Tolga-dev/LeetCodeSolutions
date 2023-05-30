//https://leetcode.com/problems/design-hashset/
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/design-hashset/submissions/
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
int masx(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;
}
/*
class MyHashSet {
public:
    unordered_map<int,int> map;
    MyHashSet() = default;

    void add(int key) {
        map[key] = key;
    }

    void removes(int key) {
        map.erase(key);
    }

    bool contains(int key) {
        return map.count(key) == 0 ? false : true;
    }
};
  */


class MyHashSet {
public:
    bool hashmap[1000001];
    MyHashSet()
    {
        memset(hashmap,false,1000001);
    }

    void add(int key) {
        hashmap[key]=true;
    }

    void remove(int key) {
        hashmap[key]=false;
    }
    bool contains(int key) {
        return hashmap[key];
    }
};



int main() {
    MyHashSet* set = new MyHashSet();


    return 0;
}

