#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/bitwise-xor-of-all-pairings/

/// time limit exceed
int xorAllNums4(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int cv = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cv ^= (nums1[i] ^ nums2[j]);

    return  cv;
}

int xorAllNums3(vector<int>& nums1, vector<int>& nums2) {
    int xorResult = 0;
    for (int num1 : nums1) {
        xorResult ^= num1; // XOR all elements in nums1
    }
    for (int num2 : nums2) {
        xorResult ^= num2; // XOR all elements in nums2
    }
    return xorResult;
}


int xors(vector<int>& nums){
    int val = nums[0];
    for(int i = 1; i < nums.size(); i++){
        val ^= nums[i];
    }
    return val;
}
int xorAllNums2(vector<int>& nums1, vector<int>& nums2) {
    int a1 = nums1.size() % 2;
    int a2 = nums2.size() % 2;
    if( a1 == 0 && a2 == 0) return 0;
    if( a1 == 0) return xors(nums1);
    if( a2 == 0) return xors(nums2);
    return xors(nums1) ^ xors(nums2);
}

int xorAl2lNums3(vector<int>& nums1, vector<int>& nums2) {
    int vla = 0;

    if(nums1.size() % 2 == 1)
    {
        for(int i = 0; i < nums2.size(); i++){
            vla ^= nums2[i];
        }
    }

    if(nums2.size() % 2 == 1)
    {
        for(int i = 0; i < nums1.size(); i++){
            vla ^= nums1[i];
        }
    }
    return vla;
}


int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int r = 0;
    int a1 = nums1.size() % 2;
    int a2 = nums2.size() % 2;

    if(a1 == 1)
    {
        for(int i:nums2)
            r = r^i;
    }
    if(a2 == 1)
    {
        for(int i:nums1)
            r = r^i;
    }

    return r;

}

int main()
{
//    vector<int> nums1 = {1,2}, nums2 = {3,4};
    vector<int> nums1 = {2,1,3}, nums2 = {10,2,5,0};
    cout << xorAllNums(nums1, nums2) << endl;

}