#include <iostream>
#include <fstream>
//#include <string>
//#include <cstring>

using namespace std;


int n, i, j, k, h, p, maxCH;
int mass[200000+2], help[200000+2];


void in()
{
    ifstream cin ("countsort.in");
    cin >>n;
    for(i=1; i<=n; i++)
    {
        cin >>  mass[i];   
    }
}

void solution()
{
   for (p=1; p<=n; p++)
    {
        if (maxCH<mass[p]) {maxCH=mass[p];}
    }
    for(k=1; k<=n; k++)
       {
          help[mass[k]] += 1;  
       } 
}

void out()
{
     ofstream cout ("countsort.out");
     //cout <<maxCH <<"\n";
     for(h=1; h<=maxCH; h++)
       {
              //cout <<ch[h] << " " << help[h] <<"\n";
          for (j=1; j<=help[h]; j++)
          {
              cout <<h <<" ";
          }  
       }  
       cout <<"\n";
    /*for(k=1; k<=maxCH; k++)
       {
          cout << help[mass[k]] <<" ";  
       }
       cout <<"\n";*/
}

int main()
{
    in();
    solution();
    out();
return 0;
}
