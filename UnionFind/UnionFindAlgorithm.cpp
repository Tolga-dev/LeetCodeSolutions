#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

/// sol 1


vector<int> dis;

int find(int i)
{
    return dis[i] < 0 ? i : dis[i] = find(dis[i]);
}

void unit(int i , int j)
{
    i = find(i), j = find(j);
    if(i == j) return;

    if(dis[i] < dis[j]) dis[i] += dis[j], dis[j] = i;
    else dis[j] += dis[i], dis[i] = j;
}

long long countPairs0(int n, vector<vector<int>>& edges) {
    long long ans = 0,m = n;
    dis.resize(n,-1);

    for (auto i : edges)
        unit(i[0], i[1]);

    for (int i = 0; i < n; i++)
        ans += dis[find(i)];

    return (ans + m*m)/2;
}


int main()
{

    vector<vector<int>>b = {{0,2},{0,5},{2,4},{1,6},{5,4}};
   //   countPairs(7,b);

}
