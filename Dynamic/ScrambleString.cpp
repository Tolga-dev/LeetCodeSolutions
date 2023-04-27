#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;

/// Time Limit Exceeded
/*bool isScramble(string s1, string s2) {

    if(s1.length() != s2.length()) return false;

    int n = s1.length();

    if(n == 0) return true;

    if(s1 == s2) return true;

    string s = s1, s0 = s2;

    sort(s.begin(),s.end());
    sort(s0.begin(),s0.end());

    if(s != s0) return false;

    for (int i = 1; i < n; ++i) {

        if (isScramble(s1.substr(0, i), s2.substr(0, i))
            && isScramble(s1.substr(i, n - i), s2.substr(i, n - i)))
            return true;
        if (isScramble(s1.substr(0, i), s2.substr(n - i, i))
            && isScramble(s1.substr(i, n - i), s2.substr(0, n - i)))
            return true;

    }
    return false;
}*/

unordered_map<string,bool> mp;
bool isScramble(string s1, string s2)
{
    int n = s1.size();
    if (s1 == s2)
    {
        return true;
    }
    vector a(26, 0), b(26, 0), c(26, 0);
    if (mp.count(s1 + s2))
    {
        return mp[s1 + s2];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int j = n - i;
        a[s1[i - 1] - 'a']++;
        b[s2[i - 1] - 'a']++;
        c[s2[j] - 'a']++;
        if (a == b && isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
        {
            mp[s1 + s2] = true;
            return true;
        }
        if (a == c && isScramble(s1.substr(0, i), s2.substr(j)) && isScramble(s1.substr(i), s2.substr(0, j)))
        {
            mp[s1 + s2] = true;
            return true;
        }
    }
    mp[s1 + s2] = false;
    return false;
}




int main()
{

    string s1 = "great", s2 = "rgeat";

    cout << isScramble(s1,s2) << endl;
}
