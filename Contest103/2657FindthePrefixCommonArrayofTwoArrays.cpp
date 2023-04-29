//https://leetcode.com/problems/make-array-empty/
#include <bits/stdc++.h>
using namespace std;

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

vector<int> findThePrefixCommonArsray(vector<int>& A, vector<int>& B) {
    const int n = A.size();
    unordered_set<int> s;
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        s.insert(A[i]);
        for (int j = 0; j <= i; ++j) {
            r[i] += s.count(B[j]);
        }
    }
    return r;
}

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size(), i, j, k, c = 0;
    vector<int> ans(n, 0);
    map<int, int> ct;

    for (i = 0; i < n; i++) {
        if (++ct[A[i]] == 2) c++;
        if (++ct[B[i]] == 2) c++;
        ans[i] = c;
    }
    return ans;
}

int main()
{
    vector<int> A = {1,3,2,4}, B = {3,1,2,4};
    for (auto s: findThePrefixCommonArray(A,B)) {
        cout << s << " ";
    }

}