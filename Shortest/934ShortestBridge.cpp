#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/evaluate-division/description/
#define vi vector<int>
#define pii pair<int,int>
#define qii vector<int>
#define qpii queue<pii>

#define vd vector<double>
#define vs vector<string>
#define vvs vector<vs>
#define vvi vector<vi>
#define uo_si unordered_set<int>
#define uo_ss unordered_set<string>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")


vector<pair<int,int>> first_graph,second_graph;

int first_graphPath = 2;

void searching(int ps, vector<vi>& grid, int i, int j, int size)
{
    if(i < 0 || j < 0 || i >= size || j >= size || grid[i][j] != 1) return;
    grid[i][j] = first_graphPath;

    if(first_graphPath == 2) first_graph.emplace_back(i,j);
    else second_graph.emplace_back(i,j);

    searching(ps,grid,i+1,j,size);
    searching(ps,grid,i,j+1,size);
    searching(ps,grid,i-1,j,size);
    searching(ps,grid,i,j-1,size);
}


int shortestBridge1(vector<vi>& grid) {
    int return_ans = INT_MAX;
    int size = grid.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(grid[i][j] == 1)
            {
                searching(first_graphPath,grid,i,j,size);
                first_graphPath++;
            }
        }
    }

    for(int ss =second_graph.size(), i=0;i<first_graph.size();i++)
        for(int j=0;j<ss;j++)
            return_ans=min(abs(first_graph[i].first -second_graph[j].first)+abs(first_graph[i].second-second_graph[j].second)-1,return_ans);
    return return_ans;

}





qpii q;
int visited[101][101];
vi row = {-1,1,0,0};
vi col = {0,0,-1,1};

void dfs(int i,int j,qpii&q,vvi& grid)
{
    if(i<0 || j<0 || i>=grid.size()|| j>=grid.size() || visited[i][j])  {
        return;
    }
    visited[i][j] = true;
    if(grid[i][j] == 0){
        q.push({i,j});
        return;
    }

    dfs(i + 1, j, q, grid);
    dfs(i - 1, j, q, grid);
    dfs(i, j + 1, q, grid);
    dfs(i, j - 1, q, grid);
}

int shortestBridge(vvi& grid) {
    memset(visited, 0, sizeof(visited));
    int n = grid.size();
    int m = grid[0].size();
    int flag = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(grid[i][j] == 1)
            {
                flag = 1;
                dfs(i, j, q, grid);
                break;
            }
        }

        if(flag){
            break;
        }
    }

    int result_ans = 0;


    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            int curRow = q.front().first;
            int curCol = q.front().second;

            if(grid[curRow][curCol]==1){
                return result_ans;
            }

            q.pop();
            for(int i=0;i<4;i++)
            {
                int nextRow= curRow+row[i];
                int nextCol= curCol+col[i];

                if(nextRow >= 0 && nextCol >= 0 &&nextCol < n && nextRow < n && !visited[nextRow][nextCol])
                {
                    visited[nextRow][nextCol] = 1;
                    q.push({nextRow,nextCol});
                }
            }
        }

        result_ans++;
    }

    return result_ans;
}

int main() {
    vvi nums = {{0,1,0},{0,0,0},{0,0,1}};
    cout << shortestBridge(nums) << endl;


    return 0;
}



/*grid = {{0,1},{1,0}}
Output: 1
Example 2:
    vvi nums = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};

Input: grid = {{0,1,0},{0,0,0},{0,0,1}}
Output: 2
Example 3:
 */