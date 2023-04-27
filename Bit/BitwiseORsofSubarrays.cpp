#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/bitwise-ors-of-subarrays/

// time limit exceed
int subarrayBitwiseORs0(vector<int>& arr) {
    unordered_set<int> distinctORs;
    int n = arr.size();

    // Iterate through all possible subarrays
    for (int i = 0; i < n; ++i) {
        int bitwiseOR = 0;
        for (int j = i; j < n; ++j) {
            bitwiseOR |= arr[j];  // Perform bitwise OR on each element in the subarray
            distinctORs.insert(bitwiseOR);  // Add the bitwise OR result to the set
        }
    }

    return distinctORs.size();
}

int subarrayBitwiseOR2s(vector<int>& arr) {
    unordered_set<int> distinctORs;
    unordered_set<int> prevDistinctORs;  // Set to store distinct bitwise ORs for subarrays ending at i-1
    unordered_set<int> curDistinctORs;   // Set to store distinct bitwise ORs for subarrays ending at i

    for (int i = 0; i < arr.size(); ++i) {
        curDistinctORs.clear();  // Clear the set for current subarrays ending at i
        curDistinctORs.insert(arr[i]);  // Add the element at index i as a distinct bitwise OR

        for (int prevOR : prevDistinctORs) {
            // Perform bitwise OR on previous distinct bitwise ORs with the element at index i
            curDistinctORs.insert(prevOR | arr[i]);
        }

        prevDistinctORs = curDistinctORs;  // Update previous distinct bitwise ORs with current distinct ORs
        distinctORs.insert(curDistinctORs.begin(), curDistinctORs.end());  // Add current distinct ORs to final set
    }

    return distinctORs.size();  // Return the count of distinct bitwise ORs

}

int subarrayBitwiseORs(vector<int>& arr) {
    vector<int> or_results;
    int i = 0, j = 0;
    int start,a2;
    for (auto a: arr) {
        start = or_results.size();
        or_results.emplace_back(a);
        for (int k = i; k < j; k++) {
            a2 = or_results[k] | a;
            if (a2 > or_results.back()) {
                or_results.emplace_back(a2);
            }
        }
        i = start, j = or_results.size();
    }
    return unordered_set<int>(or_results.begin(), or_results.end()).size();

}


int main()
{

    std::vector<int> s = {0};
    std::vector<int> s1 = {1,2,4};
    std::vector<int> s2 = {1,1,2};

    cout << subarrayBitwiseORs(s1) << endl;

}


