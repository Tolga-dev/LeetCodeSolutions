//https://leetcode.com/problems/word-break/
#include <bits/stdc++.h>
using namespace std;

bool worsdBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    bool dp[n+1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;

    int max_word_len = 0;
    for (string word : wordDict) {
        max_word_len = max(max_word_len, (int)word.length());
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0 && j >= i - max_word_len; j--) {
            if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

bool worsddBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (string word : dict) {
            int word_length = word.length();
            if(i >= word_length)
                cout << i << " " << s.substr(i - word_length, word_length) << endl;

            if (i >= word_length && s.substr(i - word_length, word_length) == word && dp[i - word_length]) {
                dp[i] = true;
                break;
            }
        }
        cout << endl;
    }
    return dp[n];

}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(),wordDict.end());
    int n = s.length();
    vector<bool> dp(n+1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for(auto word : dict)
        {
            int m = word.length();
            if(i >= m && s.substr(i-m,m) == word && dp[i - m])
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {

    string s1 = "catsandog"; vector<string> wordDict1 = {"cats","dog","sand","and","cat"};
    string s = "applepenapple"; vector<string> wordDict = {"apple","pen"};
    cout << wordBreak(s,wordDict);

}