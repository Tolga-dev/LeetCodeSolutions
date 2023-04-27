#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum0(vector<int>& nums, int target) {
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for (int j = i+1; j < n; ++j) {
            if(nums[i] + nums[j] == target)  return {i,j};
        }

    }
    return {-1, -1};
}

vector<int> twoSum(vector<int>& nums, int target) {
    int s = nums.size();
    map<int,int> mp;
    for(int i=0;i<s;i++){
        if(mp[target-nums[i]]!=0)
            return {mp[target-nums[i]]-1,i};
        mp[nums[i]]=i+1;
    }
    return {-1,-1};

}


int main()
{
    vector<int> m = {2,7,11,15};

    cout << twoSum(m,9)[0] << " " << twoSum(m,9)[1];


}