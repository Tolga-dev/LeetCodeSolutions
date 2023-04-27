//https://leetcode.com/problems/minimum-additions-to-make-valid-string/
#include <iostream>
using namespace std;
static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

char ops[3] = {'a','b','c'};

int addMisnimum(const string& word) {
    int n = word.size(), i = 0, mk = 0;
    int mc = 0;
    while(i < n) {

        if(word[i] == ops[0]) {
            mc++;i++;
        }
        if(i < n && word[i] == ops[1]) {
             mc++;i++;
        }
        if(i < n && word[i] == ops[2]) {
             mc++;i++;
        }
        mk += 3 - mc;
        mc = 0;
    }

    return mk;
}

int addMinimum(string word) {

    int mc = 0;
    int i = 0;

    while(i<word.size()){
        if(word[i] == ops[0]){
            if(word[i+1] == ops[1] && word[i+2] == ops[2]){
                i+=3;
            }
            else if(word[i+1] == ops[1]){
                mc++;
                i+=2;
            }
            else if(word[i+1] == ops[2]){
                mc++;
                i+=2;
            }
            else if(word[i+1] ==ops[0]){
                mc+=2;
                i++;
            }
            else{
                mc+=2;
                i++;
            }
        }
        else if(word[i] == ops[1]){
            if(word[i+1] == ops[2]){
                mc++;
                i+=2;
            }
            else{
                mc+=2;
                i++;
            }
        }
        else
        {
            mc+=2;
            i++;
        }
    }
    return mc;
}

int main()
{

    cout << addMinimum("ac") << endl;

}