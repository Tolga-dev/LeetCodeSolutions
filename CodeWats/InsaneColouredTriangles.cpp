#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://www.codewars.com/kata/5a331ea7ee1aae8f24000175/train/cpp

char find_missing(char f, char s)
{
    if(f == s) return f;

    if(f == 'R')
    {
        if(s == 'G')
            return 'B';
        else
            return 'G';
    }
    else if(f == 'B')
    {
        if(s == 'R')
            return 'G';
        else
            return 'R';
    }
    else
    {
        if(s == 'R')
            return 'B';
        else
            return 'R';
    }

}

// time out
char triangle0(const string &row)
{
    string s = row;
    int size = s.length();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i-1;++j) {
            s[j] = find_missing(s[j],s[j+1]);
        }
    }

    return s[0];
}

char triangle(string r){
    map<string, char> mp = {{"RR", 'R'}, {"BB", 'B'}, {"GG", 'G'}, {"BG", 'R'}, {"BR", 'G'}, {"GB", 'R'}, {"GR", 'B'}, {"RB", 'G'}, {"RG", 'B'}};
    string n;
    int c;
    string x;
    while(r.size() > 1){
        n = "";
        c = 1;
        while(r.size() % (3 * c) == 1) c *= 3;
        for (int i = 0; i < r.size() - 1; i += c){
            x = "";
            x += r[i];
            x += r[i + c];
            n += mp[x];
        }
        r = n;
    }
    return r[0];
}

int main()
{
    cout << triangle("B") << endl;
    cout << triangle("GB") << endl;
    cout << triangle("RRR") << endl;
    cout << triangle("RGBG") << endl;
    cout << triangle("RBRGBRB") << endl;
    cout << triangle("RBRGBRBGGRRRBGBBBGG") << endl;
}


