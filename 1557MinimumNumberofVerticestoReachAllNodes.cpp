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

vector<int> findSmallestSetOfVertices1(int n, vector<vector<int>>& edges) {
    vi ans;
    set<int> keys;
    std::unordered_map<int,int> counter;

    for (auto & edge : edges) {
        keys.insert(edge[1]);
        keys.insert(edge[0]);
        counter[edge[1]]++;
    }

    for (auto m: keys) {
        if(counter[m] == 0)
            ans.emplace_back(m);
    }

    return ans;
}

vector<int> findSmallestSetOfVertices2(int n, vector<vector<int>>& edges) {

    vector<int> counter_edges(n, 0);
    int i = 0;
    for (i = 0; i < edges.size(); ++i) {
        counter_edges[edges[i][1]]++;
    }

    vector<int> ans;
    for(i = 0;i < n; i++){
        if(counter_edges[i]==0)
            ans.emplace_back(i);
    }

    return ans;
}

vector<int> findSmallestSetOfVertices3(int n, vector<vector<int>>& edges) {
    uo_si counter_edges;

    for (const auto& edge : edges) {
        counter_edges.insert(edge[1]);
    }

    vi ans;
    for (int i = 0; i < n; ++i) {
        if (counter_edges.find(i) == counter_edges.end()) {
            ans.push_back(i);
        }
    }

    return ans;
}

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

    int* counter_edges = new int[n]();  // Initialize to zero

    for (int i = 0; i < edges.size(); ++i) {
        int destination = edges[i][1];
        counter_edges[destination]++;
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (counter_edges[i] == 0) {
            ans.push_back(i);
        }
    }

    delete[] counter_edges;
    return ans;
}



int main() {
    int n = 6;
    vvi edges = {{0,1},{0,2},{2,5},{3,4},{4,2}};

    for (auto s: findSmallestSetOfVertices(n,edges)) {
        cout << s << " ";
    }




    return 0;
}