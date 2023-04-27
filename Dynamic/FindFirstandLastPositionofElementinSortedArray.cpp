#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
#define ll long long

// sol1
vector<int> searchRange0(vector<int>& v, int target,int x =0,int y=0)
{
    if(v.empty()) return vector<int>{-1,-1};

    x = static_cast<int>((std::lower_bound (v.begin(), v.end(), target) - v.begin()));
    y = static_cast<int>((std::upper_bound(v.begin(), v.end(), target) - v.begin()));

    return x == y ?vector<int>{-1,-1} : vector<int>{x,y-1};

}

// sol2
vector<int> searchRange0(vector<int>& nums, int target)
{

    vector<int> pos;
    int low = 0;

    int high = nums.size()-1;
    int size_temp = high;
    int ans = -1;
    int mid;
    while(low<=high) {
        mid = (high + low)/2;
        if(nums[mid]<target)
            low = mid + 1;
        else if(nums[mid]>target)
            high = mid - 1;
        else {
            if(mid-1>=0 && nums[mid-1]==target)
                high = mid - 1;
            else {
                ans = mid;
                break;
            }
        }
    }
    pos.emplace_back(ans);
    low = 0;
    high = size_temp;
    ans = -1;
    while(low<=high) {
        mid = (high + low)/2;
        if(nums[mid]<target)
            low = mid + 1;
        else if(nums[mid]>target)
            high = mid - 1;
        else {
            if(mid+1<size_temp+1 && nums[mid+1]==target)
                low = mid + 1;
            else {
                ans = mid;
                break;
            }
        }
    }
    pos.emplace_back(ans);
    return pos;

}

// sol3
vector<int> searchRange2(vector<int>& nums, int target)
{
    if(nums.empty()) return {-1, -1};
    vector<int> res;
    int i = 0, j = nums.size() - 1, mid = 0;
    while(i <= j) {
        mid = i + (j - i) / 2;
        if(target <= nums[mid]) {
            j = mid - 1;
        }else {
            i = mid + 1;
        }
    }
    res.emplace_back(j + 1);
    j = nums.size() - 1;
    while(i <= j) {
        mid = i + (j - i) / 2;
        if(target >= nums[mid]) {
            i = mid + 1;
        }else {
            j = mid - 1;
        }
    }
    res.emplace_back(i -1);

    if(res[0] > res[1]) {
        return {-1, -1};
    }
    return res;

}

// sol4
int f(vector<int> nums,int x, int n, int l,int h, int rr)
{

    while(l <= h)
    {
        int mid = (l + h) / 2;

        if(nums[mid] > x)
            h = mid - 1;
        else if(nums[mid] < x)
            l = mid + 1;
        else
        {
            rr = mid;
            h = mid -1;
        }
    }
    return rr;
}
int lt(vector<int> nums,int x, int n, int l,int h, int rl)
{

    while(l <= h)
    {
        int mid = (l + h) / 2;

        if(nums[mid] > x)
            h = mid - 1;
        else if(nums[mid] < x)
            l = mid + 1;
        else
        {
            rl = mid;
            l = mid  + 1;
        }
    }
    return rl;
}
vector<int> searchRange(vector<int>& nums, int target)
{
    int n = nums.size();
    if(n == 1 && nums[n-1] == target) return vector<int>{0,0};
    return vector<int>{f(nums, target, n,0,n-1,-1),lt(nums, target, n,0,n-1,-1)};
}



int main()
{
    vector<int> nums = {2}; int target = 2;

    for (auto s: searchRange(nums,target)) {
        cout << s << " ";
    }


}