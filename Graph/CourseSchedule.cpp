#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
//https://leetcode.com/problems/longest-palindromic-subsequence/

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

bool dfs(int node, vector<int> adj[], vector<int>& vis) {
    vis[node] = 2;
    for (auto it: adj[node]) {
        if (vis[it] == 0) {
            if (dfs(it, adj, vis))
                return true;
        } else if (vis[it] == 2) {
            return true;
        }
    }
    vis[node] = 1;
    return false;
}

//dfs
bool canFinish0(int numCourses, vector<vector<int>> prerequisites) {
    int n = prerequisites.size();
    vector <int> vis(numCourses, 0);
    vector <int> adj[numCourses];
    for (int i = 0; i < n; i++)
        adj[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
    for (int i = 0; i < numCourses; i++) {
        if (vis[i] == 0) {
            if (dfs(i, adj, vis))
                return false;
        }
    }
    return true;
}

// bfs
bool canFinish(int n, vector<vector<int>> prerequisites) {
    vector<vector<int>> G(n);
    vector<int> degree(n, 0), bfs;
    for (auto& e : prerequisites)
        G[e[1]].push_back(e[0]), degree[e[0]]++;
    for (int i = 0; i < n; ++i) if (!degree[i]) bfs.push_back(i);
    for (int i = 0; i < bfs.size(); ++i)
        for (int j: G[bfs[i]])
            if (--degree[j] == 0) bfs.push_back(j);
    return bfs.size() == n;
}

int main()
{

    cout << canFinish(2,vector<vector<int>>{{1,0}}) << endl;
    cout << canFinish(2,vector<vector<int>>{{1,0},{0,1}}) << endl;

}
