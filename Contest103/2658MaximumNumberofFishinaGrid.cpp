//https://leetcode.com/problems/make-array-empty/
#include <bits/stdc++.h>
using namespace std;

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

int dfs(int x, int y, vector<vector<int>>& g) {
    if (x < 0 || x >= g.size() || y < 0 || y >= g[x].size() || g[x][y] == 0) {
        return 0;
    }
    int r = g[x][y];
    g[x][y] = 0;
    return r + dfs(x - 1, y, g) + dfs(x + 1, y, g) + dfs(x, y - 1, g) + dfs(x, y + 1, g);

}
int findMaxFish(vector<vector<int>>& grid) {
    int r = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            r = max(r, dfs(i, j, grid));
        }
    }
    return r;
}


int main()
{
    vector<vector<int>>grid = {{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
    cout << findMaxFish(grid) << endl;
}