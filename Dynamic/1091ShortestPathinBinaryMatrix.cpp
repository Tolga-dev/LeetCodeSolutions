#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/perfect-squares/?envType=study-plan-v2&id=dynamic-programming
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
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
int maxx(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;
}
int minx(const int& _a, const int& _b)
{
    if (_a > _b)
        return _b;
    return _a;
}


int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0]==1)return -1;
    int size = grid.size();

    if(size==1)return 1;
    queue<pair<pii,int>>q;
    q.push({{0,0},1});

    vector<vector<bool>>visited(size,vector<bool>(size,false));
    visited[0][0]=true;
    vvi coords = {{0,1}, {0,-1}, {1,0}, {-1,0},
                                       {1,1}, {-1,-1}, {1,-1}, {-1,1}};

    while(!q.empty())
    {
        auto&p = q.front();
        auto& vals = p.first;
        int xc = vals.first;
        int yc = vals.second;
        int ans = p.second;
        q.pop();
        for(auto& coord: coords)
        {
            int x = coord[0] + xc;
            int y = coord[1]+ yc;

            if(x>=0 && y>=0 && x<size && y<size && grid[x][y]==0 && !visited[x][y]){

                q.push({{x,y},ans+1});
                visited[x][y] = true;

                if(x==size-1 && y==size-1)
                    return ans+1;

            }
        }

    }

    return -1;

}

int main() {


    vvi grid = {{1,0,0},{1,1,0},{1,1,0}};

    cout << shortestPathBinaryMatrix(grid) << endl;
    return 0;
}








