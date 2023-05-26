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

struct node
{
    int data;
    struct node * l = nullptr;
    struct node * r = nullptr;
};

struct node* Creation(int data)
{
    auto node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    return node;
}

void Poster(struct node* node)
{
    if(node == nullptr)
    {

        return;
    }

    Poster(node->l);
    cout << node->data << " ";
    Poster(node->r);

}
void runner()
{
    auto rt = Creation(0);

    rt->l = Creation(4);
    rt->r = Creation(5);
    rt->l->r = Creation(3);
    rt->l->l = Creation(1);

    rt->r->r = Creation(1);
    rt->r->l = Creation(9);
    Poster(rt);

}

struct TreeNode
{
    int val;
    struct TreeNode * left = nullptr;
    struct TreeNode * right = nullptr;
};

int rob(TreeNode* root, int canRob=1) {
    if(root == nullptr) return 0;
    int dontRob = rob(root->left, 1) + rob(root->right, 1);
    int doRob = canRob ?
            root->val + rob(root->left,false) + rob(root->right,false):
            -1;
    return max(dontRob,doRob);
}

unordered_map<TreeNode*,int>mp;
int find(TreeNode* first) {
    if (first == nullptr) return 0;

    if (mp.count(first)){
        return mp[first];
    }
    int val = first->val;
    if (first->left != nullptr) {
        val += find(first->left->left) + find(first->left->right);
    }
    if (first->right != nullptr) {
        val += find(first->right->left) + find(first->right->right);
    }

    return mp[first]=max(val , find(first->left) + find(first->right));
}

int robs(TreeNode* first) {
    return find(first);
}

int main() {



    return 0;
}

