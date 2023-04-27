#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/merge-strings-alternately/

int w1_l = 0,w2_l = 0;
string mergeAlternately2(string word1, string word2) {
    w1_l = word1.length();
    w2_l = word2.length();
    string s = "";
    int i = 0;


    if(w1_l > w2_l)
    {
        for (; i < w2_l ; ++i) {
            s += word1[i];
            s += word2[i];
        }
        for (; i < w1_l ; ++i) {
            s += word1[i];
        }
        return s;
    }
    else if( w1_l == w2_l)
    {
        for (; i < w2_l ; ++i) {
            s += word1[i];
            s += word2[i];
        }
        return s;
    }
    else
    {

        for (; i < w1_l ; ++i) {
            s += word1[i];
            s += word2[i];
        }
        for (; i < w2_l ; ++i) {
            s += word2[i];
        }
        return s;
    }
}

string mergeAlternately(string word1, string word2) {
    string str;
    int i=0;
    while(i<min(word1.length(),word2.length()))
    {
        str=str+word1[i]+word2[i];
        i++;
    }
    if(i==word2.length())
        str+=word1.substr(i);
    else if(i==word1.length())
        str+=word2.substr(i);
    return str;
}

int main()
{

    cout << mergeAlternately("abc","pqr")<< endl;
    cout << mergeAlternately("ab","pqrs")<< endl;
    cout << mergeAlternately("abcd","pq")<< endl;


}