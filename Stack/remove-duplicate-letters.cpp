#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/remove-duplicate-letters

string removeDuplicateLetters0(string s) {
    int n = s.size();
    unordered_map<char, int> data;
    unordered_map<char, bool> visited;
    stack<int> st;
    string ans;

    for(char ch:s)	data[ch]++;

    for(int i = 0; i < n; i++){
        data[s[i]]--;
        if(visited[s[i]])	continue;

        while(!st.empty() &&  s[i] < s[st.top()] && data[s[st.top()]] > 0){
            visited[s[st.top()]] = false;
            st.pop();
        }
        st.push(i);
        visited[s[i]] = true;
    }

    while(!st.empty()){

        ans = s[st.top()] + ans;
        st.pop();
    }

    return ans;
}

string removeDuplicateLetters(string s) {

    vector<int> fre(26,0)  , vis(26,0);

    string ans = "";
    int n = s.size();

    for(int i = 0; i<n; ++i)
        fre[s[i] - 'a']++;

    for(int i = 0; i<n; ++i)
    {
        // decrease fre of current character
        fre[s[i] - 'a']--;

        // If character is not already
        // in answer
        if(!vis[s[i]- 'a'])
        {
            // Last character > s[i]
            // and its count > 0
            while(ans.size() > 0 && ans.back() > s[i] && fre[ans.back() - 'a'] > 0)
            {
                // marking letter visited
                vis[ans.back() - 'a'] = 0;
                ans.pop_back();
            }

            // Add s[i] in ans and
            // mark it visited
            ans += s[i];
            vis[s[i] - 'a'] = 1;
        }
    }
    // return ansultant string
    return ans;

}


int main()
{

    string s = "bcabc";

    cout << removeDuplicateLetters(s) << endl;

    return 0;
}