#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/combination-sum-iv/description/
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


char nextGreatestLetter(vector<char>& letters, char target) {
    char ans = 0;
    int r = letters.size();
    int l = 0;
    int mid;

    if(target >= letters[r-1] || letters[0] > target)
        return letters[0];

    while (l <= r)
    {
        mid = (l + r)/2;

        if(letters[mid] > target)
        {
            ans = letters[mid];
            r = mid -1;

        }
        else
        {
            l = mid + 1 ;
        }
    }

    return ans;
}

int main() {
    vector<char> letters = {'x','x','y','y'};
    char target = 'z';


    cout << nextGreatestLetter(letters, target)<< endl;
}



