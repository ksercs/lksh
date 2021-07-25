#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int it;

bool comp(string str1, string str2)
{
     return ( (str1+str2) > (str2+str1) );
}

int main()
{
    ifstream cin("number.in");
    ofstream cout("number.out");

    string page;
    string str[100+2];

    while (cin >> page)
    {
        str[it] = page;
        it++;
    }
    sort(str, str+it, comp);

     for (int i = 0; i < it; i++)
     {
         cout << str[i];
     }
     cout << "\n";
return 0;
}
