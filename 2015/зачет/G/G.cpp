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

long long n, m, k, temp, s;

int un[10 + 5], used[1000 + 5];

pair <pair <int, int>, int> ans;

vector < vector <int> > road(2 * 200000 + 5);

set <int> st;

void dfs(int v)
{
    used[v] = 1;
    s++;
        if (st.count(v) == 1 && v != temp)
        {
            if (s < ans.second)
            {
                ans.first.first = temp; ans.first.second = v; ans.second = s; break;
            }
        }
        for (int i = 0; i < road[v].size(); i++)
        {
            if (used[road[v][i]] == 0)
            {
                dfs(road[v][i]);
                s--;
                used[road[v][i]] = 0;
            }
        }
}

void in()
{
    ifstream cin("friends.in");
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> un[i];
        st.insert(un[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }
}

void out()
{
     ofstream cout("friends.out");
     int fl = 0;
     for (int i = 1; i <= k; i++)
     {
        for (int j = 1; j <= k; j++)
        {
          if (un[i] == un[j] && i != j)
          {
              fl = un[i]; break;
          }
        }
     }
     if (fl == 0)
     {
             ans.second = 1000000000;
             temp = un[1];
             dfs(un[1]);
     if (ans.second != 1000000000)
     {
        cout << ans.first.first << " " << ans.first.second << " " << ans.second - 1 << "\n";
     }
     else
     {
         cout << "-1\n";
     }
     }
     else{cout << fl << " " << fl << " 0\n";}
}

int main()
{
    in();
    out();
    return 0;
}
