#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums)
{
    int i = 1;
    int j = nums.size() - 1;

    for (; i < j ; i += 2) {
        if((nums[i-1] ^ nums[i]) == 0) return nums[i-1];
    }

    return nums[i-1];
}
int singleNonDuplicate4(vector<int>& nums)
{
    int b = 0;
    for (int i = 0; i < nums.size(); ++i) {
        b = b ^ nums[i];
    }
    return b;
}


int singleNonDuplicate3(vector<int>& nums)
{
    int ans = 0;
    for (auto it: nums)
    {
        ans = ans ^ it;

        cout << ans << endl;
    }
    return ans;

}

int singleNonDuplicate2(vector<int>& nums)
{
    int l=0,r=nums.size()-1;

    while(l<r){
        int mid=(l+r)/2;

        if(mid%2==0)
            if(nums[mid]==nums[mid+1])l=mid+1;
            else r=mid;
        else
            if(nums[mid]!=nums[mid+1])l=mid+1;
            else r=mid;
    }

    return nums[l];

}

int main()
{
    vector<int> k = {1,2,2,3,3};
    cout << singleNonDuplicate(k) << endl;

}