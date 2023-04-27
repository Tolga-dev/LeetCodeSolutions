#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/removing-stars-from-a-string/

string removeStars0(string s) {
    std::stack<char> st;
    string s2;
    for (int i = 0; i < s.length(); ++i) {
           if(s[i] != '*')
               st.push(s[i]);
           else
               st.pop();
    }
    while(!st.empty())
    {
        s2 += st.top();
        st.pop();
    }
    reverse(s2.begin(), s2.end());
    return s2;

}
string removeStars1(string s) {
    string s2;

    for (char c : s) {
        if (c == '*') {
            if (!s2.empty()) { // Ensure s2 is not empty before removing a character
                s2.pop_back(); // Remove the closest non-star character to the left
            }
        } else {
            s2 += c; // Append to s2 if not a '*'
        }
    }
    return s2;
}

string removeStars(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    std::string s2;

    for (int i = 0; i < s.length(); ++i) {
        if(s[i] != '*')
            s2.push_back(s[i]);
        else
            s2.pop_back();
    }

    return s2;

}

int main()
{

    string s = "leet**cod*e";

    cout << removeStars(s) << endl;

}


