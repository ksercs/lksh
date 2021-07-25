#include <iostream>
#include <fstream>

using namespace std;

// n<=1000, lon<=16000

int n, lon=0;;

void in()
{
      ifstream cin ("collatz.in");
      cin>>n; 
}

void solution()
{
     while (n!=1)
    {
       if (n%2==0) {n=n/2; lon++;}
       else        {n=n*3+1; lon++;}      
    }
    lon=lon+1;   
}

void out()
{
     ofstream cout ("collatz.out");
     cout <<lon <<"\n";
}

int main()
{
in();
solution();
out();
return 0;
}

