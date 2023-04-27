#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/minimize-maximum-of-array/


int minimizeArrayValue0(vector<int>& nums,long ans =0, int sum = 0) {

    for(int i=0;i<nums.size();sum+=nums[i],i++)
        if(nums[i]>ans)ans=max(ans,(long )ceil((double)(sum+nums[i])/(i+1)));

    return (int)ans;
}

int minimizeArrayValue1(vector<int>& nums,long ans =0, long sum = 0) {

    for(int i=0; i<nums.size(); i++)
    {
        sum += nums[i];
        ans = max(ans, (sum + i) / (i+1));
    }
    return (int)ans;

}

// wrong answer?
int minimizeArrayValue3(vector<int>& nums,long ans =0, long sum = 0) {
    ans = nums[0];
    sum = nums[0];

    for(long i=1; i<nums.size(); i++){
        sum += nums[i];
        ans = max(ans, (long)ceil(sum/(i+1)));
    }

    return (int)ans;
}

int minimizeArrayValue(vector<int>& nums,long long  int ans =0, long long int  sum = 0) {
    ans = nums[0];
    sum = nums[0];

    for(int i=1;i<nums.size();i++){
        sum+=nums[i];
        ans=max(ans,(sum+i)/(i+1));
    }

    return (int)ans;
}

int main()
{
    vector<int> nums = {3,7,1,6};
    vector<int> nums2 = {6,9,3,8,14};

    cout << minimizeArrayValue3(nums) << endl;

}