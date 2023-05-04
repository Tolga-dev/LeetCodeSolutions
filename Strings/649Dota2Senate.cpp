//https://leetcode.com/problems/row-with-maximum-ones/submissions/943930696/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define uosi vector<int>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

string predictPartyVictory(string senate) {
    int res = 0;
    for (int i = 0; i < senate.length(); ++i) {
        if(senate[i] == 'R')
        {
            if(res < 0)
                senate.push_back('D');
            res++;
        }
        else
        {
            if(res > 0)
                senate.push_back('R');
            res--;

        }
    }
    return res < 0 ? "Dire" : "Radiant";
}

int main()
{
    cout << predictPartyVictory("RD") << endl;
    cout << predictPartyVictory("RDD") << endl;
    cout << predictPartyVictory("RDDDRDRRDR") << endl;

}
