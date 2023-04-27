#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/next-greater-element-iv/
vector<int> secondGreaterElement_A(vector<int>& nums) {
    int n = nums.size();
    stack<int> s;
    set<pair<int, int>> m;
    vector<int> ans(n,-1);

    for (int i=0; i<n; i++){

        while(!m.empty() && nums[i] > (*m.begin()).first){
            ans[(*m.begin()).second] = nums[i];
            m.erase(m.begin());
        }

        while (!s.empty() && nums[i]>nums[s.top()]){
            m.insert({nums[s.top()],s.top()});
            s.pop();
        }
        s.push(i);


    }
    return ans;

}


int main()
{
    vector<int> n = {2,4,0,9,6};

    for (auto ns : secondGreaterElement_A(n)) {
        cout << ns << " ";
    }

}
