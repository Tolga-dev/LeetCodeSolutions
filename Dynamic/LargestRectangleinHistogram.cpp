#include <bits/stdc++.h>
using namespace std;
//https://iq.opengenus.org/maximal-rectangle-problem/
//https://leetcode.com/problems/largest-rectangle-in-histogram/

int find_area(vector<int>& heights) {
    int hgt [100001];
    int pos [100001];

    heights.push_back(0);
    int ans=heights[0], n=heights.size(), m=0;
    hgt[0]=heights[0];
    pos[0]=0;
    for(int i=1; i<n; ++i) {
        pos[m+1]=i;
        for(; m>=0 && heights [i]<hgt[m]; --m) {
            ans=max(ans,hgt[m]*(i-pos[m]));
        }
        hgt[++m]=heights[i];
    }
    return ans;
}


int MaxAreaInHistogram(vector<int>&heights)
{
    int N=heights.size();
    stack<int>st;
    int maxArea=0;
    int h;
    int w;
    for(int i=0;i<=N;i++)
    {
        while(!st.empty() and (i==N or heights[st.top()]>heights[i]))
        {

            h=heights[st.top()];
            st.pop();

            if(st.empty()) w=i;
            else w=i-st.top()-1;
            maxArea=max(maxArea,(h*w));
        }
        st.push(i);
    }

    return maxArea;
}



int main()
{

    vector<int> obstacleGrid = {2,1,5,6,2,3};

    cout << MaxAreaInHistogram(obstacleGrid) << endl;
}