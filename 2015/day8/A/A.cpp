#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, m;

void in()
{
    ifstream cin("king1.in");
    cin >> m >> n;
}

void out()
{
     ofstream cout("king1.out");
     if (m % 2 == 1 && n % 2 == 1)
     {
         cout << "2\n";
     }
     else
     {
         cout << "1\n";
     }
}

int main()
{
    in();
    out();
    return 0;
}
