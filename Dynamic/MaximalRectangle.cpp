#include <bits/stdc++.h>
using namespace std;
//https://iq.opengenus.org/maximal-rectangle-problem/
//https://leetcode.com/problems/maximal-rectangle/description/



// coulnt  solved!
int maximalRectangle0(vector<vector<char>>& matrix) {
    priority_queue<int> b;
    int r = matrix.size();
    int c = matrix[0].size();


    vector<vector<int>> ints(r, vector<int>(c,0));

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            ints[i][j] = matrix[i][j] - 48;
        }
    }

    for (int i = 0; i < r-1; ++i) {
        for (int j = 0; j < c; ++j) {
            if(ints[i+1][j] != 0)
                ints[i+1][j] += ints[i][j];
        }
    }

/*    1 0 1 0 0
    2 0 2 1 1
    3 1 3 2 2
    4 0 0 3 0*/

    int bg;
    int ind = 0;
    int cn;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {


        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {

            cout << ints[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}

int maximalRectangle01(vector<vector<char>>& matrix)
{

    if(matrix.empty()) return 0;
    int y = matrix.size(), x = matrix[0].size(), answer = 0;
    vector<vector<int>> a(y,vector<int>(x)), b(y,vector<int>(x));

    for(int j = 0; j != x; j++)
        for(int i = y - 1, k = 0; i >= 0; i--)
            if(matrix[i][j] == '1') a[i][j] = ++k;
            else a[i][j] = k = 0;

    for(int i = 0; i != y; i++)
        for(int j = x - 1, k = 0; j >= 0; j--)
            if(matrix[i][j] == '1') b[i][j] = ++k;
            else b[i][j] = k = 0;

    for(int i = 0; i != y; i++)
        for(int j = 0; j != x; j++){
            int Y = a[i][j], X = b[i][j];
            for(int w = j + 1, lim = j + X; w < lim; w++)
                if(Y > a[i][w]) {answer = max(answer, Y * (w - j)); Y = a[i][w];}

            answer = max(answer, Y * X);
        }

    return answer;

}

// Histogram f
int getMaxArea(vector<int> hist)
{
    stack<int> s;
    int n = hist.size();
    int max_area = 0;
    int tp;
    int area_with_top;
    int i = 0;
    while (i < n) {

        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);

        else {
            tp = s.top(); // store the top index
            s.pop(); // pop the top

            // Calculate the area with hist[tp] stack
            // as smallest bar
            area_with_top
                    = hist[tp]
                      * (s.empty() ? i : i - s.top() - 1);

            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    while (s.empty() == false) {
        tp = s.top();
        s.pop();
        area_with_top
                = hist[tp] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}
// Histogram f2

int MaxAreaInHistogram(vector<int>&heights)
{
    int N=heights.size();
    stack<int>st;
    int maxArea=0;

    for(int i=0;i<=N;i++)
    {
        while(!st.empty() and (i==N or heights[st.top()]>heights[i]))
        {

            int h=heights[st.top()];
            st.pop();
            int w;
            if(st.empty()) w=i;
            else w=i-st.top()-1;
            maxArea=max(maxArea,(h*w));
        }
        st.push(i);
    }

    return maxArea;
}



int largestRectangleArea(vector<int>& heights) {
    int hgt [100001];
    int pos [100001];

    heights.push_back(0);
    int ans=heights[0], n=heights.size(), m=0;
    hgt[0]=heights[0];
    pos[0]=0;
    for(int i=1; i<n; ++i) {
        pos[m+1]=i;
        for(; m>=0 && heights [i]<hgt[m]; --m) {
            // cout<<hgt[m]<<":["<<pos[m]<<","<<i<<")\n";
            ans=max(ans,hgt[m]*(i-pos[m]));
        }
        hgt[++m]=heights[i];
    }
    return ans;
}


int maximalRectangle(vector<vector<char>>& matrix) {

    int n=matrix.size();
    int m=matrix[0].size();
    vector<int>heights(m,0);
    int maxRec=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]=='1') heights[j]++;
            else heights[j]=0;
        }

        int area=getMaxArea(heights);
        maxRec=max(maxRec,area);
    }

    return maxRec;
}

int main()
{

    vector<vector<char>> obstacleGrid = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};

     maximalRectangle(obstacleGrid);
}