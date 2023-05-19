#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/palindrome-partitioning/description/

#define v(t) vector<t>
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vi>
#define uo_si unordered_set<int>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")


bool check(string &s, int left, int right){
    while (left<right){
        if (s[left++] != s[right--]) return false ;
    }
    return true;
}
void solve (string &s, int curr_ind, vs &temp_arr,
            vector <vs> &sol, int size){

    if (curr_ind==size){
        sol.push_back(temp_arr);
        return;
    }

    for (int i=curr_ind; i<size; i++){
        if (check(s,curr_ind,i)){
            temp_arr.push_back(s.substr(curr_ind, i-curr_ind+1));
            solve (s,i+1,temp_arr,sol,s.length());
            temp_arr.pop_back();
        }
    }
}

vector<vs> partition(string s) {
    vector <vs> sol;
    vector <string> temp_arr;
    solve (s, 0, temp_arr, sol,s.size());
    return sol;
}


int main() {

    partition("aab");

//    for (auto s : ) {
//        for (string m : s) {
//            cout << m << " ";
//        }
//        cout << endl;
//    }

    return 0;
}