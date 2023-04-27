#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;


int reverse0(int x) {
    int ans=0;
    while(x!=0)
    {
        if (ans > INT_MAX/10 || (ans == INT_MAX / 10 && x > 7)) return 0;
        if (ans < INT_MIN/10 || (ans == INT_MIN / 10 && x < -8)) return 0;
        ans=ans*10+x%10;
        x=x/10;
    }
    return ans;

}

int reverse(int x) {
    if(x==INT_MIN)
        return 0;
    int r=0;
    int ch = 1;

    if(x<0)
    {
        x=x*(-1);
        ch = 0;
    }

    while(x!=0){
        if( r>(INT_MAX/10) || r>( (INT_MAX/10)+x%10) )
            return 0;
        r=r*10 + x%10;
        x=x/10;
    }
    if(ch == 0)
        return r*(-1);
    return r;
}


int main()
{
    int m = (pow(2,29)-2);
    cout << reverse(-321) << endl;


}

