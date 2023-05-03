//https://leetcode.com/problems/row-with-maximum-ones/submissions/943930696/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define uosi vector<int>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

vector<int> row_AndMaximumOnes(vector<vector<int>>& mat) {
    int res=0, res_max=0;

    for(int i=0; i<mat.size(); i++) {
        int counter = 0;
        for(int j=0; j<mat[0].size(); j++)  if(mat[i][j] == 1)  counter++;
        if(counter > res_max)  {
            res_max = counter;
            res = i;
        }
    }

    return {res, res_max};
}
vector<int> rowAnd_MaximumOnes(vector<vector<int>>& mat) {
    int rows = mat.size();
    vector<int> ans(2, 0);
    for (int i = 0; i < rows; ++i) {
        int count = accumulate(mat[i].begin(), mat[i].end(), 0);
        if (count > ans[1]) {
            ans[0] = i;
            ans[1] = count;
        }
    }
    return ans;
}

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int ind = 0, res = 0;
    int mat_n = mat[0].size();
    int cnt = 0;
    for (int i = 0; i < mat.size(); ++i) {
        for(int j=0;j<mat_n;j++)
        {
            cnt+=mat[i][j];
        }

        if (cnt > res) {
            ind = i;
            res = cnt;
        }
        cnt = 0;
    }
    return {ind, res};
}

int main()
{
    vector<vi> nums1 = {{0,1,1},{0,1,1}};

    for (auto s : rowAndMaximumOnes(nums1)) {
        cout << s << " ";
    }
}
