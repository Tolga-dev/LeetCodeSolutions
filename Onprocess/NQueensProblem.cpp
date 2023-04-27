#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://www.codewars.com/kata/5985ea20695be6079e000003/cpp



std::string solveNQueens(int n, std::pair<int, int> mandatoryQueenCoordinates)
{


    return "";
}

int main()
{
    std::string actual = solveNQueens(4, {1, 1});
    std::string expected = "";
    cout << (actual == expected) << endl;

    actual = solveNQueens(4, {2,0});
    expected = "..Q.\nQ...\n...Q\n.Q..\n";
    cout << (actual == expected)  << endl;

    actual = solveNQueens(6, {2,1});
    expected = "....Q.\n..Q...\nQ.....\n.....Q\n...Q..\n.Q....\n";
    cout << (actual == expected)  << endl;

}


