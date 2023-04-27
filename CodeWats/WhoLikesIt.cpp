#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://www.codewars.com/kata/5266876b8f4bf2da9b000362/train/cpp

string c1 = "no one likes this";
string c2 = " likes this";
string c21 = " like this";
string c3 = " and ";
string c4 = ", ";
string c5 = " others like this";


std::string likes(const std::vector<std::string> &names)
{
    int n = names.size();

    switch (n) {
        case 3:
            return names[0] + c4 + names[1] + c3 + names[2] + c21;
        case 2:
            return names[0] + c3 + names[1] + c21;
        case 1:
            return names[0] + c2;
        case 0:
            return c1;
        default:
            ;
    }

    std::string str = std::to_string(n-2);
    return names[0] + c4 + names[1] + c3 + str + c5;


}


int main()
{
    vector<string> names = {"Alex"};

    cout << likes(names) << endl;
}

/*


static void V1(benchmark::State& state) {

    string s = "ABCABC";
    string b = "ABC";
    while(state.KeepRunning())
    {
        gcdOfStrings2(s,b);

    }


}
BENCHMARK(V1);

static void V2(benchmark::State& state) {

    string s = "ABCABC";
    string b = "ABC";
    while(state.KeepRunning())
    {
        gcdOfStrings(s,b);

    }

}
BENCHMARK(V2);

BENCHMARK_MAIN();
*/



