#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/minimum-cost-for-tickets

int mincostTickets(vector<int>& days, vector<int>& costs) {

    int maxDay = days[days.size() - 1];

    vector<int> dp(maxDay + 1);
    vector<int> isTravelDay(maxDay + 1);

    for (int day : days) {
        isTravelDay[day] = true;
    }

    for (int i = 1; i <= maxDay; i++) {
        if (!isTravelDay[i]) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = min(dp[i - 1]+costs[0], min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]));
        }
    }

    return dp[maxDay];
}



int main()
{
    vector<int> c = {2,7,15};
    vector<int> d = {1,4,6,7,8,20};

    cout << mincostTickets(d,c);


}