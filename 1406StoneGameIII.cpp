#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/house-robber-ii/
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
//brute force
int finder(int i , vi& stoneVal)
{
    if(i == stoneVal.size())
        return 0;
    int score = INT_MIN;
    score = masx(score,stoneVal[i] - finder(i+1, stoneVal));

    if(i + 1 < stoneVal.size()) score = masx(score, stoneVal[i] + stoneVal[i+1] -finder(i+2, stoneVal));
    if(i + 2 < stoneVal.size()) score = masx(score, stoneVal[i] + stoneVal[i+1] + stoneVal[i+2] -finder(i+3, stoneVal));
    return score;
}

string stoneGameIII1(vector<int>& stoneValue) {
    int val = finder(0, stoneValue);

    return val > 0 ? "Alice" : val < 0? "Bob" : "Tie";
}

int find(int i, vi stoneVal, vi memo)
{
    if(i == stoneVal.size()) return 0;
    if(memo[i] == -1) return memo[i];

    int score = INT_MIN;
    score = max(score,stoneVal[i] - find(i+1, stoneVal,memo));

    if(i + 1 < stoneVal.size()) score = masx(score, stoneVal[i] + stoneVal[i+1] -finder(i+2, stoneVal));
    if(i + 2 < stoneVal.size()) score = masx(score, stoneVal[i] + stoneVal[i+1] + stoneVal[i+2] -finder(i+3, stoneVal));
    return memo[i] = score;

}

string stoneGameIII2(vector<int>& stoneValue) {
    vi memo(stoneValue.size(),-1);
    int val = find(0, stoneValue,memo);

    return val > 0 ? "Alice" : val < 0? "Bob" : "Tie";
}


string stoneGameIII3(vector<int>& stoneValue) {
    int size = stoneValue.size();
    vi memo(size,-1);
    memo[size] = 0;
    int score = INT_MIN;
    for (int i = size-1; i >=0 ; --i) {
        score = masx(score, stoneValue[i] - memo[i+1]);
        if(i+1 < size)
            score = masx(score, stoneValue[i] + stoneValue[i+1] - memo[i+2]);
        if(i+2 < size)
            score = masx(score, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - memo[i+3]);
        memo[i] = score;
        score = INT_MIN;
    }
    return score > 0 ? "Alice" : score < 0? "Bob" : "Tie";
}


string stoneGameIII(vector<int>& arr) {
    int si = arr.size();
    int a=0,b=0,c=0;
    int answer = INT_MIN;
    for (int i = si - 1; i >= 0; i--)
    {
        answer = masx(answer, arr[i] - a);
        if (i + 1 < arr.size())
            answer = masx(answer, arr[i] + arr[i + 1] - b);
        if (i + 2 < arr.size())
            answer = masx(answer, arr[i] + arr[i + 1] + arr[i + 2] - c);
        c=b;
        b=a;
        a=answer;
        answer = INT_MIN;
    }
    return a > 0 ? "Alice" : a < 0? "Bob" : "Tie";

}


int main() {
    vi  values = {1,2,3,7};

    cout << stoneGameIII(values) << endl;

    return 0;
}

