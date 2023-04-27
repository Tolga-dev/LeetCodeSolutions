#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/count-complete-tree-nodes/

/*public boolean canJump(int[] nums) {
    int i=nums.length,curr=nums.length-1;
    while(i-->1 ){
        if((i-1)+nums[i-1]<curr) continue;
        curr=i-1;
    }p
    return curr==0;
}*/
/*const canJump = (nums, i=0, index=nums.length-1) => {
if(index <= 0) return nums[0] >= i
return canJump(nums, nums[index] >= i ? 1 : i+1, index-1)
}*/

int U_max(const int __a, const int& __b)
{
    if (__a < __b)
        return __b;
    return __a;
}

bool canJump(vector<int>& nums, int m=0, unsigned long size=0) {

    size = nums.size();
    for(int i=0;i<size;i++){
        m = U_max(m,nums[i]+i);

        if(m <  i+1){
            break;
        }
    }
    return m>=size-1;

}

int main()
{
    vector<int> can = {1,1,2,2,0,1,1}; //1
    vector<int> can2 = {3,2,1,0,4};

    cout << canJump(can)<<endl;

}

/*


static void V1(benchmark::State& state) {

    string s = "ABCABC";
    string b = "ABC";
    while(state.KeepRunning())
    {
        gcdOfStrings2(s,b);

    }


}
BENCHMARK(V1);

static void V2(benchmark::State& state) {

    string s = "ABCABC";
    string b = "ABC";
    while(state.KeepRunning())
    {
        gcdOfStrings(s,b);

    }

}
BENCHMARK(V2);

BENCHMARK_MAIN();
*/



