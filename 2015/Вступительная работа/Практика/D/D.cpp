#include <iostream>
#include <fstream>


using namespace std;

int x, ans, ch, r, a, sum;


void in()
{
    ifstream cin ("funny-numbers.in");
    cin >>x;
}

void solution()
{
    while(ans==0)
    {
       x++;
       ch=x;
       while(ch!=0)
       {
          a=ch%10;
          a*=a;
          sum+=a;
          ch/=10;
       }
    if (sum%7==0) {ans=x;}
    sum=0;
    }

}

void out()
{
    ofstream cout ("funny-numbers.out");
    cout <<ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
}
