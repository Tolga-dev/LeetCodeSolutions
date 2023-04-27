#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
//https://leetcode.com/problems/longest-palindromic-subsequence/

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

bool dfs(int node, vector<int> pr[], vector<int>& v, vector <int>& ans) {
    v[node] = 2;
    for (auto it: pr[node]) {
        if (v[it] == 0) {
            if (dfs(it, pr, v, ans))
                return true;
        } else if (v[it] == 2) {
            return true;
        }
    }
    ans.push_back(node);
    v[node] = 1;
    return false;
}
vector<int> findOrd1er(int numCourses, vector<vector<int>> prerequisites,int n = 0) {
    n = prerequisites.size();
    vector <int> v(numCourses, 0);
    vector <int> pr[numCourses];
    for (int i = 0; i < n; i++)
        pr[prerequisites[i][1]].push_back(prerequisites[i][0]);
    vector <int> ans;
    for (int i = 0; i < numCourses; i++) {
        if (v[i] == 0) {
            if (dfs(i, pr, v, ans))
                return {};
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// topo and kahn
vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
    int n = numCourses;
    vector<int> emp;
    vector<vector<int>> adj(n);
    for(auto & prerequisite : prerequisites){
        adj[prerequisite[1]].push_back(prerequisite[0]);
    }
    
    vector<int> id(n);
    vector<int> topo;
    for(int i=0; i<n; i++){
        for(auto it: adj[i]){
            id[it]++;
        }
    }

    queue<int> que_top;
    for(int i=0; i<n; i++){
        if(id[i]==0){
            que_top.push(i);
        }
    }

    while(!que_top.empty()){
        int top= que_top.front();
        topo.push_back(top);
        que_top.pop();
        for(auto it: adj[top]){
            id[it]--;
            if(id[it] ==0){
                que_top.push(it);
            }
        }
    }
    return (topo.size()<n)?emp:topo;

}



int main()
{
    for (auto s : findOrder(2,vector<vector<int>>{{1,0}})) {
        cout << s << " ";
    }
    cout << endl;

    for (auto s : findOrder(4,vector<vector<int>>{{1,0},{2,0},{3,1},{3,2}})) {
        cout << s << " ";
    }
    cout << endl;


}
