#include <iostream>
#include <fstream>

using namespace std;

int n=1, ch, i, sum=0;
int a[105]; 

int main()
{
    ifstream cin ("game.in");
    ofstream cout ("game.out");
    while (cin >>ch)
    {
          a[n]=ch; sum=sum+a[n]; if (sum>100){break;} n=n+1; //cout <<sum <<"\n";
    }
   /* for (i=1; i<n; i++)
    {
        cout <<a[i] <<"\n";
    }*/
    if (n%2==0) {cout <<"ENDER\n";}
    else        {cout <<"VALENTINE\n";}

return 0;
}
