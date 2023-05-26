#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
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

bool stoneGame(vector<int>& piles) {
    int sz=static_cast<int>(piles.size());
    int meno[sz][sz];
    for(int o=0;o<sz;o++){
        for(int p=o;p>=0;p--){
            if(p==o)
                meno[p][o]=piles[p];
            else
                meno[p][o]=max(piles[p]-meno[p+1][o],piles[o]-meno[p][o-1]);
        }
    }
    
    return meno[0][sz-1]>0;
}

int main() {
    vi nums = {3,2,6,5,0,3};
    cout << stoneGame(nums) << endl;

    return 0;
}
