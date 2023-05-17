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


int user_max(const int& a,const int& b)
{
    if (a < b)
        return b;
    return a;
}

int pairSum(ListNode* head) {
    vector<int> mem;
    int user_size = 0;
    while (head != nullptr)
    {
        mem.emplace_back(head->val);
        user_size++;
        if(head->next == nullptr)
            break;
        head = head->next;
    }

    int ans = 0;
    for (int i = 0; i <= user_size/2; ++i) {
        ans = user_max(ans,mem[i] + mem[user_size-i]);
    }
    cout << ans << endl;
    return ans;
}

int main()
{

    auto* A = (struct ListNode *) malloc(sizeof(ListNode));
    A->val = 1;
    auto* temp = A;
    vector<int> head = {2};
    for (auto s: head) {
        Create(&A,s);
    }

    //printList(A);
    pairSum(A);
    //printList(A);



    return 0;
}