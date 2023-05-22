#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/evaluate-division/description/
#define vi vector<int>
#define pii pair<int,int>
#define qii vector<int>
#define qpii queue<pii>
#define umipii unordered_map<int,pii>
#define pqpii priority_queue<pair<int,int>>
#define vd vector<double>
#define vs vector<string>
#define vvs vector<vs>
#define vvi vector<vi>
#define uo_si unordered_set<int>
#define uo_ss unordered_set<string>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")


static vector<int> m;
static int memo_f(int n, vector<int>& memo)
{
    if(memo[n] != -1) return memo[n];

    if(n <= 0) return 0;
    else if(n == 1 || n == 2) return 1;

    return memo[n] = memo_f(n - 3, memo) + memo_f(n-2,memo) + memo_f(n-1,memo);
}

static const int hello = []()
{
    m = vector<int>(pow(2,25)-1,-1);
    memo_f(37,m);

    return 0;
}();

int tribonacci1(int n) {
    if(n <= 0) return 0;
    else if(n == 1 || n == 2) return 1;

    return m[n];
}

int tribonacci2(int n) {
    vector<int>memorizatio(n+3);
    memorizatio[0]=0;
    memorizatio[1]=1;
    memorizatio[2]=1;
    for(int i=3;i<=n;i++)
    {
        memorizatio[i]=memorizatio[i-1]+memorizatio[i-2]+memorizatio[i-3];
    }
    return memorizatio[n];

}

int tribonacci(int n) {
    vector<int> memorization(3, 0);
    memorization[1] = 1;
    memorization[2] = 1;

    for(int i= 3; i<=n; i++){
        memorization[i%3] =  memorization[(i+1)%3] + memorization[(i+2)%3] + memorization[(i+3)%3];
    }

    return memorization[n%3];
}


int main() {

    return 0;
}

