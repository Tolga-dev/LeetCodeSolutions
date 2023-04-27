#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/count-complete-tree-nodes/


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
};

struct TreeNode *Creator(int val)
{
    struct TreeNode *node = (struct TreeNode *) malloc(sizeof(TreeNode));
    node->left = node->right = nullptr;
    node->val = val;

    return node;
}

/// sol 1
/*int countNumNodes(struct TreeNode *root) {
    return root == nullptr ? 0 : (1 + countNumNodes(root->right) + countNumNodes(root->left));
}*/
/// sol 2
/*
void preorder(TreeNode *root,int &count)
{
    if(root== nullptr)
        return;
    preorder(root->left,count);
    preorder(root->right,count);
    count=count+1;
}
int preorders(TreeNode* root,int count=0) {

    preorder(root,count);
    return count;
}
*/

/// sol3
/*int heightLeft(struct TreeNode *root){
    int lh = 0;
    while(root->left!= nullptr){
        lh++;
        root=root->left;
    }
    return lh;
}

int heightRight(struct TreeNode *root){
    int rh = 0;
    while(root->right!= nullptr){
        rh++;
        root=root->right;
    }
    return rh;
}

int countNodes(struct TreeNode *root) {
    if(root== nullptr) return 0;
    int lh = heightLeft(root);

    return lh==heightRight(root) ? ((2<<lh)-1) : 1+countNodes(root->left)+countNodes(root->right);
}*/
/// sol 4

/*
int heightLeft(struct TreeNode *root){
    return root == nullptr ? 0 : 1 + heightLeft(root->left);
}

int heightRight(struct TreeNode *root){
    int rh = 0;
    while(root->right!= nullptr){
        rh++;
        root=root->right;
    }
    return rh;
}

int countNodes(struct TreeNode *root) {
    if(root== nullptr) return 0;
    int lh = heightLeft(root);

    return lh==heightRight(root) ? ((2<<lh)-1) : 1+countNodes(root->left)+countNodes(root->right);
}*/


int main()
{
    struct TreeNode *node = nullptr;
    node = Creator(0);
    node->left = Creator(1);
    node->right = Creator(1);
    node->left->left = Creator(1);
    node->left->right = Creator(1);
    node->right->left = Creator(1);
//    node->right->right = Creator(1);


}

/*


static void V1(benchmark::State& state) {

    string s = "ABCABC";
    string b = "ABC";
    while(state.KeepRunning())
    {
        gcdOfStrings2(s,b);

    }


}
BENCHMARK(V1);

static void V2(benchmark::State& state) {

    string s = "ABCABC";
    string b = "ABC";
    while(state.KeepRunning())
    {
        gcdOfStrings(s,b);

    }

}
BENCHMARK(V2);

BENCHMARK_MAIN();
*/



