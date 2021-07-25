#include <iostream>
#include <fstream>

using namespace std;

int n, i, g;
int a[1002]; 

int main()
{
    ifstream cin ("count.in");
    ofstream cout ("count.out");
  cin >>n;
    for (i=1; i<=n; i++)
  {  
    a[i]=i;    
  }
  for (g=1; g<=n; g++)
  {  
     if ( (a[g]%3==0) && (a[g]%7==0) ) {cout <<a[g] <<" ";}
     else if ( (a[g]%3!=0) && (a[g]%7!=0) ) {cout <<a[g] <<" ";}    
     else if ( a[g]%3==0 ) {cout <<a[g] <<" " <<a[g] <<" ";} 
  }
  cout <<"\n";
return 0;
}
