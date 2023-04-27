#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/number-of-closed-islands/


template<typename T = int>
int dfs(vector<vector<int>>& grid, int i, int j, int r, int c )
{

    if(grid[i][j] == 1 ||  grid[i][j] == 2) return true;
    if(i <= 0 || i >= r -1 || j<=0 || j >= c-1) return false;
    grid[i][j] = 2;

    int t,b,l,rr;
    t = dfs(grid, i - 1, j, r, c);    // Top
    b = dfs(grid, i + 1, j, r, c); // Bottom
    l = dfs(grid, i, j - 1, r, c);   // Left
    rr= dfs(grid, i, j + 1, r, c);  // Right

    return t && b && l && rr;
}
int closedIsland0(vector<vector<int>>& grid) {
    if (grid.empty())
        return 0;

    int m = grid.size();
    int n = grid[0].size()-1;
    int ans = 0;

    for (int i = 1; i < m-1; ++i) {
        for (int j = 1; j < n; ++j) {
            if(grid[i][j] == 0)
                if(dfs(grid,i,j,m,n+1))
                   ans++;
        }
    }

    return ans;
}


int arr[5]={0,1,0,-1,0};
bool dfs(vector<vector<int>>& grid, int i, int j, int m, int n){
    if (i < 0 || j < 0 || i >= m || j >= n) return false;
    if (grid[i][j] == 1) return true;

    grid[i][j] = 1;

    int ans= 1;
    for(int k=0;k<4;k++){
        int t= dfs(grid,i+arr[k],j+arr[k+1],m,n);
        ans = t & ans;
    }
    return ans;
}
int closedIsland9(vector<vector<int>>& grid) {
    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 1; i < m-1; i++){
        for (int j = 1; j < n-1; j++){
            if (grid[i][j] == 0){
                if(dfs(grid, i, j,m,n)) ans++;
            }
        }
    }
    return ans;
}



int dfs(vector<vector<int>>& grid, int i, int j, int r, int c )
{

    if(grid[i][j] == 1 ||  grid[i][j] == 2) return 1;
    if(i <= 0 || i >= r -1 || j<=0 || j >= c-1) return 0;
    grid[i][j] = 2;

    int t,b,l,rr;
    t = dfs(grid, i - 1, j, r, c);    // Top
    b = dfs(grid, i + 1, j, r, c); // Bottom
    l = dfs(grid, i, j - 1, r, c);   // Left
    rr= dfs(grid, i, j + 1, r, c);  // Right

    return t & b & l & rr;
}


int closedIsland(vector<vector<int>>& grid) {
    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 1; i < m-1; i++){
        for (int j = 1; j < n-1; j++){
            if (grid[i][j] == 0){
                ans+=dfs(grid, i, j,m,n);
            }
        }
    }

    return ans;
}

int main()
{

    vector<vector<int>>grid2 = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
//    vector<vector<int>>grid2 = {{0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0}};
//    vector<vector<int>>grid2 = {{0,0,1,1,0,1,0,0,1,0},{1,1,0,1,1,0,1,1,1,0},{1,0,1,1,1,0,0,1,1,0},{0,1,1,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,1,1,0},{0,1,0,1,0,1,0,1,1,1},{1,0,1,0,1,1,0,0,0,1},{1,1,1,1,1,1,0,0,0,0},{1,1,1,0,0,1,0,1,0,1},{1,1,1,0,1,1,0,1,1,0}};

    for (auto s: grid2) {
        for (auto m : s) {
            cout << m << " ";
        }
        cout << endl;
    }
    cout << closedIsland(grid2) << endl;
}