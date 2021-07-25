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

using namespace std;

const int MAX_COUNT_POINT = 1000;

int n, length, dp;

pair <int, int> p[MAX_COUNT_POINT + 5];
vector <pair <pair <int, int>, pair <int, int> > > ans;

int where_point_lies(int i1, int i2, int i3)
{
            pair <int, int> v1, v2;
            v1.first = p[i2].first - p[i1].first;
            v1.second = p[i2].second - p[i1].second;
            v2.first = p[i3].first - p[i2].first;
            v2.second = p[i3].second - p[i2].second;
            dp = v1.first * v2.second - v1.second * v2.first;
            cout << dp << "\n";
            if (dp > 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
}


void in()
{
    ifstream cin("wall.in");
    cin >> n >> length;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
}

void solution()
{
    int s_now, s_was;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            s_was = where_point_lies(i, (i + 1) % n, (i  + 2) % n);
          //  cout <<s_was << " " << s_now << "\n";
        }
        s_now = where_point_lies(i, (i + 1) % n, (i  + 2) % n);
        if (s_now == s_was)
        {
            //cout << s_now << " " <<s_was <<"\n";
            ans.push_back(make_pair(p[i], p[i + 1]));
            ans.push_back(make_pair(p[i + 1], p[i + 2]));
        }
        else
        {
           // cout << "MGHSRGJ\n";
            ans.pop_back();
            ans.push_back(make_pair(p[i], p[i + 2]));
        }
        s_was = s_now;
    }
}

void out()
{
     ofstream cout("wall.out");
     for (int i = 0; i < ans.size(); i++)
     {
         cout << "< <" <<ans[i].first.first <<", " <<ans[i].first.second << ">, <" << ans[i].second.first <<", " << ans[i].second.second <<"> > \n";
     }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
