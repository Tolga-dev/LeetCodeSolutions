#include <bits/stdc++.h>

using namespace std;
//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// sol 1
TreeNode* bst(vector<int>nums, int left, int right) {
    if (left > right) return nullptr;

    int m = (right + left) / 2;

    TreeNode* root = new TreeNode();
    root->val = nums[m];
    root->left = bst(nums, left, m - 1);
    root->right = bst(nums, m+ 1, right);
    return root;
}

TreeNode* sortedArrayToBST(const vector<int>&nums) {
    return bst(nums, 0, nums.size() - 1);
}

int main()
{

}