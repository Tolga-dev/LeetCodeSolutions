#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/fibonacci-number/

///SOL1
int fibv(int n) {
    return(n==1 || n==2) ? 1 : fibv(n-1) + fibv(n-2);
}
int fib2(int n)
{
    return n == 0 ? 0 : fibv(n);
}

///SOL2
int fib(int n)
{
    if(n == 0 || n == 1) return n;
    int m[n+1];

    m[1] = 1;
    m[0] = 0;

    for (int i = 2; i <= n ; ++i) {
        m[i] = m[i-1] + m[i-2];
    }

    return m[n];

}


int main()
{
    cout << fib(4) << endl;
    cout << fib(0) << endl;

}
