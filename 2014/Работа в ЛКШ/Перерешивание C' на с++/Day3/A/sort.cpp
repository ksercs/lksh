#include <iostream>
#include <fstream>
//#include <string>
//#include <cstring>

using namespace std;

const int MAXch=1000;

int n, i, j, k, maxCH, help;
int ch[MAXch+2];

int fsort(int mass[MAXch+2])
{
  for (i=0; i<n; i++)
    {
      for (j=0; j<n-i; j++)
      {
          if (mass[j] > mass[j + 1]) {help = mass[j]; mass[j] = mass[j + 1]; mass[j + 1]=help;}      
      }        
    } 
  return mass[MAXch+2];
}     

void in()
{
    ifstream cin ("sort.in");
    cin >>n;
    for(i=0; i<n; i++)
    {
        cin >>  ch[i];   
    }
}

void solution()
{
   fsort(ch);
}

void out()
{
     ofstream cout ("sort.out");
          for (k=1; k<=n; k++)
          {
              cout <<ch[k] <<" ";
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
