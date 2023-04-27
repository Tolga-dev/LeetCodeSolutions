#include <bits/stdc++.h>
using namespace std;

void print(std::stack<int> temp)
{
    while(!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

}

vector<int> nextGreaterElements(vector<int>& nums) {
    if(nums.size()==1){
        vector<int>ans(1);
        ans[0]=-1;
        return ans;
    }

    int n= nums.size();
    vector<int> ans(n,-1);
    stack<int> st;

    for(int i=0;i<2*n;i++)
    {
        while(!st.empty() && nums[i%n]>nums[st.top()%n])
        {
            ans[st.top()%n]=nums[i%n];
            st.pop();
        }

        st.push(i%n);
    }

    return ans;
}



int main()
{

    vector<int> nums1 = {3,6,1,5};

    for (auto i : nextGreaterElements(nums1)) {
        cout << i << " ";
    }

    return 0;

}