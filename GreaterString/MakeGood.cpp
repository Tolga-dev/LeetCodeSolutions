#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/make-the-string-great/submissions/916300127/
string makeGood(string s) {

    string str = "";

    for (int i = 0; i < s.length(); ++i) {
        if( !str.empty() && (abs(str.back() - s[i]) == 0x20) ){
            str.pop_back();
        }else{
            str.push_back(s[i]);
        }
    }

    return str;

}
string makeGood2(string s)
{
    int n = s.size()-1;

    for(int i = 0 ; i < n ; i++) {
        if(abs(s[i] -s[i+1]) == 0x20 ){
            s.erase(i,2);
            i=-1;
            n-=2;
        }
    }
}

int main()
{

    cout << makeGood("abBAcC") << endl;
    cout << makeGood("leEeetcode") << endl;

}