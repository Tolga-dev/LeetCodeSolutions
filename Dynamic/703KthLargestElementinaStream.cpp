#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define qii vector<int>
#define qpii queue<pii>
#define umipii unordered_map<int,pii>
#define pqpii priority_queue<pair<int,int>>
#define vd vector<double>
#define vs vector<string>
#define vvs vector<vs>
#define vvi vector<vi>
#define uo_si unordered_set<int>
#define uo_ss unordered_set<string>
#define ll long long
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

class KthLargest1{
private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<>> pri_que;

public:
    KthLargest1(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (pri_que.size() < k) {
            pri_que.push(val);
        } else if (val > pri_que.top()) {
            pri_que.pop();
            pri_que.push(val);
        }
        return pri_que.top();
    }

};

class KthLargesst {
private:
    int k;
    std::vector<int> vecHeap;

public:
    KthLargesst(int k, std::vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (vecHeap.size() < k) {
            vecHeap.push_back(val);
            std::push_heap(vecHeap.begin(), vecHeap.end(), std::greater<int>());
        } else if (val > vecHeap[0]) {
            std::pop_heap(vecHeap.begin(), vecHeap.end(), std::greater<int>());
            vecHeap[k - 1] = val;
            std::push_heap(vecHeap.begin(), vecHeap.end(), std::greater<int>());
        }

        return vecHeap[0];
    }
};

class KthLargest {
public:
    int mp;
    std::priority_queue<int, vi, std::greater<>> pmk;

    KthLargest(int k, std::vector<int>& nums) {

        for (int num : nums) {
            pmk.push(num);
        }

        while (pmk.size() > k) {
            pmk.pop();
        }

        this->mp = k;

    }

    int add(int val) {
        pmk.push(val);
        if (pmk.size() > mp) {
            pmk.pop();
        }
        return pmk.top();
    }
};




int main() {



    return 0;
}

