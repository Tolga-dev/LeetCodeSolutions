#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/longest-palindromic-substring/description/


bool reversCheck(string &s, int i, int j){
    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
//brute force
string longestPalindrome0(string s) {
    int n = s.size();
    int max = 1, start = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(reversCheck(s,i,j) && j - i + 1> max)
            {
                max = j - i + 1;
                start = i;
            }

        }
    }

    return s.substr(start,max);
}

// memorization brute force
string longestPalindrome02(string s) {
    int n = s.size();
    vector<string> subs;

    for (int i = 0; i < n; ++i) {
        string temp = "";
        for (int j = i; j < n; ++j) {
                temp += s[j];
                subs.push_back(temp);
        }
    }
    int max = 0;
    string final = subs[0];
    int m = subs.size();

    for (int i = 0; i < m; ++i) {
        int s = subs[i].size();
        if(reversCheck(subs[i],0,s-1))
        {
            if(s > max)
            {
                max= s;
                final = subs[i];
            }
        }

    }
    return final;
}

int dp[1001][1001];
int solve(int i, int j, string &s){
    if(i == j){
        return dp[i][j] = 1;
    }
    if(j-i == 1){
        if(s[i] == s[j]){
            return dp[i][j] = 1;
        }
        else{
            return dp[i][j] = 0;
        }
    }
    if(s[i] == s[j] && dp[i+1][j-1] == 1){
        return dp[i][j] = 1;
    } else {
        return dp[i][j] = 0;
    }
}
string longestPalindrome2(string s) {
    int n = s.size();
    int startIndex = 0; int maxlen = 0;
    memset(dp, 0, sizeof(dp));
    for(int g=0; g<n; g++){
        for(int i=0, j=g; j<n; i++, j++){
            solve(i, j, s);
            if(dp[i][j] == 1){
                if(j-i+1 > maxlen){
                    startIndex = i;
                    maxlen = j-i+1;
                }
            }
        }
    }
    return s.substr(startIndex, maxlen);
}

// odd even
string longestPali1ndrome(string s) {
    int m = s.length(), pos = 0, len = 1, h = 0, l =0;

    for (int i = 1; i < m; ++i) {
        l = i;
        h = i -1;

        while(l >= 0 && h < m && s[l] == s[h] )
        {
            if(len < h - l +1)
            {
                pos = l;
                len = h - l +1;
            }
            l--,h++;
        }

        l=i-1;
        h=i+1;
        while(l >= 0 && h < m && s[l] == s[h] )
        {
            if(len < h - l +1)
            {
                pos = l;
                len = h - l +1;
            }
            l--,h++;
        }

    }
    return s.substr(pos,len);
}

string longestPalindromicSubstring(string s) {
    int n = s.size();
    int len = 0;
    int l = 0, h = 0;
    for (int i = 0; i < n; i++) {
        // odd length palindromes
        len = 0;
        while (i-len >= 0 && i+len < n && s[i-len] == s[i+len]) {
            len++;
        }
        if (2*len-1 > l) {
            l = 2*len-1;
            h = i-len+1;
        }
        // even length palindromes
        len = 0;
        while (i-len >= 0 && i+len+1 < n && s[i-len] == s[i+len+1]) {
            len++;
        }
        if (2*len > l) {
            l = 2*len;
            h = i-len+1;
        }
    }
    return s.substr(h, l);
}


    int main()
{

    cout << longestPalindromicSubstring("baba")<< endl;


}