#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/unique-paths-ii/

// false
int uniquePathsWithObstacles0(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();


    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if(obstacleGrid[i][j] == 1)
                continue;
            obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
        }
    }
    return obstacleGrid[m-1][n-1];

}

// true recursion
int dfs(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp) {
    if(!i && !j) return 1;
    if(i < 0 || j < 0 || obstacleGrid[i][j]) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = dfs(i, j - 1, obstacleGrid, dp) + dfs(i - 1, j, obstacleGrid, dp);
}

int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0]) return 0;

    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return dfs(m - 1, n - 1, obstacleGrid, dp);
}

// TRUE
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    int up, left = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++,up=0,left=0){

            if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) dp[i][j] = 0;
            else if(i == 0 && j == 0) dp[i][j] = 1;
            else {
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}



int main()
{
//    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
//    vector<vector<int>> obstacleGrid = {{0,0},{0,1}};
    vector<vector<int>> obstacleGrid = {{0,1},{1,0}};

    cout<< uniquePathsWithObstacles(obstacleGrid) << endl;


}