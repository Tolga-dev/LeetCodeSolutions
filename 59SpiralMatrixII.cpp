#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
//https://leetcode.com/problems/matrix-diagonal-sum/description/
#define vi vector<int>
#define uosi vector<int>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")


vector<vector<int>> generateMatrix(int n) {
    vector<vi> mat(n, vi(n));

    int top = 0, left = top;
    int right = n - 1,bottom = right;
    int a = 1;

    while (top <= bottom && left <= right) {

        for(int i=left;i<=right;i++){//top

            mat[top][i]=a;
            a++;
        }
        top++;

        for(int i=top;i<=bottom;i++){//bottom
            mat[i][right]=a;
            a++;
        }
        right--;

        for(int i=right;i>=left;i--){//left
            mat[bottom][i]=a;
            a++;
        }
        bottom--;

        for(int i=bottom;i>=top;i--){//up
            mat[i][left]=a;
            a++;
        }
        left++;

    }

        return mat;

}

int main()
{

        for (auto s: generateMatrix(3)) {
            for (int i : s) {
                cout << i << " ";
            }
            cout << endl;

        }
    return 0;
}