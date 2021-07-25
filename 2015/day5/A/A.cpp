#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int BRACKET_COUNT = 3;

vector <char> cm;
char open[5] = {'(', '[', '{'};
int close[5] = {')', ']', '}'};
int fl, ind;

void in()
{
    string str;
    //ifstream cin("check.in");
    cin >> str;;
    for (int i = 0; i < str.size(); i++)
    {
        ind = -1;
        for (int j = 0; j < BRACKET_COUNT; j++)
        {
          if (str[i] == close[j])
          {
            ind = j;
          }
        }
        if (ind == -1)
        {
          cm.push_back(str[i]);
        }
        else
        {
          if (!cm.empty() && cm.back() == open[ind])
          {
            cm.pop_back();
          }
          else
          {
            fl = 1; break;
          }
        }
    }
}

void out()
{
     //ofstream cout("check.out");
     if (fl == 0 && cm.empty())
     {
       cout << "YES\n";
     }
     else
     {
       cout << "NO\n";
     }
}

int main()
{
    in();
    out();
    return 0;
}
