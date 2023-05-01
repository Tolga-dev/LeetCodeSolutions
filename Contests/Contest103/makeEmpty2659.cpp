//https://leetcode.com/problems/make-array-empty/
#include <bits/stdc++.h>
using namespace std;

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();


long long countOperationsToEmptyArray(vector<int>& nums) {
    const int n = nums.size();
    vector<int> ind(n);
    for (int i = 0; i < n; ++i) {
        ind[i] = i;
    }
    sort(ind.begin(), ind.end(), [&](const int x, const int y) {
        return nums[x] < nums[y];
    });

    for (auto s: ind) {
        cout << s << " ";
    }

    int m = n;
    long long r = 0;
    for (int i = 1, last = 0; i < n; ++i) {
        if (ind[i] < ind[i - 1]) {
            r += m;
            m -= i - last;
            last = i;
        }
    }
    r += m;
    return r;
}

int main()
{
    vector<int> grid1 = {3,4,-1};
//    vector<int> grid1 = {1,2,4,3};
//    vector<int> grid1 = {1,2,3};

    cout << countOperationsToEmptyArray(grid1) << endl;

}