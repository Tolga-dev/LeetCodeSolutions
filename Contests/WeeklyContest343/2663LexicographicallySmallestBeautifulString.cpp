//https://leetcode.com/problems/first-completely-painted-row-or-column/description/
#include <bits/stdc++.h>
using namespace std;

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

char a = 'a';
char ak;

string smallestBeautifulString(string s, int k) {
    int n = s.length();
    int i = n - 1;
    s[i]++;
    ak = (char)(a + k);

    while (i >= 0 && i < n)
    {
        if(s[i] >= ak)
        {
            s[i] = a;
            i--;
            if(i >= 0) s[i]++;
            else break;
        }
        else if((i - 2 >= 0 && s[i] == s[i-2]) || (i-1 >= 0 && s[i] == s[i - 1] ))s[i]++;
        else i++;
    }

    if (i == -1) {
        s = "";
    }

    return s;

}
int main()
{

}

/*
 *


 */
/*

*/

/*

*/
