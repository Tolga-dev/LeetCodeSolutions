#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int node , vector<int>&vis, int &c){
    c++;
    vis[node] =1;
    for(auto a : adj[node]){
        if(!vis[a]){
            dfs(adj,a,vis,c);
        }
    }
}
//SOL1
long long countPairs0(int n, vector<vector<int>>& ed) {
    vector<int> map[n];
    map->reserve(n);
    for (auto a: ed) {
        map[a[0]].emplace_back(a[1]);
        map[a[1]].emplace_back(a[0]);
    }
    vector<int> vis(n, 0);
    long long ans = 0;
    long long temp = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(map, i, vis, c);
            ans += temp * c;
            temp += c;
            c = 0;
        }
    }
    return ans;
}



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

long long countPairs(int n, vector<vector<int>>& edges) {
    long long ans = 0;
    dis.resize(n,-1);

    for (auto i : edges)
        unit(i[0], i[1]);

    for (int i = 0; i < n; i++)
        ans += dis[find(i)];

    return -(ans + n);

}



int main()
{
//    vector<vector<int>>b = {{0,1},{0,2},{1,2}};
    vector<vector<int>>b = {{0,2},{0,5},{2,4},{1,6},{5,4}};

    cout << countPairs0(7,b) << endl;


}