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

int diagonalSum(vector<vector<int>>& arr) {
    int n = arr.size() , res =0;

    for(int i=0;i<n;i++){

        res+=arr[i][i];

        if( i != n-i-1)
            res+=arr[i][n-i-1];
    }
    return res;
}

int diagonal_Sum(vector<vector<int>>& mat) {
    int size = mat.size()-1;
    int my_result_x_Y = 0;

    if(size%2 == 0)
    {
        for (int i = 0; i < size+1; ++i) {
            my_result_x_Y += mat[i][i];
            my_result_x_Y += mat[i][size - i];
        }
        my_result_x_Y -= mat[size/2][size/2];

    }
    else
    {
        for (int i = 0; i < size+1; ++i) {
            my_result_x_Y += mat[i][i] + mat[i][size - i] ;

        }

    }

    return my_result_x_Y;
}


int main()
{


    vector<vector<int>> mat = {{7,3,1,9},
                               {3,4,6,9},
                               {6,9,6,6},
                               {9,5,8,5}};

    cout << diagonalSum(mat) << endl;

}