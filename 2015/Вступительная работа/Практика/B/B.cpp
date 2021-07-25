#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int a1, b1, c1, a2, b2, c2, ans;

int man[5], lod[5];

void in()
{
    ifstream cin ("river.in");
    for (int i=0; i<3; i++)
    {
        cin >> man[i];
    }

    for(int i=0; i<3; i++)
    {
        cin >>lod[i];
    }
}

void solution()
{
    sort(man, man+3);
    sort(lod, lod+3);
    for(int i=0; i<3; i++)
    {
        if (man[i]<=lod[i]) {ans++;}
    }
}

void out()
{
    ofstream cout ("river.out");
    if (ans==3) {cout <<"YES\n";}
    else        {cout <<"NO\n";}
}

int main()
{
    in();
    solution();
    out();
}
