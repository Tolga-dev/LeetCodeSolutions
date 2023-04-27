#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/decode-ways/description/

// SOL 1
int numDecodings0(string s) {
    int n = s.size();
    int arr[n+1];
    arr[n] = 1;
    for (int i = n-1; i >=0 ; --i) {
        if(s[i] == '0') arr[i] = 0;
        else
        {
            arr[i] = arr[i+1];
            if(i < n-1 && (s[i] == '1' || s[i] == '2' && s[i+1] < '7'))
                arr[i] += arr[i+2];
        }

    }

    return arr[0];
}




int main()
{


    cout << numDecodings0("111065") << endl;

}

