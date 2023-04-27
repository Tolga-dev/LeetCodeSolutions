#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/water-and-jug-problem/

int gcd_user (int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {

    if(targetCapacity == 0)
        return true;
    else if(targetCapacity > jug1Capacity + jug2Capacity)
        return false;
    else
    {
        return targetCapacity % gcd_user(jug1Capacity,jug2Capacity) == 0;
    }

}

int main()
{

    int jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4;

    cout << canMeasureWater(jug1Capacity,jug2Capacity,targetCapacity) << endl;


}


