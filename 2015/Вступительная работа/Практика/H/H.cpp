#include <iostream>
#include <fstream>

using namespace std;

int n, ans;

void proc(int s)
{
    if (s<4) {return;}
    if (s%5==0) { proc(3*s/5); proc(s/5);}
    else    {ans+=4; proc(s-4);}
}

void in()
{
    ifstream cin ("sheep.in");
    cin >>n;
}

void solution()
{
 proc(n);
}

void out()
{
    ofstream cout ("sheep.out");
    cout <<ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
}
