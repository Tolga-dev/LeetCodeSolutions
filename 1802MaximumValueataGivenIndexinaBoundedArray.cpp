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


int maxValue(int n, int index, int maxSum) {
    long long int mn = 1,mx = maxSum,mid,ans,f,l,k;
    while(mn <= mx){
        mid = (mn+mx)/2;
        f = mid-index;
        l = mid-(n-index-1);
        k = 0;
        if(f<=0){
            k += -f+1;
            k += (mid*(mid+1))/2;
        }else{
            k += ((index+1)*(mid+f))/2;
        }
        if(l<=0){
            k += -l+1;
            k += (mid*(mid-1))/2;
        }else{
            k += ((n-index-1)*(mid-1+l))/2;
        }
        if(k>maxSum){
            mx = mid-1;
        }else{
            ans = mid;
            mn = mid+1;
        }
    }
    return ans;
}



int main() {
    cout << maxValue(4,2,6) << endl;
}



