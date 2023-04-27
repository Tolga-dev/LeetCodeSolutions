#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/largest-color-value-in-a-directed-graph/


int largestPathValue(string colors, vector<vector<int>>& edges) {
    int nodes = colors.size(),n=nodes,res=0;
    vector<int> adjs[n];
    vector<int> in(n,0);
    vector<vector<int>> cnte(n,vector<int>(26,0));
    queue<int> que;

    for(auto &it : edges)
        adjs[it[0]].push_back(it[1]),++in[it[1]];

    for(int i=0;i<n;i++)
        if(in[i]==0) que.push(i), --nodes;

    while(!que.empty()){
        int top = que.front();que.pop();
        cnte[top][colors[top]-'a']++;
        res = max(res, cnte[top][colors[top]-'a']);
        for(auto &adjNode : adjs[top]){
            for(int i=0;i<26;i++){
                cnte[adjNode][i] = max(cnte[adjNode][i],cnte[top][i]);
                res = max(res, cnte[adjNode][i]);
            }
            --in[adjNode];
            if(in[adjNode]==0)
                que.push(adjNode),--nodes;
        }
    }

    return nodes == 0 ? res : -1;

}


int main()
{
    string colors = "abaca";
    vector<vector<int>> edges ={{0,1},{0,2},{2,3},{3,4}};

    cout << largestPathValue(colors,edges)<<endl;
}

