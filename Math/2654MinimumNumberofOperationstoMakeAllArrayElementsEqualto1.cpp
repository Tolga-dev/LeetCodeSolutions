//https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
int size_s = 0;

int gcd(int a, int b)
{
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void precomputeGcd(vi& nums, vector<vi>& table,int size)
{
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if(i == j) table[i][j] = nums[i];
            else table[i][j] = gcd(table[i][j - 1], nums[j]);;
        }
    }
}

int min_pperations(vector<int>& nums) {

    int n=(int)nums.size();
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if(nums[i] == 1) count++;
    }
    if(count > 0) { return n - count;}

    vector<vi> gcdTable(n, vi(n));
    precomputeGcd(nums, gcdTable,n);
    int ans=1e7;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int g= gcdTable[i][j];
            if(g==1){
                ans=min(ans,j-i+(n-1)); // number of operations to make this element 1+ number of non ones (i.e. n-1) .
                break;
            }
        }
    }
    return ans==1e7?-1:ans;

}

int minOperations(vector<int>& nums) {

    int n=(int)nums.size();
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if(nums[i] == 1) count++;
    }
    if(count > 0) { return n - count;}
    
    int ans=INT_MAX;

    for(int i=0;i< n; i++)
    {
        int g = nums[i];
        for(int j=i+1; j<n; j++)
        {
            g= gcd(g, nums[j]);
            if(g==1)
            {
                ans= min(ans, (j-i));
            }
        }
    }

    if(ans==INT_MAX)
        return -1;

    return ans + n-1;
}

int main()
{
    vi nums = {1,1};
    cout << minOperations(nums) << endl;
//    cout << gcd(2,6) << endl;
//    cout << gcd(1,6) << endl;
//    cout << gcd(15,25) << endl;
}