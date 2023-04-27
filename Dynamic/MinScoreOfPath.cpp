#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

// sol1
int minScore0(int n, vector<vector<int>>& roads) {
    unordered_map<int, unordered_map<int, int>> graph;
    int r_s = roads.size();
    int a,b,c;

    for (int i = 0; i < r_s; ++i) {
        a = roads[i][0], b= roads[i][1], c=roads[i][2];
        graph[a][b] = c;
        graph[b][a] = c;
    }
    
    int min = INT_MAX;
    unordered_set<int> visited;
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto adj: graph[node]){
            int neighbor = adj.first, score = adj.second;
            if(visited.count(neighbor) == 0){
                q.push(neighbor);
                visited.insert(neighbor);
            }
            min = min<score ? min : score;

        }
    }

    return min;

}

int MIN = INT_MAX;
void dfs(int s, vector<bool>&vis, vector<pair<int, int>>adj[]) {
    vis[s] = true;

    for(auto &it : adj[s]) {
        int v = it.first, wt = it.second;
        MIN = MIN<wt ? MIN : wt;

        if(!vis[v])
            dfs(v, vis, adj);
    }
}

int minScore(int n, vector<vector<int>>& roads) {
    ios_base::sync_with_stdio(false);
    vector< pair<int, int> > adj[n+1];
    for(auto &it : roads) {
        int u = it[0], v = it[1], wt = it[2];
        adj[u].emplace_back(v, wt);
        adj[v].emplace_back(u, wt);
    }
    vector<bool>vis(n+1, false);
    dfs(1, vis, adj);

    return MIN;
}

int main()
{

    vector<vector<int>> a = {{12,5,5958},{15,10,8201},{8,3,6354},{3,9,1436},{10,16,5624},{9,17,4778},{6,7,9519},{16,8,1620},{7,13,4327},{1,2,7487},{14,16,9791},{2,6,9980},{4,11,2809},{13,4,6634},{11,15,1155}};

    cout << minScore(17,a) << endl;

     a = {{7,11,418},{13,23,287},{16,25,7891},{15,7,9695},{4,3,9569},{17,7,1809},{14,3,4720},{14,4,6118},{9,2,4290},{32,17,5645},{14,16,426},{36,7,6721},{13,30,9444},{3,25,4635},{33,5,1669},{22,18,8910},{5,28,7865},{13,10,9466},{7,9,2457},{11,8,4711},{17,11,6308},{7,34,3789},{8,33,9659},{16,3,4187},{16,20,3595},{23,10,6251},{26,22,6180},{4,16,5577},{26,7,5398},{6,36,8671},{10,19,3028},{23,30,1330},{19,13,8315},{25,20,4740},{25,4,5818},{30,10,8030},{30,19,7527},{28,6,6804},{21,27,1746},{18,9,5189},{7,27,6560},{20,14,2450},{27,32,3951},{2,21,3927},{1,15,9283},{3,20,5428},{15,26,5871},{19,23,4533},{14,25,6992},{4,20,5831}};
    cout << minScore(36,a) << endl;
}
