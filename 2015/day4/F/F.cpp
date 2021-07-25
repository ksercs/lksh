#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int m, n;

pair <pair <int, int>, int> ln;
multiset <pair <pair <int, int>, int> > mst_ln;
multiset <pair <pair <int, int>, int> >:: iterator it;

void in()
{
    ifstream cin("os.in");
    cin >> m;
    cin >> n;
    cin >> ln.first.first >> ln.first.second;
    ln.second = 1;
    mst_ln.insert(ln);
    for (int i = 2; i <= n; i++)
    {
        cin >> ln.first.first >> ln.first.second;
        ln.second = i;
        for (it = mst_ln.begin(); it != mst_ln.end(); it++)
        {
            if (((*it).first.second >= ln[i].first.first && (*it).first.second <= ln[i].first.second) || ((*it).first.first >= ln[i].first.first && (*it).first.first <= ln[i].first.second) )
            {
               // ans--;
                mst_ln.erase(*it);
                mst_ln.insert(ln[i]);
            }
        }
    }
}

void out()
{
     ofstream cout("os.out");
     cout << mst_ln.size() <<"\n";
}

int main()
{
    in();
    out();
    return 0;
}
