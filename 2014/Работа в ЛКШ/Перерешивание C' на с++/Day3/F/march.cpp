#include <iostream>
#include <fstream>
#include <set>
//#include <string>
//#include <cstring>

using namespace std;

int n, temp, i;
multiset <int> ms;
multiset <int>::iterator it;

void in()
{
ifstream cin ("march.in");
    cin >>n;
    for(i=0; i<n; i++)
    {
        cin >>temp;     
        ms.insert(temp);   
    }
}

void solution()
{

}

void out()
{
     ofstream cout ("march.out");
    for(it=ms.begin(); it!=ms.end(); it++)
    {
        cout <<*it <<" ";        
    }
       cout <<"\n";
}

int main()
{
    in();
   // solution();
    out();
return 0;
}
