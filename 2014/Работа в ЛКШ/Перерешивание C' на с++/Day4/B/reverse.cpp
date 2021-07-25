#include <iostream>
#include <fstream>
//#include <string>
//#include <cstring>

using namespace std;

int n, i;

ifstream in ("reverse.in");
ofstream out ("reverse.out");

int reverse(int x)
{  
    int ch;
    in >>ch;    
    if (x > 1) {reverse(x-1);} 
    if (x==n) {out <<ch <<"\n";}
    else      {out <<ch <<" ";}             
}    

int main()
{
    in >>n;
    reverse(n);
return 0;
}
