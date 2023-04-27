#include <bits/stdc++.h>
using namespace std;
//https://www.codewars.com/kata/595a1cd5ae807b48d7000034/train/cpp
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

// TLE
#define ll long long
template <std::size_t N>
ll so5lve(std::array<int, N>& a) {
    ll n = a.size();
    ll ans = 0;
    bool flag;

    unordered_map<ll,ll>count;

    for (ll i = 0; i < n; i++) {
        for (ll j = i; j < n; j++) {

            for (ll k = i; k <= j; k++)
                count[a[k]]++;

            flag= true;

            for (auto k: count) {
                if(k.second % 2 == 0)
                {
                    flag = false;
                    break;
                }

            }

            for (auto k: count) {
                cout << k.first << " " << k.second << endl;

            }
            cout << endl;

            count.clear();

            if(flag)
                ans++;

        }
    }

    return ans;
}

#define ll long long
template <std::size_t N>
ll solv0e(std::array<int, N>& a) {
    std::size_t ans = 0;
    std::unordered_map<int, int> freq{};

    for (std::size_t i = 0; i < a.size(); i++) {
        freq.clear();

        for (std::size_t j = i; j < a.size(); j++) {
            freq[a[j]]++;

            bool is_naive = true;
            for (auto [k, v] : freq) {
                if (v % 2 == 0) {
                    is_naive = false;
                    break;
                }
            }

            if (is_naive) ans++;
        }
    }

    return ans;
}

template <std::size_t N>
int findMax(int (&a)[N]) {
    int maxElement = a[0];
    for (int i = 1; i < N; i++) {
        if (a[i] > maxElement) {
            maxElement = a[i];
        }
    }
    return maxElement;
}

#define ll long long
template <std::size_t N>
ll solve(std::array<int, N>& a) {
    int n = a.size();
    long long ans = 0;
    ll m = findMax(a);
    int freq[m+1];

    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ++freq[a[j]];
            int evenFreqCount = 0;

            for (int k = 0; k <= m; ++k) {
                if (freq[k] != 0 && freq[k] % 2 == 0) {
                    ++evenFreqCount;
                }
            }

            if (evenFreqCount == 0)
            {
                ++ans;
            }
        }
        memset(freq, 0, sizeof(freq));
    }
    return ans;
}


int main()
{
    std::array<int, 4> arr = {2,2,2, 3};
    std::array<int, 15> arr3 = {2, 5, 2, 3, 6, 7, 8, 23, 23, 13, 65, 31, 3, 4, 3};
//    naiveSubarrays(arr);
    std::array<int,27> arr2 = {6,1,7,4,6,7,1,4,7,1,4,6,6,7,4,1,6,4,7,1,4,5,3,2,1,6,9};
    cout << solve(arr3) << endl;
    cout << solve(arr) << endl;
    cout << solve(arr2) << endl;


    return 0;
}