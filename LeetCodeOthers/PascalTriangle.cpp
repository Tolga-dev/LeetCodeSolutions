#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/pascals-triangle/submissions/913199289/
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> output;

    if(!numRows) return output;

    for (int i = 0; i < numRows; ++i)
        output.emplace_back(i+1,1);

    for (int i = 2; i < numRows; ++i)
        for (int j = 1; j < output[i].size() - 1; ++j)
            output[i][j] = output[i - 1][j - 1] + output[i - 1][j];

    return output;
}

//https://leetcode.com/problems/pascals-triangle-ii/
vector<int> generate2(int numRows) {

    vector<int> output;
    output.emplace_back(1);
    if(!numRows) return output;
    long temp = 1;
    for(int i=1,up=numRows,down=1;i<=numRows;i++,up--, down++)
    {
        temp=temp*up/down;
        output.emplace_back(temp);
    }
    return output;
}



int main()
{
/*    for (auto i : generate2(3)) {
            cout << i << " ";
    }*/

    //    cout << binCoff_for(5,2)<< endl;

}
