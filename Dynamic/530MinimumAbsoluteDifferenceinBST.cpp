#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
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

int ret=INT_MAX;
vector<int>sol;
void find(TreeNode* root){
    if(root==NULL){
        return;
    }
    find(root->left);
    sol.push_back(root->val);
    find(root->right);
}
int getMinimumDifference(TreeNode* root) {
    find(root);
    for(int i=1;i<sol.size();i++){
        ret=minx(ret,abs(sol[i]-sol[i-1]));
    }
    return ret;
}


int maxLevelSum(TreeNode* root) {
    queue<TreeNode*> q;
    TreeNode* temper;
    int i,h=0,xtemp=1,ytemp=INT_MIN,mk;
    q.push(root);
    while(!q.empty()){
        i = q.size();
        h = 0;
        while(i--){
            temper = q.front();q.pop();
            h += temper->val;
            if(temper->left)q.push(temper->left);
            if(temper->right)q.push(temper->right);
        }
        if(h>ytemp){
            ytemp = h;
            mk = xtemp;
        }
        xtemp++;
    }
    return mk;
}



int main() {

    

    return 0;
}



