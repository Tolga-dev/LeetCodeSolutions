#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/super-pow/
/*
#pragma GCC target("avx,mmx,sse2,sse3,sse4")
#pragma GCC optimize (-O3, -flto, -ffast-math, -march=native, -mtune=native)

static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
*/


int power2(int a, int b, int m){
    a %= m;
    int ans = 1;
    while(b>0){
        if(b&1){
            ans = (ans * 1LL * a) % m;
        }
        a = (a*1LL*a) % m;
        b>>=1;
    }
    return ans;

}
int superPow2(int a, vector<int>& b) {
    int ans = 0;

    for (int i = 0; i < b.size(); ++i) {
        ans = (ans * 10 + b[i]) % 1140;
    }
    return power2(a, ans,1337);
}

int main()
{

    int a = 2;
    vector<int> n = {3};

    cout << superPow(a,n) << endl;


}

