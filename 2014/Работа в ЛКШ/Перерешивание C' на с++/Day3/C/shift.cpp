#include <iostream>
#include <fstream>
//#include <string>
//#include <cstring>

using namespace std;


int mass[100000+2];

int i, k, f, t, g, minCH, n, u, e, maxCH, ch;

void in()
{
    ifstream cin ("shift.in");
    cin >>ch;
    for (i=0; i<ch; i++)
    {
        cin >>mass[i];
    }
}

void solution()
{
}

void out()
{
     ofstream cout ("shift.out");
     cout <<mass[ch-1] <<" ";
        for (g=0; g<ch-1; g++)
        {
            cout <<mass[g] <<" ";
        }
cout <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
