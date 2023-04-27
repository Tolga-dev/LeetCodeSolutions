// problem https://leetcode.com/problems/gray-code/description/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

std::vector<int> GrayCode(int n)
{
    std::vector<int> Gray;
    for(int i=0; i < (1<<n) ; i++ )
    {
        Gray.push_back(i^(i>>1));
    }

    return Gray;

}

int main() {

//    GrayCode(16);

    return 0;
}
