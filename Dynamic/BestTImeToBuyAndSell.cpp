#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;

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

static int U_max(const int __a, const int& __b)
{
    if (__a < __b)
        return __b;
    return __a;
}
static int U_min(const int __a, const int& __b)
{
    if (__a > __b)
        return __b;
    return __a;
}

int maxProfit(vector<int>& prices,int profit = 0,int minPrice = INT_MAX) {
    if (prices.empty())
        return 0 ;

    for (int i = 0 ; i < prices.size(); i ++)
    {
        minPrice = U_min (minPrice, prices[i]) ;
        profit = U_max (profit, prices[i] - minPrice) ;
    }
    return profit ;

}

int main()
{

    vector<int> x = {2,1,4};

    cout << maxProfit(x) << endl;


}

