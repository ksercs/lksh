#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int st1, st2, fn1, fn2;

void in()
{
    ifstream cin("transfers.in");
    cin >> st1 >> fn1 >> st2 >> fn2;
}

void solution()
{
    if (st1 > fn1)
    {
        swap(st1, fn1);
    }
    if (st2 > fn2)
    {
        swap(st2, fn2);
    }
    if (st1 > st2)
    {
        swap(st1, st2);
        swap(fn1, fn2);
    }
}

void out()
{
     ofstream cout("transfers.out");
     //cout <<st1 <<" " <<fn1 <<" " <<st2 <<" " <<fn2 <<"\n";
    if (fn1 < st2)
    {
        cout << "0\n";
    }
    if (st2 < fn1)
    {
        if (fn2 >= fn1)
        {
            cout << fn1 - st2 + 1 << "\n";
        }
        else
        {
            cout << fn2 - st2 + 1 << "\n";
        }
    }
    if (st2 == fn1)
    {
        cout << "1\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
