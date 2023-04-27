//https://leetcode.com/problems/interleaving-string/
#include <iostream>
#include <string.h>
using namespace std;

#define ll long long
int bulsbSwitch(int n) {
    ll mn = 0, mx = n;
    while(mn <= mx){
        ll mid = (mn + mx) / 2;
        if(mid * mid == n)return mid;
        if(mid * mid <= n){
            mn = mid + 1;
        }else{
            mx = mid - 1;
        }
    }
    return mx;
}

constexpr int get(int n, int count = 0) {
    for (int i = 1; i <= n; i++) {
        if (i * i <= n) {
            count++;
        } else {
            break;
        }
    }
    return count;
}

int bulbSwitch(int n) {
    return get(n);
}


int main()
{
    cout << bulbSwitch(6) << endl;

}