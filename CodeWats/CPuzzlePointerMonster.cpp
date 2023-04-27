#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
using namespace std;
//https://www.codewars.com/kata/5985ea20695be6079e000003/cpp

#include <cstdio>
char a[4][7] = {"Common", "Point", "Boost", "Better"};
char (*b[4])[7] = {a+3, a+1, a, a+2};



char (*(*C())[4])[7]
{
    return &b;
}

char (**d())[7]
{
    return C()[1] - 3;
}
char buf[256];


char *pointer_monster(char (**f())[7])
{
    int len;

    len  = sprintf(buf, "%s", *f()[0]);

    len += sprintf(buf + len, "%s ", *((**f)()-1)[0]+4);

    len += sprintf(buf + len, "%s", (*f())[0]-4);

    len += sprintf(buf + len, "%s", f()[1][2]+3);

    len += sprintf(buf + len, "%s", *((**f)()-1)[0]+ 4);
    return buf;
}

int main()
{

/*    cout << *b[0] << endl;
    cout << *b[1] << endl;
    cout << *b[1] - 4 << endl;
    cout << **d() << endl;*/

    char *result = pointer_monster(d);
//    cout << result << endl;
    return 0;
}
