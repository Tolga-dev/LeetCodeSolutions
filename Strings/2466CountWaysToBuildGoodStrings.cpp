#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/count-ways-to-build-good-strings/
#define vi vector<int>
#define uosi vector<int>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

int moder = 1000000007;

int countGoodStrings(int low, int high, int zero, int one) {
    int memory[high+1];
    memset(memory, 0, sizeof(memory));
    memory[0]=1;
    int ans=0;
    for(int i=1;i<=high;i++){
        memory[i] = ((i-zero>=0 ? memory[i-zero]:0)+(i-one>=0 ? memory[i-one]:0))%moder;
        if(i>=low){
            ans = (ans+memory[i])%moder;
        }
    }
    return ans;
}


int main()
{

    cout << countGoodStrings(2,3,1,2) << endl;


    return 0;
}