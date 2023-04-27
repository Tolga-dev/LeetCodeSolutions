#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/next-greater-element-i/submissions/915583134/
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> out;

    int var = -1;

    for (int & i : nums1) {

        auto it = find(nums2.begin(),nums2.end(),i);
        auto ind = it - nums2.begin();

        for (int j = ind+1; j < nums2.size(); ++j) {

            if(nums2[j] > nums2[ind])
            {
                var = nums2[j];
                break;
            }
        }
        out.emplace_back(var);

        var = -1;


    }

    return out;
}

vector<int> nextGreaterElement2(vector<int>& nums1,vector<int>& nums2) {
    unordered_map <int, int> vals;
    stack <int> s;
    for(int i = 0; i < nums1.size(); i++)
        vals[nums1[i]] = i;

    for(int j = 0; j < nums2.size(); j++)
    {
        while(!s.empty() && nums2[j] > s.top())
        {
            if(vals.count(s.top()))
                nums1[vals[s.top()]] = nums2[j];
            s.pop();
        }

        s.push(nums2[j]);

    }


    while(!s.empty())
    {
        if(vals.count(s.top()))
            nums1[vals[s.top()]] = -1;

        s.pop();
    }


    return nums1;

}

vector<int> nextGreaterElement3(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mpx(nums2.size());
    stack<int> st;

    for(int i = nums2.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= nums2[i])
            st.pop();
        if(!st.empty())
            mpx[nums2[i]] = st.top();

        else mpx[nums2[i]] = -1;
        st.push(nums2[i]);
    }
    vector<int> ans;
    for(int & i : nums1)
        ans.push_back(mpx[i]);

    return ans;

}

vector<int> nextGreaterElement5(vector<int>& nums1, vector<int>& nums2) {
    map<int,int> map1;
    int size = static_cast<int>(nums1.size());

    stack<int> stack1;

    for (int i = nums2.size()-1; i >= 0; --i) {
        while(!stack1.empty() && stack1.top() <= nums2[i])
            stack1.pop();

        map1[nums2[i]] = (stack1.empty()) ? -1 : stack1.top();

        stack1.push(nums2[i]);
    }

    for (int i = 0; i < size; ++i) {
        nums1[i] = map1[nums1[i]];
    }


    return nums1;
}

int main()
{

    vector<int> nums1 = {3,1,5,7,9,2,6},
            nums2 = {1,2,3,5,6,7,9,11};

//    nextGreaterElement5(nums1,nums2);
//    5 2 6 9 11 3 7

    for (auto i : nextGreaterElement5(nums1,nums2)) {
        cout << i << " ";
    }

    return 0;

}