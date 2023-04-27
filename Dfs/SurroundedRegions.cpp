#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/surrounded-regions/

int ra[] = {-1, 0, 1, 0};
int ca[] = {0, 1, 0, -1};
int r  = 0;
int c  = 0;
void dfs(vector<vector<char>>& board,vector<vector<int>>& v, int i, int j, int m, int n)
{
    v[i][j] = 1;

    for (int k = 0; k < 4; ++k) {
        r = i + ra[k];
        c = j + ca[k];
        if(r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'O' && v[r][c] == 0)
            dfs(board,v,r,c,m,n);
    }

}

void solve(vector<vector<char>>& board) {

    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> v (m,vector<int>(n,0));

    if(v[0][0] == 0 && board[0][0]=='O') v[0][0] = 1;

    for (int i = 1; i < n; ++i) {
        if(board[0][i] == 'O' && v[0][i] == 0)
            dfs(board,v,0,i,m,n);
        if(board[m-1][i] == 'O' && v[m-1][i] == 0)
            dfs(board,v,m-1,i,m,n);
    }


    for (int i = 1; i < m; ++i) {
        if(board[i][0] == 'O' && v[i][0] == 0)
            dfs(board,v,i,0,m,n);
        if(board[i][n-1] == 'O' && v[i][n-1] == 0)
            dfs(board,v,i,n-1,m,n);
    }


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(board[i][j]=='O' && v[i][j] == 0)
                board[i][j] = 'X';
        }
    }


}


int main()
{
//    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
//    vector<vector<char>> board = {{'O','O'},{'O','O'}};
    vector<vector<char>> board = {{'O'}};
    solve(board);

    for (auto i : board) {
        for (auto j : i) {
            cout << j<< " ";
        }
        cout << endl;
    }


}


/*

void f() {
    int m = 200;
    int n = 200;
    int v[m][n];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            v[i][m] = 0;
        }
    }
}

void bar() {
    int m = 200;
    int n = 200;
    vector<vector<int>> v (m,vector<int>(n,0));

}


static void F(benchmark::State& state) {
    for (auto _ : state) {
        f();
    }
}
// Register the function as a benchmark
BENCHMARK(F);

static void BAR(benchmark::State& state) {
    for (auto _ : state) {
        bar();
    }

}
BENCHMARK(BAR);

BENCHMARK_MAIN();

*/
