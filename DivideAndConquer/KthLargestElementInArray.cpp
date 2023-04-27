#include <bits/stdc++.h>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
using namespace std;
//https://leetcode.com/problems/kth-largest-element-in-an-array/

// Basic Method
int findKthLargest0(vector<int>& nums, int k) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    std::sort(nums.begin(),nums.end());

    return nums[nums.size()-k];
}


/*int quickselect(vector<int>&nums, int l, int r, int k){
    if(l>=r) return nums[l];
    int pivot=nums[l+r>>1];
    int i=l-1,j=r+1;
    while(i<j){
        while(nums[++i]>pivot);
        while(nums[--j]<pivot);
        if(i<j)swap(nums[i],nums[j]);
    }
    int sl=j-l+1;
    if(k<=sl) return quickselect(nums,l,j,k);
    return quickselect(nums,j+1,r,k-sl);
}*/

int bs(vector<int> arr, int l, int r, int n)
{
    int mid;
    while(l < r){
        mid = l + (r-l)/2;

        if(arr[mid] <= n)
            l = mid + 1;
        else
            r = mid;
    }
    return l-1;
}

void Swapper(vector<int>& nums,int bg)
{

    int ind = bs(nums,0,nums.size(),bg);

    for (int i = ind; i > 0; --i) {
        swap(nums[i-1],nums[i]);
    }
    nums[ind] = bg;

}
// TIME LIMIT EXCEED
int findKthLargest4(vector<int>& nums, int k) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int size = nums.size();
    vector<int> ans(k,INT_MIN);
    for (int i = 0; i < size; ++i) {
        if(ans[0] < nums[i])
            Swapper(ans,nums[i]);

    }

    return ans[0];
}



void swap(vector<int> nums, int x, int y) {
    nums[y] ^= nums[x];
    nums[x] ^= nums[y];
    nums[y] ^= nums[x];
}
int partition(vector<int> nums, int left, int right, int ind) {
    int pivot = nums[ind];
    swap(nums, ind, right);
    ind = left;

    for (int i=left; i<=right; i++)
        if (nums[i] <= pivot)
            swap(nums, i, ind++);

    return ind - 1;
}

int quickSelect(vector<int> nums, int left, int right, int k) {
    if (left == right) return nums[left];

    srand(static_cast<unsigned int>(time(nullptr)));

    int ind = rand() % (right - left + 1) + left;

    ind = partition(nums, left, right, ind);

    if (ind == k) return nums[k];
    else if (ind < k) return quickSelect(nums, ind+1, right, k);
    return quickSelect(nums, left, ind-1, k);
}

// quick select
int findKthLargest(vector<int> nums, int k) {
    return quickSelect(nums, 0, nums.size()-1, nums.size()-k);
}



int main()
{
   vector<int>nums = {3,2,3,1,2,4,5,5,6};
//    vector<int>nums = {3,2,1};
    int k = 4;
    cout << findKthLargest(nums,k) << endl;



}

