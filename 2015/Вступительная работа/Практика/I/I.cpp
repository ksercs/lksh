#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, two, a, ch;

vector <int> v;

void in()
{
    ifstream cin ("two-digits-two.in");
    cin >>n;
}

void solution()
{
 for(int i=22; i<=n; i++)
 {
     ch=i;
    while(ch!=0)
       {
          a=ch%10;
          if (a==2) {two++;}
          ch/=10;
       }
    if (two==2) {v.push_back(i);}
    two=0;
 }
}

void out()
{
    ofstream cout ("two-digits-two.out");
    if (v.size()==0) {cout <<"\n";}
    else
    {
    for (int i=0; i<v.size(); i++)
    {
        cout <<v[i] <<"\n";
    }
    }
}

int main()
{
    in();
    solution();
    out();
}
