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
}

ListNode* swapNodes2(ListNode* ans, int ind) {
    ListNode* arr1=ans;
    ListNode* arr2=ans;
    ListNode* temp1;
    while(--ind){
        arr2=arr2->next;
    }
    temp1=arr2;
    while(arr2->next!=nullptr){
        arr1=arr1->next;
        arr2=arr2->next;

    }
    swap(arr1->val,temp1->val);
    return ans;
}

int l = 0;
int r = 0;

ListNode* swapNodes(ListNode* returner, int k) {
    ListNode *arr_left = returner, *arr_right = returner;

    while(--k)
        arr_left = arr_left->next;

    ListNode *temp = arr_left;
    while(temp->next != nullptr){
        temp = temp->next;
        arr_right = arr_right->next;
    }
     l = arr_left->val;
     r = arr_right->val;

    arr_left->val = r;
    arr_right->val = l;


    return returner;
}

int main()
{

    auto* A = (struct ListNode *) malloc(sizeof(ListNode));
    A->val = 1;
    auto* temp = A;
    int k = 1;
    A = swapNodes(A,k);
    printList(A);



    return 0;
}