#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/validate-stack-sequences/

/// withstack
bool validateStackSequences2(vector<int>& pushed, vector<int>& popped, int size = 0) {

    std::stack<int> op;

    for (int i = 0,j = 0; i < pushed.size(); ++i) {
      op.push(pushed[i]);
      size++;
         while (size>0 && popped[j] == op.top()) {
              op.pop();
              size--;
             ++j;
         }
    }

    return size == 0;
}

// two pointer
bool validateStackSequences(vector<int>& pushed, vector<int>& popped, int size = 0,int i = 0,int j = 0) {

    size = pushed.size();
    for (int k = 0; k < size; ++k) {
        if (pushed[k] != popped[j]) {
            pushed[i++] = pushed[k];
        } else {
            ++j;
        }

        while (i > 0 && j < size && pushed[i - 1] == popped[j]) {
            --i;
            ++j;
        }
    }

    return j == popped.size();
}


int main()
{
    vector<int>pushed = {1,2,3,4,5}, popped = {4,5,3,1,2};

    cout << validateStackSequences(pushed,popped) << endl;



}



