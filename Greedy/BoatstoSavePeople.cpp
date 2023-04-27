#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/boats-to-save-people/

// two pointer
int numRescueBoats0(vector<int>& people, int limit) {
    std::sort(people.begin(),people.end());
    int size = people.size()-1;
    int l= 0;
    int ans = 0;

    if(people[0] > limit/2 + 1)
        return size+1;

    while(l <= size)
    {
        if(people[l] + people[size] <= limit)
        {
            l +=1;
            size -= 1;
        }
        else
        {
            size -= 1;
        }
        ans++;
    }
    return ans;
}

int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int i = 0, size = people.size() - 1;
    int ans = 0;

    if(people[0] > limit/2 + 1)
        return size+1;

    while (i <= size) {
        ans++;
        if (people[i] + people[size] <= limit)
            i++;
        size--;
    }

    return ans;
}


int main()
{
//    vector<int> people = {2,4};
//    vector<int> people = {1,2};
    vector<int> people = {3,5,3,4};
    int limit = 5;

    cout << numRescueBoats(people,limit) << endl;
}