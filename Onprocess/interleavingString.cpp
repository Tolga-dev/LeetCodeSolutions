//https://leetcode.com/problems/interleaving-string/
#include <iostream>
#include <string.h>
using namespace std;
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

int arr[101][101];
int v1,v2,v3;
bool maker(const string& s1, const string& s2, const string& s3,int i, int j)
{
    if(i >= v1 && j >= v2 && i + j >= v3) return true;

    if(i + j >= v3) return false;

    if(arr[i][j] != -1) return arr[i][j];


    return arr[i][j] = ((s1[i]==s3[i+j] && maker(s1, s2, s3, i+1, j)) || 
            (s2[j]==s3[i+j] && maker(s1, s2, s3, i, j+1)));
}

bool isInterleave(const string& s1, const string& s2, const string& s3) {
    memset(arr, -1, sizeof(arr));
     v1 = s1.length();
     v2 = s2.length();
     v3 = s3.length();

    if(v1 + v2 != v3) return false;

    return maker(s1,s2,s3,0,0);
}



int main()
{
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    cout << isInterleave(s1,s2,s3) << endl;
    s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
    cout << isInterleave(s1,s2,s3) << endl;

}