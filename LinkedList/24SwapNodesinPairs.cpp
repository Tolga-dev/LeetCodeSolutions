#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/rotate-function/description/
#define vi vector<int>
#define vvi vector<vi>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};;

void Create(ListNode** Head, int n)
{

    auto* newNode = (struct ListNode *) malloc(sizeof(ListNode));

    newNode->val = n;

    newNode->next = *Head;

    *Head = newNode;


}

void printList(ListNode *node)
{

    while (node != nullptr)
    {
        cout<<" "<<node->val;
        node = node->next;
    }
    cout << endl;
}

ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next) return head; //If there are less than 2 nodes in the given nodes, then no need to do anything just return the list as it is.

    auto* dummyNode = new ListNode();

    ListNode* prevNode=dummyNode;
    ListNode* currNode=head;

    while(currNode && currNode->next){
        prevNode->next = currNode->next;
        currNode->next = prevNode->next->next;
        prevNode->next->next = currNode;

        prevNode = currNode;
        currNode = currNode->next;
    }

    return dummyNode->next;
}

int main()
{

    auto* A = (struct ListNode *) malloc(sizeof(ListNode));
    A->val = 1;
    auto* temp = A;
    int k = 1;
    vector<int> head = {2,3,4};
    for (auto s: head) {
        Create(&A,s);
    }

    printList(A);
    swapPairs(A);
    printList(A);



    return 0;
}