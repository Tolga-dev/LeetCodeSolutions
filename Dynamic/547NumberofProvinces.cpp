#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/detonate-the-maximum-bombs/
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vb vector<bool>
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

int minx(const int& _a, const int& _b)
{
    if (_a > _b)
        return _b;
    return _a;
}

int maxx(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;
}

void dfs(vb& visited, unordered_map<int,vi>& nodes, int ind)
{
    visited[ind] = true;

    for (int neighbor : nodes[ind]) {
        if (!visited[neighbor]) {
            dfs(visited, nodes,neighbor);
        }
    }
}

int findCircleNum1(vector<vector<int>>& isConnected) {
    int size = isConnected.size();
    unordered_map<int,vi> graph;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (isConnected[i][j] == 1) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vb visited(size, false);
    int ans = 0;
    for (int i = 0; i < size; ++i) {
        if(!visited[i])
        {
            ans++;
            dfs(visited,graph,i);
        }
    }

    return ans;
}


class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0), count(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a != b) {
            if (rank[a] < rank[b]) {
                parent[a] = b;
            } else if (rank[a] > rank[b]) {
                parent[b] = a;
            } else {
                parent[b] = a;
                rank[a]++;
            }
            count--;
        }
    }

    int getCount() const {
        return count;
    }

private:
    vi parent;
    vi rank;
    int count;
};

int findCircleNum(std::vector<std::vector<int>>& isConnected) {
    int n = isConnected.size();
    UnionFind uf(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1) {
                uf.unite(i, j);
            }
        }
    }

    return uf.getCount();
}




int main() {
//    vvi isConnected = {{1,0,0},{0,1,0},{0,0,1}};
    vvi isConnected = {{1,1,0},{1,1,0},{0,0,1}};

    cout << findCircleNum(isConnected) << endl;
    return 0;
}








