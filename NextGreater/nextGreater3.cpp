#include <bits/stdc++.h>
using namespace std;

int nextGreaterElement2(int n) {
    auto digits = to_string(n);
    next_permutation(begin(digits), end(digits));
    auto ans = stoll(digits);
    return (ans > 0x7FFFFFFF || ans <= n) ? -1 : ans;
}


int main()
{
    cout << nextGreaterElement2(12348)<<endl;

    return 0;

}