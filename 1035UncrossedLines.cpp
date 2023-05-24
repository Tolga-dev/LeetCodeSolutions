#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
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
#define ll long long
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

int m_ax(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;

}

int check(const int& a, const int& b)
{
    return a == b;
}

int maxUncrossedLines(vector<int>& t1, vector<int>& t2)
{
    int k=t1.size();
    int l=t2.size();
    int memo[k+1][l+1];

    for(int i=0;i<k+1;i++)
    {
        memo[i][0] = 0;
    }

    for(int i=0;i<l+1;i++)
    {
        memo[0][i] = 0;
    }

    for(int i=1;i<=k;i++){

        for(int j=1;j<=l;j++){

            if(check(t1[i-1],t2[j-1])){
                memo[i][j]=1+memo[i-1][j-1];
            }
            else{memo[i][j]=m_ax(memo[i-1][j],memo[i][j-1]);}
        }
    }
    return memo[k][l];
}


int main() {
    vi nums1 = {3,3}, nums2 = {3};

    cout << maxUncrossedLines(nums1,nums2);

    return 0;
}

