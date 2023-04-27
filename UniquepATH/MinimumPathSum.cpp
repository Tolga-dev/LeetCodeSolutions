#include <bits/stdc++.h>
using namespace std;

// sol1
int minPathSum0(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    if(m == 1)
    {
        for (int i = 1; i < n; ++i)
            grid[0][i] = grid[0][i] + grid[0][i-1];

        return grid[m-1][n-1];
    }
    else if(n == 1)
    {
        for (int i = 1; i < m; ++i)
            grid[i][0] = grid[i][0] + grid[i-1][0];
        return grid[m-1][n-1];
    }


    for (int i = 1; i < m; ++i)
        grid[i][0] = grid[i][0] + grid[i-1][0];

    for (int i = 1; i < n; ++i)
        grid[0][i] = grid[0][i] + grid[0][i-1];


    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];


    return grid[m-1][n-1];
}

int minPathSum(vector<vector<int>>& grid,int m=0,int n=0) {

     m = grid.size();n = grid[0].size();

    for (int i = 1; i < m; ++i)
        grid[i][0] = grid[i][0] + grid[i-1][0];

    for (int i = 1; i < n; ++i)
        grid[0][i] = grid[0][i] + grid[0][i-1];


    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];


    return grid[m-1][n-1];

}

int main()
{
//    vector<vector<int>> obstacleGrid = {{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int>> obstacleGrid = {{1,2,3},{4,5,6}};
//    vector<vector<int>> obstacleGrid = {{9, 1, 4, 8}};
//    vector<vector<int>> obstacleGrid = {{1,2,3}};

    cout<< minPathSum(obstacleGrid) << endl;

}