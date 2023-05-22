#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/evaluate-division/description/
#define vi vector<int>
#define vd vector<double>
#define vs vector<string>
#define vvs vector<vs>
#define vvi vector<vi>
#define uo_si unordered_set<int>
#define uo_ss unordered_set<string>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")



double dfs(string src, string dst, unordered_set<string>& visited,
           unordered_map<string, vector<pair<string, double>>>& graph) {
    if (graph.find(src) == graph.end())
        return -1;
    if (src == dst)
        return 1;

    visited.insert(src);
    for (auto& node : graph[src]) {
        if (visited.count(node.first))
            continue;
        double res = dfs(node.first, dst, visited, graph);
        if (res != -1)
            return res * node.second;
    }
    return -1;
}

vd calcEquation(vector<vector<string>>& equations, vd& values, vector<vector<string>>& queries) {
    unordered_map<string, vector<pair<string, double>>> graph;

    int n = equations.size();
    for (int i = 0; i < n; i++) {
        graph[equations[i][0]].push_back({equations[i][1], values[i]});
        graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
    }

    vd result;
    for (auto& query : queries) {
        unordered_set<string> visited;
        result.push_back(dfs(query[0], query[1], visited, graph));
    }
    return result;
}



int main() {
//    vvi nums = {{1,2,3},{0,2},{0,1,3},{0,2}};

    vvs equations = {{"a","b"},{"b","c"}}, queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    vd values = {2.0,3.0};

    for (auto s: calcEquation(equations,values,queries)) {
        cout << s << " ";
    }

    return 0;
}