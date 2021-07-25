#include <iostream>
#include <fstream>

using namespace std;

long long num;

long long mass[10]={1, 10, 200, 6000, 240000, 12000000, 720000000, 50400000000, 4032000000000, 362880000000000};
int ans[10];

void in()
{
    ifstream cin ("coins.in");
    cin >>num;
}

void solution()
{
   for (int i=9; i>=0; i--)
    {
        while(num>=mass[i])
        {
           num-=mass[i]; ans[i]++;
        }
    }
}

void out()
{
    ofstream cout ("coins.out");
 for(int i=9; i>=0; i--)
 {
    if (ans[i]!=0) {cout <<ans[i] <<" " <<i <<"\n";}
 }

}

int main()
{
    in();
    solution();
    out();
}
