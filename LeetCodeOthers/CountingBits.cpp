#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/counting-bits/description/

vector<int> countBits0(int n) {
    vector<int> s(n+1,0);
    int sum = 0;
    int tn = 0;

    for (int i = 0; i <= n; ++i,sum = 0,tn = i) {

        while(tn != 0)
        {
            sum += tn % 2;
            tn /= 2;
        }
        s[i] = sum;
    }

    return s;
}

vector<int> countBits2(int n) {
    vector<int> s(n+1,0);

    for (int i = 1; i <= n; ++i) {
        if(i%2 == 0) s[i] = s[i/2];
        else s[i] = i%2 + s[i/2];
    }
    return s;
}

vector<int> countBits(int n) {
    vector<int> ans(n + 1, 0);

    ans[0] = 0;

    for (int i = 1; i <= n; i++)
        ans[i] = __builtin_popcount(i);

    return ans;
}

int main()
{

    for (auto i : countBits2(2)) {
        cout<< i << " ";
    }
    cout<< endl;
    for (auto i : countBits2(5)) {
        cout<< i << " ";

    }

}