#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/bitwise-and-of-numbers-range/


int rangeBitwiseAnd5(int left, int right) {
    int shift = 0;

    // Right-shift left and right until they become equal
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    // Left-shift left by the number of positions we right-shifted

    return left << shift;
}
int rangeBitwiseAnd(int left, int right) {
    while(right > left) {
        right = right & (right-1);
    }
    return right;
}

int main()
{

    cout << rangeBitwiseAnd(5,7) << endl;
    cout << rangeBitwiseAnd(0,0) << endl;
    cout << rangeBitwiseAnd(1,2147483647) << endl;



}