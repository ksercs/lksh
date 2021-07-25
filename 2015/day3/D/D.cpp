#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#include <map>

using namespace std;

const int MAX_SIZE = 100000 + 5;

int m, cur, last, cnt, maxr, ind;
bool fl = true;

pair <int, int> seg[MAX_SIZE];
vector <int> ans;

void in()
{
    ifstream cin("cover.in");
    int a, b;
    cin >> m;
    while (cin >> a >> b)
    {
        if (a != 0 || b != 0)
        {
            seg[cnt] = make_pair(a, b);
            cnt++;
        }
    }
}

void solution()
{
    sort(seg, seg+cnt);
    while (cur < m && fl)
    {
        maxr = cur;
        ind = -1;
        for (int i = last; i < cnt; i++)
        {
            if (seg[i].first > cur) {break;}
            else
            {
                if (seg[i].second > maxr)
                {
                    maxr = seg[i].second;
                    ind = i;
                    last = i + 1;
                }
            }
        }
        if (ind == -1) {fl = false;}
        else
        {
            cur = maxr;
            ans.push_back(ind);
        }
    }
}


void out()
{
    ofstream cout("cover.out");
    if (cur >= m)
    {
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << seg[ans[i]].first << " " << seg[ans[i]].second << "\n";
        }
    }
    else {cout << "No solution\n";}
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
