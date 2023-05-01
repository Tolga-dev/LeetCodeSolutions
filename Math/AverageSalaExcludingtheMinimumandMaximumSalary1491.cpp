//https://leetcode.com/problems/make-array-empty/
#include <bits/stdc++.h>
using namespace std;

static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

double averdage(vector<int>& salary) {

    return (double)((1.0* accumulate(salary.begin(), salary.end(), 0) - *max_element(salary.begin(), salary.end()) - *min_element(salary.begin(), salary.end()))/(salary.size()-2));

}

int size_= 0;
double sum;double avg;
double average(vector<int>& salary) {

    sort(salary.begin(),salary.end());
    sum = 0;
    avg = 0;
    size_ = (int)salary.size();
    for(int i=1;i<size_-1;i++){
        sum+=salary[i];
    }

    avg=sum/(size_-2);
    return avg;
}


int main()
{
    vector<int> salary = {4000,3000,1000,2000};
    cout << average(salary) << endl;
}