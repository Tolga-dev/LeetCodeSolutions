#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
#define ll long long


ll bs(vector<int> arr, ll spell, ll success, ll l,ll r, ll n)
{
    ll mid;
    while(l < r){
        mid = l + (r-l)/2;

        if(arr[mid] >= n)
            r = mid;
        else
            l = mid + 1;
    }
    return l;

}
// TIME LIMIT EXCEED - OPTIMIZED BRUTE FORCE
vector<int> successfulPairs0(vector<int>& spells, vector<int>& potions, long long success) {
    int size = potions.size();
    int c = size;
    std::sort(potions.begin(),potions.end());

    for (int i = 0; i < spells.size(); ++i) {
        for (int j = 0; j < size; ++j) {
                if((long long)spells[i] * (long long)potions[j] >= success)
                {
                    c = j;
                    break;
                }
        }
        spells[i] = size - c;
        c = size;
    }

    return spells;
}

// TIME LIMIT EXCEED - OPTIMIZED BINARY SEARCH
vector<int> successfulPairs2(vector<int>& spells, vector<int>& potions, long long success) {
    int size = potions.size();
    std::sort(potions.begin(), potions.end());

    for (int i = 0; i < spells.size(); ++i) {
        spells[i] = size - bs(potions,spells[i],success,0,size,(long long)(success + spells[i] - 1) / spells[i]);
    }
    return spells;
}

// TIME LIMIT EXCEED - OPTIMIZED BINARY SEARCH
vector<int> successfulPairs3(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    vector<int> res;
    int size = potions.size();

    for (int i = 0; i < spells.size(); ++i) {
        res.push_back(size - bs(potions,spells[i],success,0,size,(long long)(success + spells[i] - 1) / spells[i]));

    }

    return res;
}

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(),potions.end());
    int size = potions.size();
    int d=0;
    long long g = 0;
    int f = 0;
    for(int i=0; i<spells.size(); i++){
        d = 0;
        g = success/spells[i];
        if(success%spells[i])
            g++;
        f=lower_bound(potions.begin(),potions.end(),g)-potions.begin();
        d += size-f;
        spells[i] = d;
    }

    return spells;

}

// OPTIMIZED BINARY SEARCH
int obs(vector<int>& potions, long long base, long long success,int start,int end,int mid, int p_size) {
    if(base * potions[0]>=success) return p_size;
    if(base * potions.back()<success) return 0;

    while(start<end-1) {
        mid = start + (end-start)/2;
        if(base * potions[mid]>=success) end = mid;
        else start = mid;
    }
    return potions.size()-end;
}
vector<int> successfulPairs4(vector<int>& spells, vector<int>& potions, long long success) {
    ios_base::sync_with_stdio(0);
    int p_size = potions.size();
    int start = 0, end = potions.size()-1, mid;
    sort(potions.begin(), potions.end());
    for(int i=0;i<spells.size();i++) {
        spells[i] = obs(potions, spells[i], success,start,end,mid,p_size);
    }
    return spells;
}


int main()
{
    vector<int> spells = {3,1,2}, potions = {8,5,8};
    long long success = 16;

    for (auto s : successfulPairs4(spells,potions, success)) {
        cout << s << " ";
    }

}