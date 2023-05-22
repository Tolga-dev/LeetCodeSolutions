#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
#define vi vector<int>
#define vvi vector<vi>
#define uo_si unordered_set<int>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

bool dfs(vvi& graph, vi& visited, int node, int p){
    if(visited[node] != 0)
        return (visited[node] == p);

    visited[node] = p;
    for(int i : graph[node]){
        if(!dfs(graph, visited, i, -p))
            return false;
    }

    return true;
}

bool isBipartite1(vvi& graph) {
    int n = graph.size();
    vi visited(n, 0);

    for(int node = 0; node < n; node++){
        if(visited[node]==0)
            return dfs(graph, visited, node, 1);
    }

    return true;
}



bool isBipartite(vvi& graph) {
    int n = graph.size();
    vi visited(n, 0);

    for(int node = 0; node < n; node++){
        if(visited[node]==0)
            return dfs(graph, visited, node, 1);
    }

    return true;
}


int main() {
//    vvi nums = {{1,2,3},{0,2},{0,1,3},{0,2}};
    vvi nums = {{1,3},{0,2},{1,3},{0,2}};

    cout << isBipartite(nums) << endl;

    return 0;
}