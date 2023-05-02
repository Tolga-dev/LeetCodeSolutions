//https://leetcode.com/problems/calculate-delayed-arrival-time/description/
#include <bits/stdc++.h>
using namespace std;

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

int sumOfMultiples(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if(i % 3 == 0)
        {
            sum += i;
            continue;
        }
        else if(i % 5 == 0)
        {
            sum += i;
            continue;

        }
        else if(i % 7 == 0)
        {
            sum += i;
            continue;
        }
    }
    return sum;
}

int main()
{


}