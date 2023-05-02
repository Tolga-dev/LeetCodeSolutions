//https://leetcode.com/problems/calculate-delayed-arrival-time/description/
#include <bits/stdc++.h>
using namespace std;

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();


int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
    return (arrivalTime + delayedTime) % 24;
}

int main()
{


}