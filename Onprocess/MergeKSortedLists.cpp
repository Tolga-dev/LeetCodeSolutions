#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/merge-k-sorted-lists/solutions/3285930/100-faster-c-java-python/

struct ListNode
{
    int val;
    ListNode *next;
};
ListNode* Creator(ListNode* root, int val)
{
    auto node = (struct ListNode*)malloc(sizeof(ListNode*));
    node->val = val;
    node->next = root;
    root = node;
    return root;
}

void Print(ListNode * root)
{
    while(root->next != nullptr)
    {
        cout << root->val << " ";
        root = root->next;
    }
    cout << root->val << endl;

}

ListNode* merge(ListNode *left, ListNode *right) {

    Print(left);
    Print(right);
    cout << endl;
    ListNode *dummy = new ListNode();
    ListNode *temp = dummy;
    while (left != nullptr && right != nullptr) {
        if (left -> val < right -> val) {
            temp -> next = left;
            temp = temp -> next;
            left = left -> next;
        }
        else {
            temp -> next = right;
            temp = temp -> next;
            right = right -> next;
        }
    }
    while (left != nullptr) {
        temp -> next = left;
        temp = temp -> next;
        left = left -> next;
    }
    while (right != nullptr) {
        temp -> next = right;
        temp = temp -> next;
        right = right -> next;
    }
    return dummy -> next;
}
ListNode* mergeKListsPre(vector<ListNode*>& lists, int start, int end) {
    if (start == end)
        return lists[start];
    int mid = start + (end - start) / 2;

    return merge(mergeKListsPre(lists, start, mid), mergeKListsPre(lists, mid + 1, end));
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    return lists.empty() ? nullptr : mergeKListsPre(lists,0, lists.size()-1);
}


int main()
{
    struct ListNode* root = nullptr;
    struct ListNode *root2 = nullptr;
    struct ListNode* root3 = nullptr ;


    root = Creator(root, 5);
    root = Creator(root, 4);
    root = Creator(root, 1);

    root2 = Creator(root2, 4);
    root2 = Creator(root2, 3);
    root2 = Creator(root2, 1);

    root3 = Creator(root3, 6);
    root3 = Creator(root3, 2);

    vector<ListNode*> n;
    n.emplace_back(root);
    n.emplace_back(root2);
    n.emplace_back(root3);

    Print(mergeKLists(n));


}

