#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
//https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vb vector<bool>
#define qii vector<int>
#define qpii queue<pii>
#define umipii unordered_map<int,pii>
#define pqpii priority_queue<pair<int,int>>
#define vd vector<double>
#define vs vector<string>
#define vvs vector<vs>
#define uo_si unordered_set<int>
#define uo_ss unordered_set<string>
#define ll long long
static const int ____ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

int minx(const int& _a, const int& _b)
{
    if (_a > _b)
        return _b;
    return _a;
}

int maxx(const int& _a, const int& _b)
{
    if (_a < _b)
        return _b;
    return _a;
}
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // answer vector
        vector<string> ans;

        // a storage variable to store if the elements in the array are continuous
        // for example, 1,2,3
        // in this case, it will store the index of 1
        int continuous = -1;

        // we don't traverse till the last element in this solution.
        // we travel only till the n - 1 element
        // to prevent the last element from missing the traversal, we add this value
        nums.push_back(INT_MIN);

        for (int i = 0; i < nums.size() - 1; i++) {
            // checks if the continuous variable currently doesn't hold any index
            // that means a continuous range hasn't appeared yet
            // then, we store the index of the first element in this variable, if such index appears
            if ((long) nums[i + 1] - nums[i] == 1 && continuous == -1) {
                continuous = i;
            }

                // a continuous range is there, and it continues
                // we do nothing, and continue the traversal
            else if ((long) nums[i + 1] - nums[i] == 1 && continuous != -1) {
                continue;
            }

            else {
                // continuous to be equal to -1 means variables not appearing in a chain.
                // example - 0,1,2,7,8,9
                // in this case, 7 matches this condition
                // we push 7 in the result
                if (continuous == -1) {
                    ans.push_back(to_string(nums[i]));
                }

                    // a continuous range existed till now, but got broken
                    // push the starting index of the range and the current i
                else {
                    ans.push_back(to_string(nums[continuous]) + "->" + to_string(nums[i]));
                    continuous = -1;
                }
            }
        }

        return ans;
    }
};
int main() {

    vi nums = {0,1,2,4,5,7};

}



