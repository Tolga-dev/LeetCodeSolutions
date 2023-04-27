#include <bits/stdc++.h>
using namespace std;


// brute force
int partitionString0(string s) {
    int ans = 1;

    string temp{s[0]};
    int l = s.length();

    for (int i = 1; i < l; ++i) {
        for (int j = 0; j < temp.length(); ++j) {
            if(temp[j] == s[i])
            {
                ans++;
                temp.clear();
                break;
            }
        }
        temp += s[i];

    }

    return ans;
}

int partitionString1(std::string const& s)
{
    return std::accumulate(std::cbegin(s), std::cend(s), 1,
                           [observed = std::array<int, 128>{0}](auto count, auto c) mutable
                           {
                               if (observed[c] == count) { ++count; }
                               observed[c] = count;
                               return count;
                           });
}

// hash map
int partitionString2(std::string const& s)

{
    int hash[26] = {0};
    int ans =1,ind=0;
    for (int i = 0; i < s.size(); ++i) {
        ind = s[i] - 'a';
        if(hash[ind] == 1)
        {
            ans++;
            memset(hash,0, sizeof(hash));
        }
        hash[ind] = 1;
    }

    return ans;
}
// expensive operation
int partitionString5(std::string const& s)
{
    int mp=0, ind;
    int ans = 1;
    int val;
    for (int i = 0; i < s.length(); ++i) {
        ind = s[i] - 97;
        val = 1<<ind;
        if (mp & val){
            mp = 0;
            ans++;
        }
        mp |= val;

    }
    return ans;
}

const int ALPHABET_SIZE = 26;
int partitionString7(const string& s) {
    const int n = s.length();
    int mp = 0, ans = 1;
    int val, ind;
    int powersOfTwo[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        powersOfTwo[i] = 1 << i;
    }
    for (int i = 0; i < n; ++i) {
        ind = s[i] - 'a';
        val = powersOfTwo[ind];
        if (mp & val) {
            mp = 0;
            ans++;
        }
        mp |= val;
    }
    return ans;
}

int partitionString9(std::string const& s)
{
    const int n = s.length();
    bitset<26> bs; // a bitset to represent the set of unique characters
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (bs[s[i] - 'a']) { // if the current character is already in the set
            bs.reset(); // reset the set
            ans++; // increment the count of substrings
        }
        bs.set(s[i] - 'a'); // add the current character to the set
    }
    return ans;
}
// hash table
int partitionString(std::string const& s)
{
    const int n = s.length();
    unordered_set<char> uniqueChars; // a hash set to store unique characters
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (uniqueChars.count(s[i])) { // if the current character is already in the set
            uniqueChars.clear(); // clear the set
            ans++; // increment the count of substrings
        }
        uniqueChars.insert(s[i]); // add the current character to the set
    }
    return ans;
}

int main()
{
    string s = "gizfdfri";
    cout << partitionString(s) << endl;
//    cout << partitionString("ssssss") << endl;


}