#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/regular-expression-matching/
//https://leetcode.com/problems/regular-expression-matching/solutions/191830/java-dp-solution-beats-100-with-explanation/
bool isMatch(string s, string p) {
    int s1 = s.length();
    int p1 = p.length();

    for (int i = 0; i < s1; ++i) {
        if(p[i] == '.') continue;

    }

    return false;
}


int main()
{


    cout << isMatch("aa","a") << endl;
    cout << isMatch("aa","a*") << endl;
    cout << isMatch("ab",".*") << endl;

}