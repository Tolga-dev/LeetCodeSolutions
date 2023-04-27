#include <iostream>

using namespace std;

int climbStairs(int n) {
    if(n<=1)
        return 1;

    return climbStairs(n-1)+climbStairs(n-2);
}
int climbStairs_alternative(int n)
{
    if(n == 0 || n == 1)
        return n;
    int p = 1, k = 1, c = 0;
    for(int i = 2; i <= n; i++)
    {
        c = p + k;
        p = k;
        k = c;
    }

    return k;
}
int climbStairs_alternative_2(int i)
{
    if(i == 0 || i == 1)
        return i;

    int a[2] = {1,1};

    while (i-- >= 2)
        a[i & 1] = a[0] + a[1];

    return a[1];

}

int main()
{

    cout << climbStairs_alternative_2(7) << endl;

}