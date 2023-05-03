//https://leetcode.com/problems/minimum-additions-to-make-valid-string/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define uosi vector<int>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

char chars[3] = {'a','b','c'};

int addMinimum(string word) {

    int result = 0;
    int i = 0;

    while(i<word.size()){
        if(word[i] == chars[0]){
            if(word[i+1] == chars[1] && word[i+2] == chars[2]){
                i+=3;
            }
            else if(word[i+1] == chars[1]){
                result++;
                i+=2;
            }
            else if(word[i+1] == chars[2]){
                result++;
                i+=2;
            }
            else if(word[i+1] ==chars[0]){
                result+=2;
                i++;
            }
            else{
                result+=2;
                i++;
            }
        }
        else if(word[i] == chars[1]){
            if(word[i+1] == chars[2]){
                result++;
                i+=2;
            }
            else{
                result+=2;
                i++;
            }
        }
        else
        {
            result+=2;
            i++;
        }
    }
    return result;
}

int main()
{
    cout << addMinimum("aaa") << endl;



}
