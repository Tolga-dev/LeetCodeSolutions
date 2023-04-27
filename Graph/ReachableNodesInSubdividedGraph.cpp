#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/

int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {

    auto INF = 1e8;
    vector<vector<pair<int,int>>> g(n);
    for(auto i: edges){
        g[i[0]].push_back({i[1],i[2]});
        g[i[1]].push_back({i[0],i[2]});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > queue;
    queue.push({0, 0}); //distance,node
    vector<int> d(n, INF);
    d[0] = 0;

    while(!queue.empty()){
        int dist = queue.top().first;
        int node = queue.top().second;
        queue.pop();
        for(auto it:g[node]){
            if(d[it.first]>dist+it.second+1)
            {
                d[it.first]=dist+it.second+1;
                queue.push({d[it.first], it.first});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(d[i] <= maxMoves)
            ans++;
    }

    for(auto i : edges) {
        int src=i[0],dest=i[1], between=i[2];
        int x = max(0, (maxMoves - d[src]));
        int y = max(0, (maxMoves - d[dest]));
        ans += min(between, x + y);
    }
    return ans;
}


int main()
{
    vector<vector<int>> edges = {{1,2,4},{1,4,5},{1,3,1},{2,3,4},{3,4,5}};
    int maxMoves = 17, n = 5;
    reachableNodes(edges,maxMoves,n);

}