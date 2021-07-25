#include <iostream>
#include <fstream>
//#include <string>
//#include <cstring>
//#include <conio.h>

using namespace std;

const int MAXch=100000;

int n, i, j, help;
long long m1, m2;
long long ch[MAXch+2];
 

void in()
{
    ifstream cin ("inspection.in");
    cin >>n;
    for(i=0; i<n; i++)
    {
        cin >>  ch[i];   
    }
}

void solution()
{
   m1 = ch[0];
   m2 = ch[1];
   if (m1>m2) {help=m1; m1=m2; m2=help;}
for (j=2; j<n; j++)
  { 
    if (ch[j] < m2) {
                       m2 = ch[j];
                       if (m2<m1) {help=m1; m1=m2; m2=help;}
                     }
  //cout <<m1 <<" " <<m2; getch();
  }
}

void out()
{
     ofstream cout ("inspection.out");
    cout <<m1 <<" " <<m2 <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
