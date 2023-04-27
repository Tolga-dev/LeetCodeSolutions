#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/reducing-dishes/

// SOL1
int maxSatisfaction0(vector<int>& satisfaction) {
    sort(satisfaction.begin(),satisfaction.end());
    int s = satisfaction.size();
    vector<vector<int>> ar(s+1,vector<int>(s+2,0));

    for (int i = s-1; i >= 0 ; i--) {
        for (int j = 0; j <= s; ++j) {
            ar[i][j] = max(satisfaction[i]*j + ar[i+1][j+1],ar[i+1][j]);
        }

        
    }
    return ar[0][0];
}
int maxSatisfaction1(vector<int>& vec) {
    sort(vec.begin(),vec.end());
    int res=0,sum=0;
    for(int i=vec.size()-1;i>=0;i--){
        res=max(res,res+sum+vec[i]);
        sum+=vec[i];
    }

    return res;

}
int maxSatisfaction(vector<int>& vec) {
    sort(vec.begin(), vec.end());
    int presum = 0, res = 0;

    for (int i = vec.size()-1; i >= 0; i--) {
        presum += vec[i];
        if (presum < 0) {
            break;
        }
        res += presum;
    }
    return res;

}


int main()
{

    vector<int>b = {-1,-8,0,5,-9};
    cout << maxSatisfaction(b) << endl;
}
