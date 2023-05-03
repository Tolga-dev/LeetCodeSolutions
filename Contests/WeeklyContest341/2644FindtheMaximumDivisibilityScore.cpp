#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/find-the-maximum-divisibility-score/description/
#define vi vector<int>
#define uosi vector<int>
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

int maxDiv_Score(vector<int>& nums, vector<int>& div) {
    int count = 0, divisor = 0;
    int num_size = nums.size();

    for (int i = 0; i < div.size(); i++) {
        int count_div = 0;
        for (int j = 0; j < num_size; j++) {
            if (nums[j] % div[i] == 0) count_div++;
        }
        if (count == count_div) {
            divisor = divisor == 0 ? div[i] : min(divisor, div[i]);
        } else if (count_div > count) {
            count = count_div;
            divisor = div[i];
        }
    }
    return divisor;
}

int max_Div_Score(vector<int>& s, vector<int>& d) {
    int res=INT_MAX;
    int min_i=INT_MAX;
    int t=0;
    for(auto& i:d)
    {
        min_i=min(min_i,i);
        int c=0;
        for(auto& j:s)
        {
            if(j%i==0) c++;
        }
        if(t<c)
        {
            res=i;
            t=c;
        }
        else if(t==c)
        {
            res=min(res,i);
        }
    }
    if(t==0) return min_i;
    else return res;
}

int maxDivScore(vector<int>& nums, vector<int>& divisors) {
    std::sort(nums.begin(), nums.end(), std::greater());
    std::sort(divisors.begin(), divisors.end());

    int result = divisors[0];
    int maxCount = 0;

    for (auto div: divisors){
        int count = 0;
        for (auto num: nums){
            if (div > num) break;
            if (num % div == 0)
                count++;
        }

        if (count > maxCount){
            result = div;
            maxCount = count;
        }
    }

    return result;
}


int main()
{
    vi nums = {4,7,9,3,9}, divisors = {5,2,3};

    cout << maxDivScore(nums,divisors) << endl;
}
