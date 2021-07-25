#include <iostream>
#include <fstream>

using namespace std;

int n, mc, mi;
int mass[100000+5], cash[100000+5];

void in()
{
    ifstream cin ("cash.in");
    cin >>n;
    for (int i=1; i<=n; i++)
    {
        cin >>mass[i];
        cash[i]=mass[i]-mass[i-1];
    }
}

void solution()
{
    mc=cash[1]; mi=1;
    for (int i=2; i<=n; i++)
    {
        if (cash[i]>mc) {mc=cash[i]; mi=i;}
    }
}

void out()
{
    ofstream cout ("cash.out");
 cout <<mi <<" " <<mc <<"\n";
}

int main()
{
    in();
    solution();
    out();
}
