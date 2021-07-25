#include <iostream>
#include <fstream>

using namespace std;

int a=1000, ans, b, i=1;

void in()
{
    ifstream cin ("mistake.in");
    while(cin >>b)
    {
        if (b==(a+3) || (b==(a-3) ) ) {a=b; i++;}
        else {ans=i;}
    }
}

void solution()
{

}

void out()
{
    ofstream cout ("mistake.out");
    cout <<ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
}
