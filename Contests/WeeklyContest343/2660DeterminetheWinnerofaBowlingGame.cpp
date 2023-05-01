//https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/
#include <bits/stdc++.h>
using namespace std;

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

char a = 'a';
char ak;

string smallestBeautifulString(string s, int k) {
    int n = s.length();
    string ans(n, 'a');

    for (int i = 0; i < n; i++) {
        if (i >= 2 && ans[i-1] == ans[i-2]) {
            // sliding window contains the same character
            char c = ans[i-1] + 1;
            while (c - 'a' < k && (i < 3 || (c != ans[i-3] && c != ans[i-2]))) {
                ans[i] = c;
                c++;
            }
            if (c - 'a' == k) {
                ans = "";
                break;
            }
        }
    }

    return ans;

}

int main()
{
    string s = "abcz";int k = 4;
    cout << smallestBeautifulString(s,k) << endl;


}