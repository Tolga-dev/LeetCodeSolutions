//https://leetcode.com/problems/first-completely-painted-row-or-column/description/
#include <bits/stdc++.h>
using namespace std;

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();


int firstCompsleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    unordered_map<int, int> mpr, mpc, mprc, mpcc;
    int msize = mat.size();
    int colsize = mat[0].size();

    for(int i = 0; i < msize; i++){
        for(int j = 0; j< colsize; ++j){
            mpr[mat[i][j]] = i;     mpc[mat[i][j]] = j;
        }
    }

    for(int i = 0; i < arr.size(); i++){

        mprc[mpr[arr[i]]]++;
        mpcc[mpc[arr[i]]]++;
        if(mprc[mpr[arr[i]]] ==colsize || mpcc[mpc[arr[i]]] == msize) return i;
    }
    return -1;
}


int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
{
    int size_r = mat.size();
    int size_c = mat[0].size();

    unordered_map<int, pair<int,int>> pos;
    for(int i=0;i<size_r;i++)
    {
        for(auto it = mat[i].begin(); it != mat[i].end(); ++it)
        {
            pos[*it] = {i, it - mat[i].begin()};
        }
    }

    vector<int> r(size_r,0), c(size_c,0);

    for(int i=0; i<arr.size(); i++)
    {

        r[pos[arr[i]].first] += 1;
        c[pos[arr[i]].second] += 1;

        if(r[pos[arr[i]].first] == size_c || c[pos[arr[i]].second] == size_r)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1,3,4,2};
    vector<vector<int>> mat = {{1,4},{2,3}};
    cout << firstCompleteIndex(arr,mat) << endl;

}
