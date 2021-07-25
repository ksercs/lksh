#include <iostream>
#include <fstream>

using namespace std;

int n, lon=0;;

int main()
{
    ifstream cin ("collatz.in");
    ofstream cout ("collatz.out");
    cin>>n;
  
    while (n!=1)
    {
       if (n%2==0) {n=n/2; lon=lon+1;}
       else        {n=n*3+1; lon=lon+1;}      
    }
    lon=lon+1;          
    cout <<lon <<"\n";
return 0;
}
