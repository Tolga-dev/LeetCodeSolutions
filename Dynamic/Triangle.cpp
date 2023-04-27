//https://leetcode.com/problems/triangle/
#include <bits/stdc++.h>
using namespace std;

int calc2(int n, int i, int j, vector<vector<int>>& triangle) {
    if(n - 1 == i) return triangle[i][j];

    int v1 = triangle[i][j] + calc2(n,i+1,j,triangle);
    int v2 = triangle[i][j] + calc2(n,i+1,j+1,triangle);

    return min(v1,v2);
}
//Will Give TLE
int minimumTo5tal(vector<vector<int>>& triangle) {
    return calc2((int)triangle.size(), 0, 0, triangle);
}

int calc(int n, int i, int j, const vector<vector<int>>& triangle, vector<vector<int>>& memo) {
    int& res = memo[i][j];
    if (res != -1) {
        return res;
    }
    if (n - 1 == i) {
        return res = triangle[i][j];
    }
    res = triangle[i][j] + min(calc(n,i+1,j,triangle, memo), calc(n,i+1,j+1,triangle, memo));
    return res;
}

int minimumTsotal(vector<vector<int>>& triangle) {
    const int n = triangle.size();
    vector<vector<int>> memo(n, vector<int>(n,-1));
    return calc(n, 0, 0, triangle, memo);
}

int minimumuTotal(vector<vector<int>>& arr) {
    int ind = arr.size();
    vector<int> data = arr[ind-1];

    for(int i = ind-2 ; i>=0 ; i--)
    {
        for(int j = 0 ; j<=i ; j++)
        {
            data[j] = arr[i][j] +  min(data[j] , data[j+1]);
        }
    }
    return data[0];
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>>dp(2, vector<int>(n));

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {

            if(i==n-1)
            {
                dp[(n-1)%2][j] = triangle[n-1][j];
            }
            else
            {
                int up = triangle[i][j] + dp[(i+1)%2][j];
                int up_left = triangle[i][j] + dp[(i+1)%2][j+1];
                dp[i%2][j] = min(up, up_left);
            }

        }
    }
    return dp[0][0];
}

int main() {
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout <<     minimumTotal(triangle);
}