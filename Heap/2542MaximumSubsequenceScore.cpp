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

/*a = max(
        (ll)((arrr1[i] + arrr1[j] + arrr1[l]) * min(arrr2[i], min(arrr2[j] , arrr2[l])))
        ,a);*/
ll m_ax(const ll& _a, const ll& _b)
{
    if (_a < _b)
        return _b;
    return _a;

}
long long maxScore(vector<int>& arrr1, vector<int>& arrr2, int ind) {
    vector<pair<int, int>> ar;
    int n = arrr2.size();
    ar.reserve(n);
    transform(arrr1.begin(), arrr1.end(), arrr2.begin(), back_inserter(ar), [](int a, int b) {
        return make_pair(a, b);
    });

    sort(ar.begin(), ar.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    priority_queue<int,vi, greater<>> queu;
    ll rn = 0;
    ll turn = 0;
    for (int i = n-1; i > n-1-ind; --i) {
        queu.push(ar[i].first);
        rn += ar[i].first;
    }

    turn = m_ax(turn, rn * ar[n-ind].second);

    int temp;
    for (int i = n-1-ind; i >= 0; --i) {
        temp = queu.top();
        queu.pop();
        rn -= temp;

        rn += ar[i].first;
        queu.push(ar[i].first);

        turn = m_ax(turn, rn * ar[i].second);
    }
    
    return turn;
}

int main() {
//    vi arrr1 = {1,3,3,2},
//    arrr2 = {2,1,3,4};
    vi arrr1 = {4,2,3,1,1},
            arrr2 = {7,5,10,9,6};

    int k = 1;
//    int k = 3;

    cout << maxScore(arrr1,arrr2,k) << endl;

    return 0;
}

