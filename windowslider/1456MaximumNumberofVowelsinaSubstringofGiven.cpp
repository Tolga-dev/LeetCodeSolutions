//https://leetcode.com/problems/row-with-maximum-ones/submissions/943930696/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define uosi vector<int>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

inline bool check(char& c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(string s, int k) {

    int count=0;
    for(int i=0;i<k;i++){
        if(check(s[i]))count++;
    }
    int ans=count;
    int i=0,j=k;
    while(j<s.size()){
        if(check(s[j]))count++;
        if(check(s[i]))count--;
        ans=max(ans,count);
        j++;
        i++;
    }
    return ans;
}

int main()
{
    cout << maxVowels("abciiidef",3) << endl;

}
