#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
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



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

struct TreeNode* CreateNode(int val)
{
    auto newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}



vector<TreeNode*> find(int t, int d) {

    if(t > d) {
        return {nullptr};
    }
    vector<TreeNode*> ans;

    for(int i = t; i <= d; ++i) {
        vector<TreeNode*> l = find(t, i - 1);
        vector<TreeNode*> r = find(i + 1, d);

        for(int j = 0; j < l.size(); j++) {
            for(int k = 0; k < r.size(); k++) {
                TreeNode* root = new TreeNode(i);
                root->left = l[j];
                root->right = r[k];
                ans.push_back(root);
            }
        }
         
    }

    return ans;
}

vector<TreeNode*> generateTrees(int n) {
    return find(1, n);
}



int main() {

    struct TreeNode* root = CreateNode(1);
    root->left = CreateNode(0);
    root->right = CreateNode(2);


    return 0;
}
