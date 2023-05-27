#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/house-robber-ii/
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
int masx(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;
}

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

void print(struct TreeNode* TreeNode)
{
    if(TreeNode == nullptr)
    {

        return;
    }

    print(TreeNode->left);
    print(TreeNode->right);
    cout << TreeNode->val << " ";
}

int res;
int find(TreeNode *root) {
    if(root == nullptr) return 0;
    int l = masx(find(root->left), 0);
    int r = masx(find(root->right), 0);
    res = masx(res, l + r + root->val);
    return masx(l + root->val, r + root->val);
}

int maxPathSum(TreeNode* root) {
    res = INT_MIN;
    find(root);
    return res;
}

int main() {

    TreeNode * root = CreateNode(-10);
    root->left = CreateNode(9);

    root->right = CreateNode(20);
    root->right->right = CreateNode(7);
    root->right->left = CreateNode(15);

    print(root);


    return 0;
}

