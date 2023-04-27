#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#include <cmath>
//https://www.codewars.com/kata/5518a860a73e708c0a000027/train/cpp


int pow_mod(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % 10;
        }
        base = (base * base) % 10;
        exp /= 2;
    }
    return result;
}

int last_digit(std::list<int> array ) {
    vector<unsigned long long> lst;
    for (auto s: array) {
        lst.push_back(s);
    }
    if (lst.empty()) {
        return 1;
    } else {
        int exp = 1;
        for (int i = lst.size() - 1; i > 0; i--) {
            if (exp == 0) {
                exp = 1;
            } else {
                switch (lst[i] % 4) {
                    case 0:
                        exp = (lst[i] == 0) ? 0 : 4;
                        break;
                    case 1:
                        exp = (lst[i] == 1) ? 1 : 5;
                        break;
                    case 2:
                        exp = (exp == 1) ? 2 : 4;
                        break;
                    case 3:
                        exp = (exp % 2 == 0) ? 5 : 3;
                        break;
                    default:
                        throw runtime_error("error");
                }
            }
        }
        return (int)pow(lst[0] % 10, exp) % 10;
    }
}

int last_digit0(list<int> array) {
    int64_t p = 1;
    auto it = array.rbegin();
    while( it != array.rend()) {
        int a = p >= 4 ? 4 + (p % 4) : p;
        int b = *it >= 20 ? 20 + (*it % 20) : *it;
        p = pow(b,a);
        it++;
    }
    return p % 10;
}

int last_digits(list<int> l) {
    long b=1;
    for(auto i=l.rbegin(); i!=l.rend(); i++)
        b=pow(*i>9?*i%20+20:*i, b<4?b:(b%4+4));
    return b%10;
}


int last_digdit(std::list<int> l) {
    int result = 1;
    for (std::list<int>::iterator i = l.end(); i != l.begin();)
        result = pow(--i == l.begin() ? *i % 10 : *i < 4 ? *i : *i % 4 + 4, result < 4 ? result : result % 4 + 4);
    return result % 10;
}


int main()
{
    std::list<int> arr = {499942,898102,846073};
    last_digit(arr);

    assert(last_digit({})==        (1));
    assert(last_digit({0,0})==     (1));
    assert(last_digit({0,0,0})==   (0));
    assert(last_digit({1,2})==     (1));
    assert(last_digit({3,4,5})==   (1));
    assert(last_digit({4,3,6})==   (4));
    assert(last_digit({7,6,21})==  (1));
    assert(last_digit({12,30,21})==(6));
    assert(last_digit({2,2,2,0})== (4));
    assert(last_digit({937640,767456,981242})== (0));
    assert(last_digit({123232,694022,140249})== (6));
    assert(last_digit({499942,898102,846073})== (6));

}
