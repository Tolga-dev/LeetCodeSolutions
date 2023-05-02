//https://leetcode.com/problems/sign-of-the-product-of-an-array/description/
#include <bits/stdc++.h>
using namespace std;

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

int array_Sign(vector<int>& nums) {
    bool asnw = false;

    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i] == 0) return 0;
        else if(nums[i] < 0) asnw = !asnw;
    }

    return asnw ? -1 : 1;
}

int arraySign(vector<int>& nums) {
    int anw = 1;

    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i] == 0) {
            return 0; 
        }
        else if(nums[i] < 0) {
            anw *= -1; 
        }
        else {
            anw *= 1;
        }
    }
    
    return anw == 1 ? 1 : -1; 
}


int main()
{
    vector<int> start = {-1,-2,-3,-4,3,2,1};
    cout << arraySign(start) << endl;

}