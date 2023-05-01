//https://leetcode.com/problems/first-completely-painted-row-or-column/description/
#include <bits/stdc++.h>
using namespace std;

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
    int sx = start[0];
    int sy = start[1];
    int tx = target[0];
    int ty = target[1];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n = specialRoads.size();
    vector<int> dp(n, INT_MAX);
    for (int i = 0; i != n; ++i){
        pq.emplace(abs(tx - specialRoads[i][2]) + abs(ty - specialRoads[i][3]), i);
    }

    while (!pq.empty()){
        int cost = pq.top().first;
        int i = pq.top().second;
        pq.pop();
        if (dp[i] != INT_MAX) { continue; }
        dp[i] = min(dp[i], cost);
        for (int j = 0; j != n; ++j){
            if (j == i) { continue; }
            pq.emplace(cost + specialRoads[i][4] + abs(specialRoads[j][2] - specialRoads[i][0]) + abs(specialRoads[j][3] - specialRoads[i][1]), j);
        }
    }

    int res = abs(sx - tx) + abs(sy - ty);
    for (int i = 0; i != n; ++i){
        res = min(res, abs(sx - specialRoads[i][0]) + abs(sy - specialRoads[i][1]) + specialRoads[i][4] + dp[i]);
    }
    return res;

}

int main()
{
    vector<int> start = {1,1}, target = {4,5};
    vector<vector<int>>specialRoads = {{1,2,3,3,2},{3,4,4,5,1}};

    cout << minimumCost(start,target,specialRoads) << endl;
}