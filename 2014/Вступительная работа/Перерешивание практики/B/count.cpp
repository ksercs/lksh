#include <iostream>
#include <fstream>

using namespace std;

int const N=1000;

int n, i=0, g, f;
int ans[N+N/3+2]; 

void in()
{
      ifstream cin ("count.in");
      cin >>n;
}

void solution()
{
            for (g=1; g<=n; g++)
            {  
               if ( (g%3==0) && (g%7==0) ) {ans[i]=g; i++;}
               else if ( (g%3!=0) && (g%7!=0) ) {ans[i]=g; i++;}    
               else if ( g%3==0 ) {ans[i]=g; i++; ans[i]=g; i++;} 
            }
}

void out()
{
     ofstream cout ("count.out");
     for (f=0; f<i; f++)
     {
         cout <<ans[f] <<" ";
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
