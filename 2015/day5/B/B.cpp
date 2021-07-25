#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <utility>
#include <vector>

using namespace std;

vector <char> mc;

void in()
{
    ifstream cin("decode.in");
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (!mc.empty() && str[i] == mc.back())
        {
            mc.pop_back();
        }
        else
        {
            mc.push_back(str[i]);
        }
    }
}

void out()
{
     ofstream cout("decode.out");
     for (int i = 0; i < mc.size(); i++)
     {
         cout << mc[i];
     }
     cout << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
