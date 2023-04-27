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

int maxProfit0(vector<int>& prices) {
    ios::sync_with_stdio(false);
    int n = prices.size();
    int ans = 0;
    stack<int>t;

    for (int i = 0; i < n; ++i) {
        if(t.empty()) t.push(prices[i]);
        else
        {
            if(t.top() < prices[i])
                ans += (prices[i] - t.top());
            else t.pop();
        }

        t.push(prices[i]);
    }

    return ans;
}
int maxProfit2(vector<int>& prices) {
    ios::sync_with_stdio(false);
    int n = prices.size();
    int ans = 0;

    for (int i = 1; i < n; ++i) {
        if(prices[i] > prices[i-1]) ans+=(prices[i]-prices[i-1]);
    }

    return ans;
}

int main()
{

    vector<int> x = {7,1,5,3,6,4};

    cout << maxProfit(x) << endl;


}

